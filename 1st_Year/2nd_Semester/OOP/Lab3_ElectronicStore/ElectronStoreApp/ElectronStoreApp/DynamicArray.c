#include "DynamicArray.h"
#include <stdlib.h>
#include "Constants.h"

DynamicArray* createArray(DestructorFunction destroy, CopyFunction copy) {
	/*
		Creates an empty array with an initial constant capacity
		Returns the address of the array allocated in heap
	*/
	DynamicArray* v = (DynamicArray*)malloc(sizeof(DynamicArray));
	v->elems = (ElementType*)malloc(ARRAY_CAPACITY * sizeof(ElementType));
	v->capacity = ARRAY_CAPACITY;
	v->numberOfElements = 0;
	v->destroy = destroy;
	v->copy = copy;
	return v;
}

DynamicArray* copyArray(DynamicArray* v) {
	/*
		Creates a copy of another array
		Returns the address of the other array
	*/
	DynamicArray* newList = createArray(v->destroy, v->copy);
	for (int i = 0; i < v->numberOfElements; i++) {
		appendArray(newList, accessElement(v, i));
	}
	return newList;
}
void resize(DynamicArray* v) {
	/*
		Doubles the memory allocated for an array
		v - address of a DynamicArray that is about to be resized
	*/
	v->capacity *= 2;
	v->elems = (ElementType*)realloc(v->elems, v->capacity * sizeof(ElementType));
}
void appendArray(DynamicArray* v, ElementType elem) {
	/*
		Adds another element to the end of the array
		v - address of a DynamicArray where we will store the value of elem
		elem - address of a Product variable which represents the new element we need to add
	*/
	if (v->numberOfElements == v->capacity) {
		resize(v);
	}
	ElementType aux = v->copy(elem);
	v->elems[v->numberOfElements] = aux;
	v->numberOfElements++;
}
ElementType* searchElement(DynamicArray* v, SearchFunction identify, void* address) {
	/*
		Searches the array for an element with a specific id
		v - address of a DynamicArray where we will search the element
		identify - function pointer which represents the way we search through the array
		address - void pointer to the element we compare with
		Returns the address of the element if it exists in the array and NULL if the element could not be found
	*/
	for (int i = 0; i < v->numberOfElements; i++) {
		if (identify(v->elems[i], address)) {
			return accessElement(v, i);
		}
	}
	return NULL;
}
ElementType* accessElement(DynamicArray* v, int index) {
	/*
		Accesses a specific element stored into a DynamicArray
		v - address of a DynamicArray that we want to access
		index - integer which represents the index of the element we want to access
		Returns the address of the element is the index is adequate or NULL if the index is invalid
	*/
	if (index < 0 || index >= v->numberOfElements) {
		return NULL;
	}
	return &v->elems[index];
}
void deleteElement(DynamicArray* v, int index) {
	/*
		Deletes an element of the DynamicArray
		v - address of a DynamicArray that we want to access
		index - integer which represents the index of the element we want to delete
		No deletion will take place if the index is invalid
	*/
	if (index < 0 || index >= v->numberOfElements) {
		return;
	}
	v->destroy(v->elems[index]);
	for (int i = index; i < v->numberOfElements - 1; i++) {
		v->elems[i] = v->elems[i + 1];
	}
	v->numberOfElements--;
}

void destroyArray(DynamicArray* v) {
	/*
		Deallocates the memory space occupied by the DynamicArray
		v - address of a DynamicArray that we want to destroy
	*/
	if (v != NULL) {
		for (int i = 0; i < v->numberOfElements; i++) {
			v->destroy(v->elems[i]);
		}
		free(v->elems);
		free(v);
	}
}
int arraySize(DynamicArray* v) {
	/*
		Finds the size of the array
		Returns the integer value of the size
	*/
	return v->numberOfElements;
}

void sort(DynamicArray* v, CompareFunction compare) {
	/*
		Function that sorts the array v as specified by a criteria (implements selection sort)
		v - address of a DynamicArray
		compare - function pointer to a function that describes the criteria
	*/
	ElementType aux;
	ElementType* firstElem;
	ElementType* secondElem;
	for (int i = 0; i < v->numberOfElements; i++) {
		firstElem = accessElement(v, i);
		for (int j = i + 1; j < v->numberOfElements; j++) {
			secondElem = accessElement(v, j);
			if (compare(*firstElem, *secondElem) < 0) {
				aux = *firstElem;
				*firstElem = *secondElem;
				*secondElem = aux;
			}
		}
	}
}


void filter(DynamicArray* v, FilterFunction filter, void* address) {
	/*
		Function that filters an array, leaving only the elements that satisfy a condition in the array
		v - address of a DynamicArray that we are about to filter
		filter - pointer to a function that will represent the criteria
		address - void* which will be used in the filter function
	*/
	int i = 0;
	while (i < v->numberOfElements) {
		if (filter(*accessElement(v, i), address) == 0) {
			deleteElement(v, i);
		}
		else {
			i++;
		}
	}
}