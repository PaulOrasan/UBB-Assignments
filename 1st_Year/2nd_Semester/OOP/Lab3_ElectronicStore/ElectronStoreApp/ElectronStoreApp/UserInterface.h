#ifndef UI_H
#define UI_H
#include "Controller.h"
#include "ProductEntity.h"
typedef struct {
	Service* serv;
}UI;

/*
	Function that runs the entire UI
*/
void run(UI*);

/*
	Function that displays the menu options in console
*/
void showMenu();

/*
	Function that controls the interface for the add product feature
*/
void interfaceAddProduct(UI*);

/*
	Function that controls the interface for the update repository feature
*/
void interfaceUpdateRepository(UI*);

/*
	Function that implements the interface for the delete product feature
*/
void interfaceDeleteProduct(UI*);

/*
	Function that displays all products
*/
void interfaceShowContent(UI*);

/*
	Function that implements the interface for the sorting function
*/
void interfaceSort(UI*);

/*
	Function that implements the interface of the filter function
*/
void interfaceFilter(UI*);

/*
	Function that prints out details of a product
*/
void showProduct(Product*);

/*
	Function that displays the array in console
*/
void showArray(DynamicArray*);

/*
	Function that checks and cleans the buffer in case the user inputs too many characters
*/
void cleanBuffer();
#endif