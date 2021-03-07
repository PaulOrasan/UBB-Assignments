#include "ProductEntity.h"
#include <string.h>

void initialiseProduct(Product* x, int id, char type[], char producer[], char model[], double price, int quantity) {
	/*
		Initialises a variable of type Product with default values;
	*/
	x->uniqueIdentifier = id;
	strcpy(x->model, model);
	x->price = price;
	strcpy(x->producer, producer);
	strcpy(x->type, type);
	x->quantity = quantity;
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
void setQuantity(Product* x, int newQuantity) {
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