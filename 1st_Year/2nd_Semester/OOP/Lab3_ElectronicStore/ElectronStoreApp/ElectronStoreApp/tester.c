#include <assert.h>
#include "ProductEntity.h"
#include <string.h>
#include "tester.h"
#include "Repository.h"
#include "Controller.h"
#include "Validation.h"
#include <math.h>
#include "DynamicArray.h"
void runTests() {
	/*
		Function that runs all the tests
	*/
	runTestsProductEntity();
	runTestsDynamicArray();
	runTestsRepository();
	runTestsService();
	runTestsValidation();
}
void runTestsProductEntity() {
	/*
		Function that tests the Product Entity code
	*/
	Product* x;
	int id = 1, quantity = 25;
	char type[] = "laptop", model[] = "tuf", producer[] = "asus";
	double price = 2500.5, epsilon = 0.00001;
	x = createProduct(0, "", "", "", 0.0, 0);
	setUniqueID(x, id);
	assert(getUniqueID(x) == id);
	setType(x, type);
	assert(strcmp(getType(x), type) == 0);
	setProducer(x, producer);
	assert(strcmp(getProducer(x), producer) == 0);
	setModel(x, model);
	assert(strcmp(getModel(x), model) == 0);
	setPrice(x, price);
	assert(getPrice(x) - price<epsilon && getPrice(x) - price>-epsilon);
	setQuantity(x, quantity);
	assert(getQuantity(x) == quantity);
	Product *y = copyProduct(x);
	assert(equality(x, y));
	setUniqueID(y, 23);
	assert(equality(x, y) == 0);

	assert(filterProductProducer(x, producer) == 1);
	assert(filterProductProducer(x, type) == 0);
	assert(filterProductPrice(x, &price) == 1);
	assert(filterProductPrice(x, &epsilon) == 0);
	assert(filterProductQuantity(x, &quantity) == 1);
	assert(filterProductQuantity(x, &id) == 0);

	assert(compareProductQuantityIncreasing(x, y) == 0);
	assert(compareProductQuantityDecreasing(x, y) == 0);
	setQuantity(y, quantity + 1);
	assert(compareProductQuantityIncreasing(x, y) == 1);
	assert(compareProductQuantityIncreasing(y, x) == -1);
	assert(compareProductQuantityDecreasing(x, y) == -1);
	assert(compareProductQuantityDecreasing(y, x) == 1);

	assert(compareProductPriceIncreasing(x, y) == 0);
	assert(compareProductPriceDecreasing(x, y) == 0);
	setPrice(y, price + 1);
	assert(compareProductPriceIncreasing(x, y) == 1);
	assert(compareProductPriceIncreasing(y, x) == -1);
	assert(compareProductPriceDecreasing(x, y) == -1);
	assert(compareProductPriceDecreasing(y, x) == 1);
	destroyProduct(x);
	destroyProduct(y);
}
void runTestsRepository() {
	/*
		Function that tests the Repository code
	*/
	Product *x;
	int id = 0, quantity = 25;
	char type[] = "laptop", model[] = "tuf", producer[] = "asus";
	double price = 2500.5, epsilon = 0.00001;
	x = createProduct(id, type, producer, model, price, quantity);
	DynamicArray* v = createArray(destroyProduct, copyProduct);
	Repository repo;
	initialiseRepository(&repo, v);
	assert(addProduct(&repo, x));						// start addProduct feature testing
	assert(size(&repo) == 1);
	assert(getUniqueID(*accessElement(repo.list, 0)) == id);
	assert(getQuantity(*accessElement(repo.list, 0)) == quantity);
	quantity = 100;
	setQuantity(x, quantity);
	assert(addProduct(&repo, x) == 0);
	assert(getQuantity(*accessElement(repo.list, 0)) == quantity);
	for (int i = 1; i < REPOSITORY_CAPACITY; i++) {
		setUniqueID(x, i);
		addProduct(&repo, x);
	}
	setUniqueID(x, -5);
														// end addProduct feature testing

	updateRepository(&repo, 1, PRICE_UPDATE_CODE, 1.0);	// start updateRepository feature testing
	assert(getPrice(*accessElement(repo.list, 1)) - 1.0 <= epsilon && getPrice(*accessElement(repo.list, 1)) - 1.0 >=-epsilon);
	updateRepository(&repo, 2, QUANTITY_UPDATE_CODE, 30);
	assert(getQuantity(*accessElement(repo.list, 2)) == 30);
	updateRepository(&repo, 3, PRICE_AND_QUANTITY_UPDATE_CODE, 3.75, 23);
	assert(getPrice(*accessElement(repo.list, 3)) - 3.75 <= epsilon && getPrice(*accessElement(repo.list, 3)) - 3.75 >= -epsilon);
	assert(getQuantity(*accessElement(repo.list, 3)) == 23);		
	assert(updateRepository(&repo, -2342, 2, 2) == 0);		// end updateRepository feature testing

	assert(deleteProduct(&repo, 0));					// start deleteProduct feature testing
	assert(deleteProduct(&repo, 0) == 0);				// end deleteProduct feature testing
	
	DynamicArray* newList = getAll(&repo);
	for (int index = 0; index < repo.numberOfItems; index++) {
		assert(equality(*accessElement(repo.list, index), *accessElement(newList, index)));
	}
	destroyProduct(x);
	destroyArray(repo.list);
	destroyArray(newList);
}

