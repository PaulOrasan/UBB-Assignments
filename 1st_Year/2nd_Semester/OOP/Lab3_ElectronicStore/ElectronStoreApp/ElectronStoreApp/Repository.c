#include "Repository.h"
#include <stdarg.h>
void initialiseRepository(Repository* repo, DynamicArray* v) {
	/*
		Initialises the repository with default values
		repo - address of the repository we want to initialise
		v - address of the array we will use for the repository
	*/
	repo->list = v;
	repo->numberOfItems = 0;
}
int addProduct(Repository* repo, Product* prod) {
	/*
		Function that adds a new product into the repository
		repo - address of the repository we want to add the product into
		prod - variable of type Product which represents the Product we want to add
		Returns 1 if a new product was added to the repository, 0 if the product already existed
	*/
	int id = getUniqueID(prod);
	Product** result = (Product**)searchElement(repo->list, searchById, &id);
	if (result == NULL) {
		appendArray(repo->list, prod);
		repo->numberOfItems++;
		return 1;
	}
	setQuantity(*result, getQuantity(prod));
	return 0;
}
int updateRepository(Repository* repo, int id, int code, ...) {
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
	va_list parameters;			// stores the variadic parameters of the function
	Product** result = (Product**)searchElement(repo->list, searchById, &id);
	if (result == NULL)
		return 0;
	double newPrice = getPrice(*result);
	int newQuantity = getQuantity(*result);
	va_start(parameters, code);
	if (code == 1) {
		newPrice = va_arg(parameters, double);
	}
	if (code == 2) {
		newQuantity = va_arg(parameters, int);
	}
	if (code == 3) {
		newPrice = va_arg(parameters, double);
		newQuantity = va_arg(parameters, int);
	}
	setPrice(*result, newPrice);
	setQuantity(*result, newQuantity);
	return 1;
}

int deleteProduct(Repository* repo, int id) {
	/*
		Function that deletes a product from the repository
		repo - address to a variable of type Repository which represents the repository we want to delete products from
		id - integer which represents the unique identifier of the product we want to delete
		Returns 1 if the product was deleted successfully or 0 if there is no product with that unique identifier
	*/
	Product** result = (Product**)searchElement(repo->list, searchById, &id);
	if (result == NULL)
		return 0;
	deleteElement(repo->list, id);
	repo->numberOfItems--;
	return 1;
}
int size(Repository* repo) {
	/*
		Function that returns the size of the repository
		repo - address to the repository whose size we want to find out
		Returns an integer which represents the size of the repository
	*/
	return repo->numberOfItems;
}

DynamicArray* getAll(Repository* repo) {
	/*
		Function that creates a copy of the contents of the repository
		repo -  address to a variable of type Repository 
	*/
	return copyArray(repo->list);
}