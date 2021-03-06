#include "ProductEntity.h"
#include <string.h>

void initialiseProduct(Product* x) {
	/*
		Initialises a variable of type Product with default values;
	*/
	x->uniqueIdentifier = 0;
	strcpy(x->model, "");
	x->price = 0.0;
	strcpy(x->producer, "");
	strcpy(x->type, "");
	x->quantity = 0;
}
int getUniqueID(Product x) {
	/*
		Finds the ID of a product
		x - variable of type Product
		Returns the id of that variable
	*/
	return x.uniqueIdentifier;
}
void setUniqueID(Product* x, int newID) {
	/*
		Sets the ID of a product to a specific value
		x - variable of type Product which represents the product we need to modify
		newID - integer which represents the new ID we must assign
	*/
	x->uniqueIdentifier = newID;
}
char* getType(Product x) {

	return &x.type;
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
char* getProducer(Product x) {
	/*
		Finds the producer of a product
		x - variable of type Product
		Returns a pointer to the producer of that variable
	*/
	return &x.producer;
}
void setProducer(Product* x, char newProducer[]) {
	/*
		Sets the producer of a product to a specific value
		x - variable of type Product which represents the product we need to modify
		newProducer - C-style string which represents the new producer we must assign
	*/
	strcpy(x->producer, newProducer);
}
char* getModel(Product x) {
	/*
		Finds the model of a product
		x - variable of type Product
		Returns a pointer to the model of that variable
	*/
	return &x.model;
}
void setModel(Product* x, char newModel[]) {
	/*
		Sets the model of a product to a specific value
		x - variable of type Product which represents the product we need to modify
		newProducer - C-style string which represents the new model we must assign
	*/
	strcpy(x->model, newModel);
}
double getPrice(Product x) {
	/*
		Finds the price of a product
		x - variable of type Product
		Returns a double value which represents the price of that product
	*/
	return x.price;
}
void setPrice(Product* x, double newPrice) {
	/*
		Sets the price of a product to a specific value
		x - variable of type Product which represents the product we need to modify
		newProducer - double which represents the new price we must assign
	*/
	x->price = newPrice;
}
int getQuantity(Product x) {
	/*
		Finds the quantity of a product
		x - variable of type Product
		Returns an int value which represents the quantity of that product
	*/
	return x.quantity;
}
void setQuantity(Product* x, int newQuantity) {
	/*
		Sets the quantity of a product to a specific value
		x - variable of type Product which represents the product we need to modify
		newQuantity - integer which represents the new quantity we must assign
	*/
	x->quantity = newQuantity;
}