void runTestsService() {
	/*
		Function that tests the implementation of the Service component
	*/
	DynamicArray* v = createArray(destroyProduct, copyProduct);
	Repository repo;
	initialiseRepository(&repo, v);
	Service serv;
	serv.repo = &repo;
	Product* x;
	int id = 0, quantity = 25;
	char type[] = "laptop", model[] = "tuf", producer[] = "asus";
	double price = 2500.5, epsilon = 0.00001;
	x = createProduct(id, type, producer, model, price, quantity);		
	assert(serviceAddProduct(&serv, id, type, producer, model, price, quantity) == 1);
	assert(serviceAddProduct(&serv, id, type, producer, model, price, quantity) == 0);				// testing add and size feature
	assert(serviceAddProduct(&serv, id+1, type, producer, model, price, quantity) == 1);
	for (int i = 2; i < REPOSITORY_CAPACITY; i++) {
		assert(serviceAddProduct(&serv, i, type, producer, model, price, quantity) == 1);
	}
	assert(serviceSize(&serv) == REPOSITORY_CAPACITY);

	assert(serviceUpdateRepository(&serv, 0, 0.5, 2) == 1);											// testing update feature
	assert(getPrice(*accessElement(serv.repo->list,0)) - 0.5 < epsilon && getPrice(*accessElement(serv.repo->list, 0)) - 0.5 > -epsilon);
	assert(getQuantity(*accessElement(serv.repo->list, 0)) == 2);
	assert(serviceUpdateRepository(&serv, 0, 0.25, -1) == 1);
	assert(getPrice(*accessElement(serv.repo->list, 0)) - 0.25 < epsilon && getPrice(*accessElement(serv.repo->list, 0)) - 0.25 > -epsilon);
	assert(serviceUpdateRepository(&serv, 0, -1.0, 3) == 1);
	assert(getQuantity(*accessElement(serv.repo->list, 0)) == 3);
	assert(serviceUpdateRepository(&serv, REPOSITORY_CAPACITY + 1, 2.3, 5) == 0);
	assert(serviceUpdateRepository(&serv, 0, -2.0, -5) == 0);

	assert(serviceDeleteProduct(&serv, 0) == 1);													// testing delete feature
	assert(serviceDeleteProduct(&serv, 0) == 0);
	DynamicArray* newList = serviceGetAll(&serv);
	for (int i = 0; i < REPOSITORY_CAPACITY - 1; i++) {
		setUniqueID(x, i + 1);
		assert(equality(*accessElement(serv.repo->list, i), x));
	}
	destroyProduct(x);
	destroyArray(repo.list);
	destroyArray(newList);

	v = createArray(destroyProduct, copyProduct);
	initialiseRepository(&repo, v);
	serviceAddProduct(&serv, id, type, producer, model, price, quantity);
	serviceAddProduct(&serv, id+1, type, producer, model, price+1, quantity+1);
	serviceAddProduct(&serv, id+2, type, type, model, price+2, quantity+2);

	serviceSort(&serv, &newList, "quantity", "decreasing");
	
	assert(getQuantity(*accessElement(newList, 0)) > getQuantity(*accessElement(newList, 1)));
	assert(getQuantity(*accessElement(newList, 1)) > getQuantity(*accessElement(newList, 2)));
	destroyArray(newList);

	serviceSort(&serv, &newList, "quantity", "increasing");
	assert(getQuantity(*accessElement(newList, 0)) < getQuantity(*accessElement(newList, 1)));
	assert(getQuantity(*accessElement(newList, 1)) < getQuantity(*accessElement(newList, 2)));
	destroyArray(newList);

	serviceSort(&serv, &newList, "price", "increasing");
	
	assert(getPrice(*accessElement(newList, 0)) < getPrice(*accessElement(newList, 1)));
	assert(getPrice(*accessElement(newList, 1)) < getPrice(*accessElement(newList, 2)));
	destroyArray(newList);

	serviceSort(&serv, &newList, "price", "decreasing");
	assert(getPrice(*accessElement(newList, 0)) > getPrice(*accessElement(newList, 1)));
	assert(getPrice(*accessElement(newList, 1)) > getPrice(*accessElement(newList, 2)));
	assert(serviceSort(&serv, &newList, "Fdsafd", "afdsa") == 0);
	destroyArray(newList);

	serviceFilter(&serv, &newList, "producer", producer);
	assert(arraySize(newList) == 2);
	destroyArray(newList);

	serviceFilter(&serv, &newList, "quantity", &quantity);
	assert(arraySize(newList) == 1);
	destroyArray(newList);

	serviceFilter(&serv, &newList, "price", &price);
	assert(arraySize(newList) == 1);
	destroyArray(newList);
	assert(serviceFilter(&serv, &newList, "fdsafdas", &quantity) == 0);
	destroyArray(newList);
	destroyArray(v);

}

