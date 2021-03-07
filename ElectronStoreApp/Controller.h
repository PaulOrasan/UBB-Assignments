#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Repository.h"
#include "ProductEntity.h"
typedef struct {
	Repository* repo;
}Service;
int serviceAddProduct(Service*, int, char*, char*, char*, double, int);
int serviceUpdateRepository(Service*, int, double, int);
int serviceDeleteProduct(Service*, int);
int serviceSize(Service*);
void serviceGetAll(Service*, Product*);
#endif