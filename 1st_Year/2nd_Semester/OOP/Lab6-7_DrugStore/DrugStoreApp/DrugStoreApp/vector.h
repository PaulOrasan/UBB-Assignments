#ifndef VECTOR_H
#define VECTOR_H
#include <memory>
#include "Error.h"

template <class Type>
class Iterator;

template <class Type>
class Vector {
	friend class Iterator<Type>;
private:
	int capacity;
	int size;
	std::unique_ptr<Type[]> elements;
	void resize();
public:
	Vector();
	void append(const Type& getElement);
	void erase(const Iterator<Type>& iterator);
	int length() const noexcept{
		return size;
	}
};

template <class Type>
class Iterator {
	friend class Vector<Type>;
private:
	const Vector<Type>& vector;
	int currentIndex;
public:
	Iterator(const Vector<Type>& vec) noexcept;
	const Type& getElement() const ;
	void setElement(const Type& elementNou) const;
	void next();
	bool valid() const noexcept;

};

class VectorException : public Error {
	using Error::Error;
public:
	static const std::string iteratorInvalid;
	static const std::string wrongIterator;
};

template <class Type>
Vector<Type>::Vector() {
	capacity = 2;
	size = 0;
	elements = std::make_unique<Type[]>(capacity);
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
Iterator<Type>::Iterator(const Vector<Type>& vec) noexcept : vector(vec) {
	currentIndex = 0;
}

template <class Type>
const Type& Iterator<Type>::getElement() const {
	if (valid()) {
		return vector.elements[currentIndex];
	}
	else {
		throw VectorException{ VectorException::iteratorInvalid };
	}
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
