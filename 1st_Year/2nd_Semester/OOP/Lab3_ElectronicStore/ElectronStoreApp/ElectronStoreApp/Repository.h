#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "Constants.h"
#include "ProductEntity.h"
#include "DynamicArray.h"

typedef struct {
	DynamicArray* list;
	int numberOfItems;
}Repository;

/*
	Initialises the repository with default values
*/
void initialiseRepository(Repository*, DynamicArray*);

/*
	Function that adds a new product into the repository
	repo - address of the repository we want to add the product into
	prod - variable of type Product which represents the Product we want to add
	Returns 1 if a new product was added to the repository, 0 if the product already existed
*/
int addProduct(Repository*, Product*);

/*
	Function that updates the contents of the repository, capable of modifying price, quantity or both
	repo - pointer to a variable of type Repository which represents the repository we're modifying
	id - integer which represents the unique identifier of the product we want to modify
	code - integer which represents the description for the modification target
		1 - modify price
		2 - modify quantiy
		3 - modify both
	... - the function has a variable number of arguments
		if code is equal to 1, there will be another double argument
		if code is equal to 2, there will be another int argument
		if code is equal to 3, there will be another two arguments, a double and an int
	Returns 1 if any product was updated and 0 if no product with that id was found
*/
int updateRepository(Repository*, int, int, ...);

/*
	Function that deletes a product from the repository
	repo - address to a variable of type Repository which represents the repository we want to delete products from
	id - integer which represents the unique identifier of the product we want to delete
	Returns 1 if the product was deleted successfully or 0 if there is no product with that unique identifier
*/
int deleteProduct(Repository*, int);

/*
	Function that returns the size of the repository
	repo - address to the repository whose size we want to find out
	Returns an integer which represents the size of the repository
*/
int size(Repository*);

/*
	Function that creates a copy of the contents of the repository
	repo -  address to a variable of type Repository
	Returns a DynamicArray pointer to the copy of the list stored in the repository
*/
DynamicArray* getAll(Repository*);
#endif