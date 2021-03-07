/*
	Module which defines the entity of a product of an electronic store
*/
#ifndef PRODUCT_ENTITY_H
#define PRODUCT_ENTITY_H
#include "Constants.h"

typedef struct {
	int uniqueIdentifier;
	char type[STRING_LENGTH];
	char producer[STRING_LENGTH];
	char model[STRING_LENGTH];
	double price;
	int quantity;
}Product;

void initialiseProduct(Product*, int, char*, char*, char*, double, int);
int getUniqueID(Product*);
void setUniqueID(Product*, int);
char* getType(Product*);
void setType(Product*, char[]);
char* getProducer(Product*);
void setProducer(Product*, char[]);
char* getModel(Product*);
void setModel(Product*, char[]);
double getPrice(Product*);
void setPrice(Product*, double);
int getQuantity(Product*);
void setQuantity(Product*, int);
#endif