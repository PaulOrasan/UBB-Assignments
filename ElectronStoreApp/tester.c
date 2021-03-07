#include <assert.h>
#include "ProductEntity.h"
#include <string.h>
#include "tester.h"
#include "Repository.h"
#include "Controller.h"
#include "Validation.h"
#include <math.h>
void runTests() {
	/*
		Function that runs all the tests
	*/
	runTestsProductEntity();
	runTestsRepository();
	runTestsService();
	runTestsValidation();
}
void runTestsProductEntity() {
	/*
		Function that tests the Product Entity code
	*/
	Product x;
	int id = 1, quantity = 25;
	char type[] = "laptop", model[] = "tuf", producer[] = "asus";
	double price = 2500.5, epsilon = 0.00001;
	initialiseProduct(&x, 0, "", "", "", 0.0, 0);
	setUniqueID(&x, id);
	assert(getUniqueID(&x) == id);
	setType(&x, type);
	assert(strcmp(getType(&x), type) == 0);
	setProducer(&x, producer);
	assert(strcmp(getProducer(&x), producer) == 0);
	setModel(&x, model);
	assert(strcmp(getModel(&x), model) == 0);
	setPrice(&x, price);
	assert(abs(getPrice(&x) - price) <= epsilon);
	setQuantity(&x, quantity);
	assert(getQuantity(&x) == quantity);
	Product y = x;
	assert(equality(&x, &y));
	setUniqueID(&y, 23);
	assert(equality(&x, &y) == 0);
}
void runTestsRepository() {
	/*
		Function that tests the Repository code
	*/
	Product x;
	int id = 0, quantity = 25;
	char type[] = "laptop", model[] = "tuf", producer[] = "asus";
	double price = 2500.5, epsilon = 0.00001;
	initialiseProduct(&x, id, type, producer, model, price, quantity);
	Repository repo;
	initialiseRepository(&repo);
	assert(addProduct(&repo, x));						// start addProduct feature testing
	assert(size(&repo) == 1);
	assert(getUniqueID(&repo.list[0]) == id);
	assert(getQuantity(&repo.list[0]) == quantity);
	quantity = 100;
	setQuantity(&x, quantity);
	assert(addProduct(&repo, x) == 0);
	assert(getQuantity(&repo.list[0]) == quantity);
	for (int i = 1; i < REPOSITORY_CAPACITY; i++) {
		setUniqueID(&x, i);
		addProduct(&repo, x);
	}
	setUniqueID(&x, -5);
	assert(addProduct(&repo, x) == -1);					// end addProduct feature testing

	updateRepository(&repo, 1, PRICE_UPDATE_CODE, 1.0);	// start updateRepository feature testing
	assert(abs(getPrice(&repo.list[1]) - 1.0) <= epsilon);
	updateRepository(&repo, 2, QUANTITY_UPDATE_CODE, 30);
	assert(getQuantity(&repo.list[2]) == 30);
	updateRepository(&repo, 3, PRICE_AND_QUANTITY_UPDATE_CODE, 3.75, 23);
	assert(abs(getPrice(&repo.list[3]) - 3.75) <= epsilon);
	assert(getQuantity(&repo.list[3]) == 23);			// end updateRepository feature testing

	assert(deleteProduct(&repo, 0));					// start deleteProduct feature testing
	assert(size(&repo) == REPOSITORY_CAPACITY - 1);
	assert(deleteProduct(&repo, 0) == 0);				// end deleteProduct feature testing
	
	Product newList[REPOSITORY_CAPACITY];
	getAll(&repo, newList);
	for (int index = 0; index < repo.numberOfItems; index++) {
		assert(equality(&repo.list[index], &newList[index]));
	}
}

void runTestsService() {
	/*
		Function that tests the implementation of the Service component
	*/
	Repository repo;
	initialiseRepository(&repo);
	Service serv;
	serv.repo = &repo;
	Product x;
	int id = 0, quantity = 25;
	char type[] = "laptop", model[] = "tuf", producer[] = "asus";
	double price = 2500.5, epsilon = 0.00001;
	initialiseProduct(&x, id, type, producer, model, price, quantity);		
	assert(serviceAddProduct(&serv, id, type, producer, model, price, quantity) == 1);
	assert(serviceAddProduct(&serv, id, type, producer, model, price, quantity) == 0);				// testing add and size feature
	assert(serviceAddProduct(&serv, id+1, type, producer, model, price, quantity) == 1);
	for (int i = 2; i < REPOSITORY_CAPACITY; i++) {
		assert(serviceAddProduct(&serv, i, type, producer, model, price, quantity) == 1);
	}
	assert(serviceSize(&serv) == REPOSITORY_CAPACITY);
	assert(serviceAddProduct(&serv, REPOSITORY_CAPACITY + 1, type, producer, model, price, quantity) == -1);

	assert(serviceUpdateRepository(&serv, 0, 0.5, 2) == 1);											// testing update feature
	assert(getPrice(&serv.repo->list[0]) - 0.5 < epsilon && getPrice(&serv.repo->list[0]) - 0.5 > -epsilon);
	assert(getQuantity(&serv.repo->list[0]) == 2);
	assert(serviceUpdateRepository(&serv, 0, 0.25, -1) == 1);
	assert(getPrice(&serv.repo->list[0]) - 0.25 < epsilon && getPrice(&serv.repo->list[0]) - 0.25 > -epsilon);
	assert(serviceUpdateRepository(&serv, 0, -1.0, 3) == 1);
	assert(getQuantity(&serv.repo->list[0]) == 3);
	assert(serviceUpdateRepository(&serv, REPOSITORY_CAPACITY + 1, 2.3, 5) == 0);
	assert(serviceUpdateRepository(&serv, 0, -2.0, -5) == 0);

	assert(serviceDeleteProduct(&serv, 0) == 1);													// testing delete feature
	assert(serviceDeleteProduct(&serv, 0) == 0);
	Product newList[REPOSITORY_CAPACITY];
	serviceGetAll(&serv, newList);
	for (int i = 0; i < REPOSITORY_CAPACITY - 1; i++) {
		setUniqueID(&x, i + 1);
		assert(equality(&serv.repo->list[i], &x));
	}
}

void runTestsValidation() {
	char s[100];
	void* number;
	int result, numberI;
	double numberD;
	double epsilon = 0.0001;
	number = &numberI;
	strcpy(s, "123");
	result = validateString(s, strtolWrapped, number);
	assert(result == 1);
	assert(numberI == 123);
	strcpy(s, "dfsjksfd");
	result = validateString(s, strtolWrapped, number);
	assert(result == 0);
	strcpy(s, "4325skhkfg");
	result = validateString(s, strtolWrapped, number);
	assert(result == 0);
	strcpy(s, "149.45");
	number = &numberD;
	result = validateString(s, strtodWrapped, number);
	assert(result == 1);
	assert(numberD - 149.45 < epsilon && numberD - 149.45 > -epsilon);
	strcpy(s, "fdsafsdf");
	result = validateString(s, strtodWrapped, number);
	assert(result == 0);
	strcpy(s, "0.3249fsdhhf");
	result = validateString(s, strtodWrapped, number);
	assert(result == 0);
	
	

}