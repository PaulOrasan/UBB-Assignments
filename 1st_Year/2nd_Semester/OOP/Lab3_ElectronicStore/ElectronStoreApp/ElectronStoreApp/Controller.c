#include "Controller.h"
#include "Repository.h"
#include "ProductEntity.h"
#include "Constants.h"
#include <string.h>
int serviceAddProduct(Service* serv, int id, char type[], char producer[], char model[], double price, int quantity) {
	/*
		Function that creates a Product Entity and adds it to the repository referenced by the service
		serv - address to a variable of type Service
		id - integer that represents the id of the new product
		type - C-style array that represents the type of the new product
		producer - C-style array that represents the producer of the new product
		model - C-style array that represents the model of the new product
		price - double that represents the price of the new product
		quantity - integer that represents the quantity of the new product
		Returns 1 if the new product was added to the repository, 0 if the product already existed and -1 if the capacity of the repo is reached
	*/
	Product* x;
	x = createProduct(id, type, producer, model, price, quantity);
	int result = addProduct(serv->repo, x);
	destroyProduct(x);
	return result;
}
int serviceUpdateRepository(Service* serv, int id, double newPrice, int newQuantity) {
	/*
		Function that updates the repository by modifying either price or quantity of a product identified by an id
		serv - address to a variable of type Service
		id - integer that represents the id of the product we need to update
		newPrice - double that represents the new price of that product
		newQuantity - integer that represents the new quantity of that product
		Returns 1 if the product was updated and 0 if no product was found in the repository having the same id
	*/
	if (newPrice > 0 && newQuantity > -1) {
		return updateRepository(serv->repo, id, PRICE_AND_QUANTITY_UPDATE_CODE, newPrice, newQuantity);
	} else if (newQuantity > -1) {
		return updateRepository(serv->repo, id, QUANTITY_UPDATE_CODE, newQuantity);
	} else if (newPrice>0){
		return updateRepository(serv->repo, id, PRICE_UPDATE_CODE, newPrice);
	}
	return 0;
}
int serviceDeleteProduct(Service* serv, int id) {
	/*
		Function that deletes a product from the repository
		serv - address to a variable of type Service
		id - integer that represents the id of the product we need to update
		Returns 1 if the product having the same id as the parameter was deleted from the repository or 0 if no such product was found
	*/
	return deleteProduct(serv->repo, id);
}
int serviceSize(Service* serv) {
	/*
		Function that finds the total number of elements from the repository
		serv - address to a variable of type Service
		Returns the number of products stored in the repository referenced by the current service
	*/
	return size(serv->repo);
}
DynamicArray* serviceGetAll(Service* serv) {
	/*
		Function that creates a copy of the contents of the repository
		serv - address to a variable of type Service
		newList - address to an array of product where the contents of the repository will be copied
	*/
	return getAll(serv->repo);
}

int serviceSort(Service* serv, DynamicArray** newList, char* type, char* order) {
	/*
		Function that will create a report of the elements from the repository sorted by price or quantity either increasingly or decreasingly
		serv - address to a variable of type Service
		newList - address to a DynamicArray
		type - C-style string which describres the type of sort needed (must be either "price" or "quantity")
		order - C-style string which describres the order of the sort (must be either "increasing" or "decreasing")
		Returns 1 if the array was sorted and the report generated or 0 if the type or order are incorrect
	*/
	*newList = getAll(serv->repo);
	int ok = 0;
	if (strcmp(order, "increasing") == 0) {
		if (strcmp(type, "price") == 0) {
			sort(*newList, compareProductPriceIncreasing);
			ok = 1;
		}
		if (strcmp(type, "quantity") == 0) {
			sort(*newList, compareProductQuantityIncreasing);
			ok = 1;
		}
	}
	if (strcmp(order, "decreasing") == 0) {
		if (strcmp(type, "price") == 0) {
			sort(*newList, compareProductPriceDecreasing);
			ok = 1;
		}
		if (strcmp(type, "quantity") == 0) {
			sort(*newList, compareProductQuantityDecreasing);
			ok = 1;
		}
	}
	return ok;
}
int serviceFilter(Service* serv, DynamicArray** newList, char* type, void* address) {
	/*
		Function that will create a report which will represent the content stored in repository filtered by a criteria
		serv - address to a variable of type Service
		newList - address to a DynamicArray
		type - C-style string which describres the type of filter needed (must be either "price", "quantity" or "producer")
		address - void pointer which represents the criteria we filter on 
		Returns 1 if the array was filtered and the report generated or 0 if the type or order are incorrect
	*/
	*newList = getAll(serv->repo);
	int ok = 0;
	if (strcmp(type, "producer") == 0) {
		filter(*newList, filterProductProducer, address);
		ok = 1;
	}
	if (strcmp(type, "price") == 0) {
		filter(*newList, filterProductPrice, address);
		ok = 1;
	}
	if (strcmp(type, "quantity") == 0) {
		filter(*newList, filterProductQuantity, address);
		ok = 1;
	}
	return ok;
}