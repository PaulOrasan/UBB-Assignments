#include "ProductEntity.h"
#include <string.h>
#include <stdlib.h>
Product* createProduct(int id, char type[], char producer[], char model[], double price, int quantity) {
	/*
		Initialises a variable of type Product with default values;
	*/
	Product* x = (Product*)malloc(sizeof(Product));
	x->uniqueIdentifier = id;
	x->model = (char*)malloc((strlen(model) + 1) * sizeof(char));
	strcpy(x->model, model);
	x->price = price;
	x->producer = (char*)malloc((strlen(producer) + 1) * sizeof(char));
	strcpy(x->producer, producer);
	x->type = (char*)malloc((strlen(type) + 1) * sizeof(char));
	strcpy(x->type, type);
	x->quantity = quantity;
	return x;
}

Product* copyProduct(Product* x) {
	/*
		Function that copies the values of the second product in the first product
		x - address of a variable of type Product which represents the Product we want to copy
	*/
	return createProduct(getUniqueID(x), getType(x), getProducer(x), getModel(x), getPrice(x), getQuantity(x));
}
int getUniqueID(Product* x) {
	/*
		Finds the ID of a product
		x - address of a variable of type Product
		Returns the id of that variable
	*/
	return x->uniqueIdentifier;
}
void setUniqueID(Product* x, int newID) {
	/*
		Sets the ID of a product to a specific value
		x - variable of type Product which represents the product we need to modify
		newID - integer which represents the new ID we must assign
	*/
	x->uniqueIdentifier = newID;
}
char* getType(Product* x) {

	/*
		Function that finds the type of a product
		x - address of a variable of type Product
		returns the address to a C-style string
	*/
	return x->type;
}
void setType(Product* x, char newType[])
{
	/*
		Sets the type of a product to a specific value
		x - variable of type Product which represents the product we need to modify
		newType - C-style string which represents the new type we must assign
	*/
	x->type = (char*)realloc(x->type, (strlen(newType) + 1) * sizeof(char));
	strcpy(x->type, newType);
}
char* getProducer(Product* x) {
	/*
		Finds the producer of a product
		x - address of a variable of type Product
		Returns a pointer to the producer of that variable
	*/
	return x->producer;
}
void setProducer(Product* x, char newProducer[]) {
	/*
		Sets the producer of a product to a specific value
		x - variable of type Product which represents the product we need to modify
		newProducer - C-style string which represents the new producer we must assign
	*/
	x->producer = (char*)realloc(x->producer, (strlen(newProducer) + 1) * sizeof(char));
	strcpy(x->producer, newProducer);
}
char* getModel(Product* x) {
	/*
		Finds the model of a product
		x - address of a variable of type Product
		Returns a pointer to the model of that variable
	*/
	return x->model;
}
void setModel(Product* x, char newModel[]) {
	/*
		Sets the model of a product to a specific value
		x - variable of type Product which represents the product we need to modify
		newProducer - C-style string which represents the new model we must assign
	*/
	if (x->model!=NULL)
		x->model = (char*)realloc(x->model, (strlen(newModel) + 1) * sizeof(char));
	if (x->model!=NULL)
		strcpy(x->model, newModel);
}
double getPrice(Product* x) {
	/*
		Finds the price of a product
		x - address of a variable of type Product
		Returns a double value which represents the price of that product
	*/
	return x->price;
}
void setPrice(Product* x, double newPrice) {
	/*
		Sets the price of a product to a specific value
		x - variable of type Product which represents the product we need to modify
		newProducer - double which represents the new price we must assign
	*/
	x->price = newPrice;
}
int getQuantity(Product* x) {
	/*
		Finds the quantity of a product
		x - address of a variable of type Product
		Returns an int value which represents the quantity of that product
	*/
	return x->quantity;
}
void setQuantity(Product* x , int newQuantity) {
	/*
		Sets the quantity of a product to a specific value
		x - variable of type Product which represents the product we need to modify
		newQuantity - integer which represents the new quantity we must assign
	*/
	x->quantity = newQuantity;
}

int equality(Product* a, Product* b) {
	/*
		Tests if two products are equal
		a - variable of type Product
		b - variable of type Product
		Returns 1 if a is considered equal to b or 0 otherwise
	*/
	// bad looking code but gets the job done
	double epsilon = 0.00001;
	int value = 1 && getUniqueID(a) == getUniqueID(b) && getQuantity(a) == getQuantity(b) && getPrice(a) - getPrice(b) > -epsilon && getPrice(a) - getPrice(b) < epsilon;
	char* x = getType(a);
	char* y = getType(b);
	value = value && (strcmp(x, y) == 0);
	x = getProducer(a);
	y = getProducer(b);
	value = value && (strcmp(x, y) == 0);
	x = getModel(a);
	y = getModel(b);
	value = value && (strcmp(x, y) == 0);
	return value;
}

