#ifndef VECTOR_H
#define VECTOR_H
#include <memory>
#include "Error.h"
#include <functional>
// NOT a complete Vector template class implementation due to the short amount of time available
template <class Type>
class Iterator;

template <class Type>
class Vector {
	friend class Iterator<Type>;
private:
	int capacity;
	int size;
	std::unique_ptr<Type[]> elements;

	/*
	* Method that resizes the array
	*/
	void resize();
public:
	/*
	* Implicit constructor for class Vector
	*/
	Vector();

	/*
	* Copy constructor for class Vector
	*/
	Vector(const Vector& copy);

	/*
	* Default destructor
	*/
	~Vector() = default;

	/*
	* Assignment operator overload
	*/
	Vector& operator=(const Vector& copy);

	/*
	* Function that appends a new element to the vector
	* element - const reference to a variable of type Type which will be added in the Vector using Type's assignment operator
	*/
	void append(const Type& getElement);

	/*
	* Function that erases an element from the vector indicated by an iterator
	* iterator - const reference to a vector iterator
	*/
	void erase(const Iterator<Type>& iterator);

	/*
	* Method that finds the number of elements stored in the Vector
	* Returns an integer which represents the number of elements
	*/
	int length() const noexcept{
		return size;
	}

	/*
	* Method that rearranges the elements in the vector sorting them based on a specific criteria
	* comparator - function pointer which describes the way the elements are compared (returns True if left is in the right order compared to right)
	*/
	void sort(bool (*comparator)(const Type& first, const Type& second));

	/*
	* Method that filters the elements in the vector, deleting every element that doesn't respect a specific condition
	* condition - function which returns true if the element respects the condition and false otherwise
	*/
	void filter(std::function<bool(const Type& element)>condition);
};
template <class Type>
class Iterator {
	friend class Vector<Type>;
private:
	const Vector<Type>& vector;
	int currentIndex;
public:
	Iterator() = delete;

	/*
	* Copy constructor 
	*/
	Iterator(const Vector<Type>& vec) noexcept;

	/*
	* Method which finds the element that the iterator points to
	* Returns a const reference to the element stored in the Vector and pointer to by the iterator
	*/
	const Type& getElement() const ;

	/*
	* Method which modifies the element that the iterator points to
	* elementNou - const reference to another element of type Type which will be set
	*/
	void setElement(const Type& elementNou) const;

	/*
	* Method which moves the iterator to the next element
	*/
	void next();

	/*
	* Method which checks if the iterator is still valid
	*/
	bool valid() const noexcept;

};

class VectorException : public Error {
	using Error::Error;
public:
	static const std::string iteratorInvalid;
	static const std::string wrongIterator;
	static const std::string invalidComparison;
};

template <class Type>
Vector<Type>::Vector() {
	capacity = 2;
	size = 0;
	elements = std::make_unique<Type[]>(capacity);
}

template <class Type>
Vector<Type>::Vector(const Vector& copy) {
	capacity = copy.capacity;
	size = copy.size;
	elements = std::make_unique<Type[]>(capacity);
	for (int i = 0; i < size; i++) {
		elements[i] = copy.elements[i];
	}
}

template <class Type>
Vector<Type>& Vector<Type>::operator=(const Vector& copy) {
	if (this == &copy)
		return *this;
	capacity = copy.capacity;
	size = copy.size;
	elements = std::make_unique<Type[]>(capacity);
	for (int i = 0; i < size; i++)
		elements[i] = copy.elements[i];

}

template <class Type>
void Vector<Type>::resize() {
	capacity = capacity * 2;
	std::unique_ptr<Type[]> newElements{ std::make_unique<Type[]>(capacity) };
	for (int i = 0; i < size; i++) {
		newElements[i] = elements[i];
	}
	elements = std::move(newElements);
}
template <class Type>
void Vector<Type>::append(const Type& newElement) {
	if (size == capacity) 
		resize();
	elements[size] = newElement;
	size++;
}

template <class Type>
void Vector<Type>::erase(const Iterator<Type>& iterator) {
	if (this != &iterator.vector) {
		throw VectorException{ VectorException::wrongIterator };
	}
	if (!iterator.valid()) {
		throw VectorException{ VectorException::iteratorInvalid };
	}
	for (int i = iterator.currentIndex; i < size - 1; i++) {
		elements[i] = elements[i + 1];
	}
	size--;
}

template <class Type>
void Vector<Type>::sort(bool (*comparator)(const Type& first, const Type& second)) {
	if (comparator != nullptr) {
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				if (!comparator(elements[i], elements[j])) {
					Type aux{ elements[i] };
					elements[i] = elements[j];
					elements[j] = aux;
				}
			}
		}
	}
}

template <class Type>
void Vector<Type>::filter(std::function<bool(const Type& element)>condition) {
	int i = 0;
	while (i < size) {
		if (!condition(elements[i])) {
			for (int j = i; j < size - 1; j++) {
				elements[j] = elements[j + 1];
			}
			size--;
		}
		else {
			i++;
		}
	}
}
template <class Type>
Iterator<Type>::Iterator(const Vector<Type>& vec) noexcept : vector(vec) {
	currentIndex = 0;
}

template <class Type>
const Type& Iterator<Type>::getElement() const {
	if (valid()) 
		return vector.elements[currentIndex];
	else 
		throw VectorException{ VectorException::iteratorInvalid };
}

template <class Type>
void Iterator<Type>::setElement(const Type& element) const {
	if (valid()) {
		vector.elements[currentIndex] = element;
	}
	else {
		throw VectorException{ VectorException::iteratorInvalid };
	}
}
template <class Type>
void Iterator<Type>::next() {
	if (valid()) {
		currentIndex++;
	}
	else {
		throw VectorException{ VectorException::iteratorInvalid };
	}
}

template <class Type>
bool Iterator<Type>::valid() const noexcept {
	return currentIndex < vector.size;
}
#endif
