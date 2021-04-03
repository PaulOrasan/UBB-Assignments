#include "UserInterface.h"
#include <stdio.h>
#include "Constants.h"
#include "Validation.h"
#include "Controller.h"
#include <string.h>
void run(UI* ui) {
	/*
		Function that runs the entire UI
	*/
	int option;
	char inputString[STRING_LENGTH];
	void* helper;
	while (1) {
		showMenu();
		fgets(inputString, STRING_LENGTH - 1, stdin);
		cleanBuffer(inputString);
		inputString[strlen(inputString) - 1] = '\0';		// fgets reads \n as well
		if (strlen(inputString) == 0) {
			printf("Error: Invalid input! You did not enter any characters.\n");
			return;
		}
		helper = &option;
		if (validateString(inputString, strtolWrapped, helper)) {
			switch (option) {
				case 1:
					interfaceAddProduct(ui);
					break;
				case 2:
					interfaceUpdateRepository(ui);
					break;
				case 3:
					interfaceDeleteProduct(ui);
					break;
				case 4:
					interfaceShowContent(ui);
					break;
				case 5:
					interfaceSort(ui);
					break;
				case 6:
					interfaceFilter(ui);
					break;
				case 7:
					printf("Goodbye!\n");
					return;
				default:
					printf("Error: The command you inputted is non-existent.\n");
					break;
			}
		}
		else {
			printf("Error: The command you inputted is not valid. The command must be a number from 1 to 5.\n");
		}
	}
}
void cleanBuffer(char *s) {
	/*
		Function that checks and cleans the buffer in case the user inputs too many characters
	*/
	if (strchr(s, '\n'))
		return;
	char n = (char)getchar();
	while (n != '\n' && n != EOF) {
		n = (char)getchar();
	}
}
void showMenu() {
	/*
		Function that displays the menu options in console
	*/
	printf("Menu\n");
	printf("1. Add product\n");
	printf("2. Update quantity or price of product\n");
	printf("3. Delete product\n");
	printf("4. Show products\n");
	printf("5. Sort products\n");
	printf("6. Filter products\n");
	printf("7. Exit\n");
	printf("Please input the code for one of the options above: ");
}

