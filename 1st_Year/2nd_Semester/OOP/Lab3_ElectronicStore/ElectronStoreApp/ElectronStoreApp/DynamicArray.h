#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include "ProductEntity.h"

typedef void* ElementType;
typedef int (*CompareFunction)(ElementType, ElementType);
typedef int (*FilterFunction)(ElementType, void*);
typedef int (*SearchFunction)(ElementType, void*);
typedef void (*DestructorFunction)(ElementType);
typedef ElementType(*CopyFunction)(ElementType);
typedef struct {
	ElementType* elems;
	int capacity;
	int numberOfElements;
	DestructorFunction destroy;
	CopyFunction copy;
}DynamicArray;

/*
	Creates an empty array with an initial constant capacity
	Returns the address of the array allocated in heap
*/
DynamicArray* createArray(DestructorFunction, CopyFunction);

/*
	Creates a copy of another array
	Returns the address of the other array
*/
DynamicArray* copyArray(DynamicArray*);

/*
	Doubles the memory allocated for an array
	v - address of a DynamicArray that is about to be resized
	DestructorFunction - function pointer to the destruction function that will destroy the elements referenced by elems
	CopyFunction - function pointer to the copy function that will copy the elements referenced by elems
*/
void resize(DynamicArray*);

/*
	Adds another element to the end of the array
	v - address of a DynamicArray where we will store the value of elem
	elem - address of a Product variable which represents the new element we need to add
*/
void appendArray(DynamicArray*, ElementType);

/*
	Accesses a specific element stored into a DynamicArray
	v - address of a DynamicArray that we want to access
	index - integer which represents the index of the element we want to access
	Returns the address of the element is the index is adequate or NULL if the index is invalid
*/

/*
	Searches the array for an element with a specific id
	v - address of a DynamicArray where we will search the element
	identify - function pointer which represents the way we search through the array
	address - void pointer to the element we compare with
	Returns the address of the element if it exists in the array and NULL if the element could not be found
*/
ElementType* searchElement(DynamicArray*, SearchFunction, void*);

ElementType* accessElement(DynamicArray*, int);

/*
	Deletes an element of the DynamicArray
	v - address of a DynamicArray that we want to access
	index - integer which represents the index of the element we want to delete
	No deletion will take place if the index is invalid
*/
void deleteElement(DynamicArray*, int);

/*
	Deallocates the memory space occupied by the DynamicArray
	v - address of a DynamicArray that we want to destroy
*/
void destroyArray(DynamicArray*);

/*
	Finds the size of the array
	Returns the integer value of the size
*/
int arraySize(DynamicArray*);

void sort(DynamicArray*, CompareFunction);
void filter(DynamicArray*, FilterFunction, void*);
#endif