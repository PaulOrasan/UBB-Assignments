#include "Repository.h"
#include <stdarg.h>
void initialiseRepository(Repository* repo) {
	/*
		Initialises the repository with default values
	*/
	repo->numberOfItems = 0;
}
int addProduct(Repository* repo, Product prod) {
	/*
		Function that adds a new product into the repository
		repo - address of the repository we want to add the product into
		prod - variable of type Product which represents the Product we want to add
		Returns 1 if a new product was added to the repository, 0 if the product already existed and -1 if the repo's capacity was reached
	*/
	for (int index = 0; index < repo->numberOfItems; index++) {
		if (getUniqueID(repo->list[index]) == getUniqueID(prod)) {								// if the product already exist
			updateRepository(repo, getUniqueID(prod), QUANTITY_UPDATE_CODE, getQuantity(prod)); // we update the quantity
			return 0;
		}																						
	}
	if (repo->numberOfItems == REPOSITORY_CAPACITY) {
		return -1;
	}
	repo->numberOfItems++;
	repo->list[repo->numberOfItems-1] = prod;
	return 1;

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
	int found = 0;
	va_list parameters;			// stores the variadic parameters of the function
	for (int index = 0; index < repo->numberOfItems; index++) {
		if (getUniqueID(repo->list[index]) == id) {
			found = 1;
			double newPrice = getPrice(repo->list[index]);
			int newQuantity = getQuantity(repo->list[index]);
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
			setPrice(&repo->list[index], newPrice);
			setQuantity(&repo->list[index], newQuantity);
		}
	}
	return found;
}

int deleteProduct(Repository* repo, int id) {
	/*
		Function that deletes a product from the repository
		repo - address to a variable of type Repository which represents the repository we want to delete products from
		id - integer which represents the unique identifier of the product we want to delete
		Returns 1 if the product was deleted successfully or 0 if there is no product with that unique identifier
	*/
	int found = 0;
	for (int index = 0; index < repo->numberOfItems; index++) {
		if (getUniqueID(repo->list[index]) == id) {
			found = 1;
			for (int deleteIndex = index; deleteIndex < repo->numberOfItems - 1; deleteIndex++) {
				repo->list[deleteIndex] = repo->list[deleteIndex + 1];
			}
			repo->numberOfItems--;
		}
	}
	return found;
}
int size(Repository* repo) {
	/*
		Function that returns the size of the repository
		repo - address to the repository whose size we want to find out
		Returns an integer which represents the size of the repository
	*/
	return repo->numberOfItems;
}