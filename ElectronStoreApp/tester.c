#include <assert.h>
#include "ProductEntity.h"
#include <string.h>
#include "tester.h"
#include "Repository.h"
#include <math.h>
void runTests() {
	/*
		Function that runs all the tests
	*/
	runTestsProductEntity();
	runTestsRepository();
}
void runTestsProductEntity() {
	/*
		Function that tests the Product Entity code
	*/
	Product x;
	int id = 1, quantity = 25;
	char type[] = "laptop", model[] = "tuf", producer[] = "asus";
	double price = 2500.5, epsilon = 0.00001;
	initialiseProduct(&x);
	setUniqueID(&x, id);
	assert(getUniqueID(x) == id);
	setType(&x, type);
	assert(strcmp(getType(x), type) == 0);
	setProducer(&x, producer);
	assert(strcmp(getProducer(x), producer) == 0);
	setModel(&x, model);
	assert(strcmp(getModel(x), model) == 0);
	setPrice(&x, price);
	assert(abs(getPrice(x) - price) <= epsilon);
	setQuantity(&x, quantity);
	assert(getQuantity(x) == quantity);
}
void runTestsRepository() {
	/*
		Function that tests the Repository code
	*/
	Product x;
	int id = 0, quantity = 25;
	char type[] = "laptop", model[] = "tuf", producer[] = "asus";
	double price = 2500.5, epsilon = 0.00001;
	initialiseProduct(&x);
	setUniqueID(&x, id);
	setType(&x, type);
	setProducer(&x, producer);
	setModel(&x, model);
	setPrice(&x, price);
	setQuantity(&x, quantity);
	Repository repo;
	initialiseRepository(&repo);
	assert(addProduct(&repo, x));						// start addProduct feature testing
	assert(size(&repo) == 1);
	assert(getUniqueID(repo.list[0]) == id);
	assert(getQuantity(repo.list[0]) == quantity);
	quantity = 100;
	setQuantity(&x, quantity);
	assert(addProduct(&repo, x) == 0);
	assert(getQuantity(repo.list[0]) == quantity);
	for (int i = 1; i < REPOSITORY_CAPACITY; i++) {
		setUniqueID(&x, i);
		addProduct(&repo, x);
	}
	setUniqueID(&x, -5);
	assert(addProduct(&repo, x) == -1);					// end addProduct feature testing

	updateRepository(&repo, 1, PRICE_UPDATE_CODE, 1.0);	// start updateRepository feature testing
	assert(abs(getPrice(repo.list[1]) - 1.0) <= epsilon);
	updateRepository(&repo, 2, QUANTITY_UPDATE_CODE, 30);
	assert(getQuantity(repo.list[2]) == 30);
	updateRepository(&repo, 3, PRICE_AND_QUANTITY_UPDATE_CODE, 3.75, 23);
	assert(abs(getPrice(repo.list[3]) - 3.75) <= epsilon);
	assert(getQuantity(repo.list[3]) == 23);			// end updateRepository feature testing

	assert(deleteProduct(&repo, 0));					// start deleteProduct feature testing
	assert(size(&repo) == REPOSITORY_CAPACITY - 1);
	assert(deleteProduct(&repo, 0) == 0);				// end deleteProduct feature testing
	
}