void interfaceAddProduct(UI* ui) {
	/*
		Function that controls the interface for the add product feature
	*/
	int id, quantity;
	char type[STRING_LENGTH], producer[STRING_LENGTH], model[STRING_LENGTH], inputString[STRING_LENGTH];
	double price;
	void* helper;
	printf("Please input the product's ID (positive integer): ");
	fgets(inputString, STRING_LENGTH - 1, stdin);
	cleanBuffer(inputString);
	inputString[strlen(inputString) - 1] = '\0';
	if (strlen(inputString) == 0) {
		printf("Error: Invalid input! You did not enter any characters.\n");
		return;
	}
	helper = &id;
	if (!validateString(inputString, strtolWrapped, helper)) {
		printf("Error: Invalid input! The ID must be a positive integer.\n");
		return;
	}
	else if (id < 0) {
		printf("Error: Invalid input! The ID must be a positive integer.\n");
		return;
	}
	printf("Please input the product's type: ");
	fgets(type, STRING_LENGTH - 1, stdin);
	cleanBuffer(type);
	type[strlen(type) - 1] = '\0';
	if (strlen(type) == 0) {
		printf("Error: Invalid input! You did not enter any characters.\n");
		return;
	}
	printf("Please input the product's producer: ");
	fgets(producer, STRING_LENGTH - 1, stdin);
	cleanBuffer(producer);
	producer[strlen(producer) - 1] = '\0';
	if (strlen(producer) == 0) {
		printf("Error: Invalid input! You did not enter any characters.\n");
		return;
	}
	printf("Please input the product's model: ");
	fgets(model, STRING_LENGTH - 1, stdin);
	cleanBuffer(model);
	model[strlen(model) - 1] = '\0';
	if (strlen(model) == 0) {
		printf("Error: Invalid input! You did not enter any characters.\n");
		return;
	}
	printf("Please input the product's price (positive real number): ");
	fgets(inputString, STRING_LENGTH - 1, stdin);
	cleanBuffer(inputString);
	inputString[strlen(inputString) - 1] = '\0';
	if (strlen(inputString) == 0) {
		printf("Error: Invalid input! You did not enter any characters.\n");
		return;
	}
	helper = &price;
	if (!validateString(inputString, strtodWrapped, helper)) {
		printf("Error: Invalid input! The price must be a positive real number (use . instead of comma).\n");
		return;
	}
	else if (price < 0) {
		printf("Error: Invalid input! The price must be a positive real number (use . instead of comma).\n");
		return;
	}
	helper = &quantity;
	printf("Please input the product's quantity (positive integer): ");
	fgets(inputString, STRING_LENGTH - 1, stdin);
	cleanBuffer(inputString);
	inputString[strlen(inputString) - 1] = '\0';
	if (strlen(inputString) == 0) {
		printf("Error: Invalid input! You did not enter any characters.\n");
		return;
	}
	if (!validateString(inputString, strtolWrapped, helper)) {
		printf("Error: Invalid input! The quantity must be a positive integer.\n");
		return;
	}
	else if (quantity < 0) {
		printf("Error: Invalid input! The quantity must be a positive integer.\n");
		return;
	}
	int result = serviceAddProduct(ui->serv, id, type, producer, model, price, quantity);
	if (result == 1) {
		printf("The product was added successfully!\n");
		return;
	}
	else if (result == 0) {
		printf("The product already exists in the database! Updated the quantity.\n");
		return;
	}
	else if (result == -1) {
		printf("The maximum capacity of storage was reached and the product could not be added.\n");
		return;
	}
	printf("Critical error: contact application administrator for solution\n");
}
void interfaceUpdateRepository(UI* ui) {
	/*
		Function that controls the interface for the update repository feature
	*/
	char inputString[STRING_LENGTH];
	int id, newQuantity = -1;
	double newPrice = -1.0;
	void* helper;
	printf("Please input the ID of the product you want to update: ");
	fgets(inputString, STRING_LENGTH - 1, stdin);
	cleanBuffer(inputString);
	inputString[strlen(inputString) - 1] = '\0';
	if (strlen(inputString) == 0) {
		printf("Error: Invalid input! You did not enter any characters.\n");
		return;
	}
	helper = &id;
	if (!validateString(inputString, strtolWrapped, helper)) {
		printf("Error: Invalid input! The ID must be a positive integer.\n");
		return;
	}
	else if (id < 0) {
		printf("Error: Invalid input! The ID must be a positive integer.\n");
		return;
	}
	printf("Please input the new price you want for the product (leave empty if you want to leave unchanged): ");
	fgets(inputString, STRING_LENGTH - 1, stdin);
	cleanBuffer(inputString);
	if (inputString[0] != '\n') {
		inputString[strlen(inputString) - 1] = '\0';
		helper = &newPrice;
		if (!validateString(inputString, strtodWrapped, helper)) {
			printf("Error: Invalid input! The price must be a positive real number.\n");
			return;
		}
		else if (newPrice < 0) {
			printf("Error: Invalid input! The price must be a positive real number.\n");
			return;
		}
	}
	printf("Please input the new quantity you want for the product (leave empty if you want to leave unchanged): ");
	fgets(inputString, STRING_LENGTH - 1, stdin);
	cleanBuffer(inputString);
	if (inputString[0] != '\n') {
		inputString[strlen(inputString) - 1] = '\0';
		helper = &newQuantity;
		if (!validateString(inputString, strtolWrapped, helper)) {
			printf("Error: Invalid input! The quantity must be a positive integer.\n");
			return;
		}
		else if (newQuantity < 0) {
			printf("Error: Invalid input! The quantity must be a positive integer.\n");
			return;
		}
	}
	if (newPrice < 0 && newQuantity < 0) {
		printf("There is no change to be made.\n");
		return;
	}
	int result = serviceUpdateRepository(ui->serv, id, newPrice, newQuantity);
	if (result == 1) {
		printf("The product was updated successfully.\n");
		return;
	}
	else if (result == 0) {
		printf("No product with that ID exists.\n");
		return;
	}
	printf("Critical error: contact administrator for solution.\n");
}
void interfaceDeleteProduct(UI* ui) {
	/*
		Function that implements the interface for the delete product feature
	*/
	printf("Please input the ID of the product you want to delete (positive integer): ");
	int id;
	char inputString[STRING_LENGTH];
	void* helper;
	fgets(inputString, STRING_LENGTH - 1, stdin);
	cleanBuffer(inputString);
	inputString[strlen(inputString) - 1] = '\0';
	if (strlen(inputString) == 0) {
		printf("Error: Invalid input! You did not enter any characters.\n");
		return;
	}
	helper = &id;
	if (!validateString(inputString, strtolWrapped, helper)) {
		printf("Error: Invalid input! The ID must be a positive integer.\n");
		return;
	}
	else if (id < 0) {
		printf("Error: Invalid input! The ID must be a positive integer.\n");
		return;
	}
	int result = serviceDeleteProduct(ui->serv, id);
	if (result == 1) {
		printf("The product was deleted successfully.\n");
		return;
	}
	else if (result == 0) {
		printf("There exists no product with that ID.\n");
		return;
	}
	printf("Critical error: contact administrator for solution\n");
}
void interfaceShowContent(UI* ui) {
	/*
		Function that displays all products
	*/
	DynamicArray* newList = serviceGetAll(ui->serv);
	showArray(newList);
	destroyArray(newList);
}
void interfaceSort(UI* ui) {
	/*
		Function that implements the interface for the sorting function
	*/
	char type[STRING_LENGTH], order[STRING_LENGTH];
	printf("Input the type of sorting you want (must be either \"price\" or \"quantity\": ");
	fgets(type, STRING_LENGTH - 1, stdin);
	cleanBuffer(type);
	type[strlen(type) - 1] = '\0';
	if (strlen(type) == 0) {
		printf("Error: Invalid input! You did not enter any characters.\n");
		return;
	}
	printf("Input the order of sorting you want (must be either \"increasing\" or \"decreasing\": ");
	fgets(order, STRING_LENGTH - 1, stdin);
	cleanBuffer(order);
	order[strlen(order) - 1] = '\0';
	if (strlen(order) == 0) {
		printf("Error: Invalid input! You did not enter any characters.\n");
		return;
	}
	DynamicArray* newList;
	int result = serviceSort(ui->serv, &newList, type, order);
	if (result == 0) {
		printf("Error: Invalid input! Please respect the type and order of the available sort\n");
		destroyArray(newList);
		return;
	}
	showArray(newList);
	destroyArray(newList);
}
void interfaceFilter(UI* ui) {
	/*
		Function that implements the interface of the filter function
	*/
	char type[STRING_LENGTH], producer[STRING_LENGTH], inputString[STRING_LENGTH];
	double price;
	int quantity;
	void* helper;
	printf("Input the type of filter you want to apply (must be \"price\", \"producer\" or \"quantity\": ");
	fgets(type, STRING_LENGTH - 1, stdin);
	cleanBuffer(type);
	type[strlen(type) - 1] = '\0';
	if (strlen(type) == 0) {
		printf("Error: Invalid input! You did not enter any characters.\n");
		return;
	}
	DynamicArray* newList = NULL;
	if (strcmp(type, "producer") == 0) {
		printf("Input the producer you want to filter by: ");
		fgets(producer, STRING_LENGTH - 1, stdin);
		cleanBuffer(producer);
		producer[strlen(producer) - 1] = '\0';
		if (strlen(producer) == 0) {
			printf("Error: Invalid input! You did not enter any characters.\n");
			return;
		}
		serviceFilter(ui->serv, &newList, type, producer);
		showArray(newList);
		destroyArray(newList);
		return;
	}
	if (strcmp(type, "quantity") == 0) {
		printf("Input the quantity you want to filter by: ");
		fgets(inputString, STRING_LENGTH - 1, stdin);
		cleanBuffer(inputString);
		inputString[strlen(inputString) - 1] = '\0';
		if (strlen(inputString) == 0) {
			printf("Error: Invalid input! You did not enter any characters.\n");
			return;
		}
		helper = &quantity;
		if (!validateString(inputString, strtolWrapped, helper)) {
			printf("Error: Invalid input! The quantity must be a positive integer.\n");
			return;
		}
		serviceFilter(ui->serv, &newList, type, helper);
		showArray(newList);
		destroyArray(newList);
		return;
	}
	if (strcmp(type, "price") == 0) {
		printf("Input the price you want to filter by: ");
		fgets(inputString, STRING_LENGTH - 1, stdin);
		cleanBuffer(inputString);
		inputString[strlen(inputString) - 1] = '\0';
		if (strlen(inputString) == 0) {
			printf("Error: Invalid input! You did not enter any characters.\n");
			return;
		}
		helper = &price;
		if (!validateString(inputString, strtodWrapped, helper)) {
			printf("Error: Invalid input! The quantity must be a positive integer.\n");
			return;
		}
		serviceFilter(ui->serv, &newList, type, helper);
		showArray(newList);
		destroyArray(newList);
		return;
	}
	destroyArray(newList);
	printf("Error: Invalid input! Cannot filter by that type.\n");
	return;
}
void showProduct(Product* x) {
	/*
		Function that prints out details of a product
	*/
	printf("\nID of product: %d\n", getUniqueID(x));
	printf("Type of product: %s\n", getType(x));
	printf("Producer of product: %s\n", getProducer(x));
	printf("Model of product: %s\n", getModel(x));
	printf("Price of product: %lf\n", getPrice(x));
	printf("Quantity of product: %d\n\n", getQuantity(x));
}
void showArray(DynamicArray* v) {
	/*
		Function that displays the array in console
	*/
	int size = arraySize(v);
	if (size == 0) {
		printf("There are no products currently stored.\n");
		return;
	}
	for (int i = 0; i < size; i++) {
		showProduct(*accessElement(v, i));
	}
}