void destroyProduct(Product* elem) {
	/*
		Deallocates the memory occupied by a Product
		elem - address of a variable of type Product
	*/
	free(getType(elem));
	free(getProducer(elem));
	free(getModel(elem));
	free(elem);
}

int compareProductPriceIncreasing(Product* a, Product* b) {
	/*
		Function that compares the price of two products and determines if they are in increasing sequence
		a - address of a product on the left side
		b - address of a product on the right side
		Returns 1 if the price of product a is smaller than the price of product b
		Returns 0 if the prices are equal
		Returns -1 if the price of product a is bigger than the price of product b
	*/
	double epsilon = 0.000001, priceA = getPrice(a), priceB = getPrice(b);
	if (priceA - priceB<epsilon && priceA - priceB>-epsilon) {
		return 0;
	}
	if (priceA - priceB < 0) {
		return 1;
	}
	return -1;
}


int compareProductPriceDecreasing(Product* a, Product* b) {
	/*
		Function that compares the price of two products and determines if they are in decreasing sequence
		a - address of a product on the left side
		b - address of a product on the right side
		Returns 1 if the price of product a is bigger than the price of product b
		Returns 0 if the prices are equal
		Returns -1 if the price of product a is smaller than the price of product b
	*/
	double epsilon = 0.000001, priceA = getPrice(a), priceB = getPrice(b);
	if (priceA - priceB<epsilon && priceA - priceB>-epsilon) {
		return 0;
	}
	if (priceA - priceB < 0) {
		return -1;
	}
	return 1;
}


int compareProductQuantityIncreasing(Product* a, Product* b) {
	/*
		Function that compares the quantity of two products and determines if they are in increasing sequence
		a - address of a product on the left side
		b - address of a product on the right side
		Returns 1 if the quantity of product a is smaller than the price of product b
		Returns 0 if the quantity are equal
		Returns -1 if the quantity of product a is bigger than the price of product b
	*/
	int quantityA = getQuantity(a), quantityB = getQuantity(b);
	if (quantityA == quantityB) {
		return 0;
	}
	if (quantityA < quantityB)
		return 1;
	return -1;
}


int compareProductQuantityDecreasing(Product* a, Product* b) {
	/*
		Function that compares the quantity of two products and determines if they are in decreasing sequence
		a - address of a product on the left side
		b - address of a product on the right side
		Returns 1 if the quantity of product a is bigger than the price of product b
		Returns 0 if the quantity are equal
		Returns -1 if the quantity of product a is smaller than the price of product b
	*/
	int quantityA = getQuantity(a), quantityB = getQuantity(b);
	if (quantityA == quantityB) {
		return 0;
	}
	if (quantityA < quantityB)
		return -1;
	return 1;
}

int filterProductProducer(Product* a, void* str) {
	/*
		Function that checks whether the producer of a product is equal to a specific value
		a - address of a variable of type Product that we want to check
		str - pointer of type void which addresses a C-style string
		Returns 1 if the equality holds and 0 otherwise
	*/
	if (strcmp(getProducer(a), (char*)str) == 0)
		return 1;
	return 0;
}

int filterProductPrice(Product* a, void* pri) {
	/*
		Function that checks whether the price of a product is equal to a specific value
		a - address of a variable of type Product that we want to check
		pri - pointer of type void which addresses a double
		Returns 1 if the equality holds and 0 otherwise
	*/
	double epsilon = 0.0000001, price = getPrice(a), newPrice = *(double*)pri;
	if (price - newPrice<epsilon && price - newPrice>-epsilon)
		return 1;
	return 0;
}

int filterProductQuantity(Product* a, void* quan) {
	/*
		Function that checks whether the quantity of a product is equal to a specific value
		a - address of a variable of type Product that we want to check
		quan - pointer of type void which addresses a int
		Returns 1 if the equality holds and 0 otherwise
	*/
	if (getQuantity(a) == *(int*)quan)
		return 1;
	return 0;
}

int searchById(Product* prod, int* id) {
	if (getUniqueID(prod) == *id)
		return 1;
	return 0;
}