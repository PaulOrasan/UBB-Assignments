/*
	Module which defines the entity of a product of an electronic store
*/
#ifndef PRODUCT_ENTITY_H
#define PRODUCT_ENTITY_H
#include "Constants.h"

typedef struct {
	int uniqueIdentifier;
	char* type;
	char* producer;
	char* model;
	double price;
	int quantity;
}Product;

/*
	Initialises a variable of type Product with default values;
*/
Product* createProduct(int, char*, char*, char*, double, int);

Product* copyProduct(Product*);

/*
	Finds the ID of a product
	x - address of a variable of type Product
	Returns the id of that variable
*/
int getUniqueID(Product*);

/*
	Sets the ID of a product to a specific value
	x - variable of type Product which represents the product we need to modify
	newID - integer which represents the new ID we must assign
*/
void setUniqueID(Product*, int);

/*
	Function that finds the type of a product
	x - address of a variable of type Product
	returns the address to a C-style string
*/
char* getType(Product*);

/*
	Sets the type of a product to a specific value
	x - variable of type Product which represents the product we need to modify
	newType - C-style string which represents the new type we must assign
*/
void setType(Product*, char[]);

/*
	Finds the producer of a product
	x - address of a variable of type Product
	Returns a pointer to the producer of that variable
*/
char* getProducer(Product*);

/*
	Sets the producer of a product to a specific value
	x - variable of type Product which represents the product we need to modify
	newProducer - C-style string which represents the new producer we must assign
*/
void setProducer(Product*, char[]);

/*
	Finds the model of a product
	x - address of a variable of type Product
	Returns a pointer to the model of that variable
*/
char* getModel(Product*);

/*
	Sets the model of a product to a specific value
	x - variable of type Product which represents the product we need to modify
	newProducer - C-style string which represents the new model we must assign
*/
void setModel(Product*, char[]);

/*
	Finds the price of a product
	x - address of a variable of type Product
	Returns a double value which represents the price of that product
*/
double getPrice(Product*);

/*
	Sets the price of a product to a specific value
	x - variable of type Product which represents the product we need to modify
	newProducer - double which represents the new price we must assign
*/
void setPrice(Product*, double);

/*
	Finds the quantity of a product
	x - address of a variable of type Product
	Returns an int value which represents the quantity of that product
*/
int getQuantity(Product*);

/*
	Sets the quantity of a product to a specific value
	x - variable of type Product which represents the product we need to modify
	newQuantity - integer which represents the new quantity we must assign
*/
void setQuantity(Product*, int);

/*
	Tests if two products are equal
	a - variable of type Product
	b - variable of type Product
	Returns 1 if a is considered equal to b or 0 otherwise
*/
int equality(Product* a, Product* b);

/*
	Deallocates the memory occupied by a Product
	elem - address of a variable of type Product
*/
void destroyProduct(Product*);

/*
	Function that compares the price of two products and determines if they are in increasing sequence
	a - address of a product on the left side
	b - address of a product on the right side
	Returns 1 if the price of product a is smaller than the price of product b
	Returns 0 if the prices are equal
	Returns -1 if the price of product a is bigger than the price of product b
*/
int compareProductPriceIncreasing(Product*, Product*);

/*
	Function that compares the price of two products and determines if they are in decreasing sequence
	a - address of a product on the left side
	b - address of a product on the right side
	Returns 1 if the price of product a is bigger than the price of product b
	Returns 0 if the prices are equal
	Returns -1 if the price of product a is smaller than the price of product b
*/
int compareProductPriceDecreasing(Product*, Product*);

/*
	Function that compares the quantity of two products and determines if they are in increasing sequence
	a - address of a product on the left side
	b - address of a product on the right side
	Returns 1 if the quantity of product a is smaller than the price of product b
	Returns 0 if the quantity are equal
	Returns -1 if the quantity of product a is bigger than the price of product b
*/
int compareProductQuantityIncreasing(Product*, Product*);

/*
	Function that compares the quantity of two products and determines if they are in decreasing sequence
	a - address of a product on the left side
	b - address of a product on the right side
	Returns 1 if the quantity of product a is bigger than the price of product b
	Returns 0 if the quantity are equal
	Returns -1 if the quantity of product a is smaller than the price of product b
*/
int compareProductQuantityDecreasing(Product*, Product*);

/*
	Function that checks whether the producer of a product is equal to a specific value
	a - address of a variable of type Product that we want to check
	str - pointer of type void which addresses a C-style string
	Returns 1 if the equality holds and 0 otherwise
*/
int filterProductProducer(Product*, void*);

/*
	Function that checks whether the price of a product is equal to a specific value
	a - address of a variable of type Product that we want to check
	pri - pointer of type void which addresses a double
	Returns 1 if the equality holds and 0 otherwise
*/
int filterProductPrice(Product*, void*);

/*
	Function that checks whether the quantity of a product is equal to a specific value
	a - address of a variable of type Product that we want to check
	quan - pointer of type void which addresses a int
	Returns 1 if the equality holds and 0 otherwise
*/
int filterProductQuantity(Product*, void*);

/*
	Function that checks if a product has the same id as a parameter
	prod - pointer to a product
	id - pointer to an int
	Returns 1 if the equality stands and 0 otherwise
*/
int searchById(Product*, int*);
#endif