void runTestsValidation() {
	/*
		Function that tests the implementation of the validation feature
	*/
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
void runTestsDynamicArray() {
	/*
		Function that tests the implementation of the DynamicArray
	*/
	DynamicArray* v = createArray(destroyProduct, copyProduct);
	assert(arraySize(v) == 0);
	Product *x;
	int id = 0, quantity = 25, idTest;
	char type[] = "laptop", model[] = "tuf", producer[] = "asus";
	double price = 2500.5;
	x = createProduct(id, type, producer, model, price, quantity);
	appendArray(v, x);
	assert(arraySize(v) == 1);
	assert(equality(*accessElement(v, 0), x));
	assert(accessElement(v, -5) == NULL);
	idTest = 1;
	assert(searchElement(v, searchById, &idTest) == NULL);
	idTest = 0;
	assert(searchElement(v, searchById, &idTest) != NULL);
	destroyProduct(x);
	x = createProduct(id, type, producer, model, price, quantity);
	appendArray(v, x);
	assert(v->capacity == ARRAY_CAPACITY);
	destroyProduct(x);
	x = createProduct(id, type, producer, model, price, quantity);
	appendArray(v, x);
	assert(v->capacity == 2 * ARRAY_CAPACITY);
	deleteElement(v, 0);
	assert(arraySize(v) == 2);
	deleteElement(v, -5);
	assert(arraySize(v) == 2);
	destroyArray(v);
	v = createArray(destroyProduct, copyProduct);
	appendArray(v, x);
	destroyProduct(x);
	x = createProduct(id, type, producer, model, price, quantity+1);
	appendArray(v, x);
	destroyProduct(x);
	x = createProduct(id, type, producer, model, price, quantity + 2);
	appendArray(v, x);
	destroyProduct(x);
	sort(v, compareProductQuantityDecreasing);
	assert(getQuantity(*accessElement(v, 0)) > getQuantity(*accessElement(v, 1)));
	assert(getQuantity(*accessElement(v, 1)) > getQuantity(*accessElement(v, 2)));
	setProducer(*accessElement(v, 1), type);
	assert(arraySize(v) == 3);
	filter(v, filterProductProducer, producer);
	assert(arraySize(v) == 2);
	destroyArray(v);
}