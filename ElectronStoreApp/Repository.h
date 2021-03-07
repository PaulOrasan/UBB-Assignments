#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "Constants.h"
#include "ProductEntity.h"

typedef struct {
	Product list[REPOSITORY_CAPACITY];
	int numberOfItems;
}Repository;
void initialiseRepository(Repository*);
int addProduct(Repository*, Product);
int updateRepository(Repository*, int, int, ...);
int deleteProduct(Repository*, int);
int size(Repository*);
void getAll(Repository*, Product*);
#endif