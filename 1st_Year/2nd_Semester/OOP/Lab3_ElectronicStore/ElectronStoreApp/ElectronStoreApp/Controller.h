#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Repository.h"
#include "ProductEntity.h"
typedef struct {
	Repository* repo;
}Service;

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
int serviceAddProduct(Service*, int, char*, char*, char*, double, int);

/*
	Function that updates the repository by modifying either price or quantity of a product identified by an id
	serv - address to a variable of type Service
	id - integer that represents the id of the product we need to update
	newPrice - double that represents the new price of that product
	newQuantity - integer that represents the new quantity of that product
	Returns 1 if the product was updated and 0 if no product was found in the repository having the same id
*/
int serviceUpdateRepository(Service*, int, double, int);

/*
	Function that deletes a product from the repository
	serv - address to a variable of type Service
	id - integer that represents the id of the product we need to update
	Returns 1 if the product having the same id as the parameter was deleted from the repository or 0 if no such product was found
*/
int serviceDeleteProduct(Service*, int);

/*
	Function that finds the total number of elements from the repository
	serv - address to a variable of type Service
	Returns the number of products stored in the repository referenced by the current service
*/
int serviceSize(Service*);

/*
	Function that creates a copy of the contents of the repository
	serv - address to a variable of type Service
	Returns the address of a DynamicArray which represents the copy of the repository
*/
DynamicArray* serviceGetAll(Service*);

/*
	Function that will create a report of the elements from the repository sorted by price or quantity either increasingly or decreasingly
	serv - address to a variable of type Service
	newList - address to a DynamicArray*
	type - C-style string which describres the type of sort needed (must be either "price" or "quantity")
	order - C-style string which describres the order of the sort (must be either "increasing" or "decreasing")
	Returns 1 if the array was sorted and the report generated or 0 if the type or order are incorrect
*/
int serviceSort(Service*, DynamicArray**, char*, char*);

/*
	Function that will create a report which will represent the content stored in repository filtered by a criteria
	serv - address to a variable of type Service
	newList - address to a DynamicArray*
	type - C-style string which describres the type of filter needed (must be either "price", "quantity" or "producer")
	address - void pointer which represents the criteria we filter on
	Returns 1 if the array was filtered and the report generated or 0 if the type or order are incorrect
*/
int serviceFilter(Service*, DynamicArray**, char*, void*);
#endif