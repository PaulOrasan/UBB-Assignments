#ifndef UI_H
#define UI_H
#include "Controller.h"
#include "ProductEntity.h"
typedef struct {
	Service* serv;
}UI;

void run(UI*);
void showMenu();
void interfaceAddProduct(UI*);
void interfaceUpdateRepository(UI*);
void interfaceDeleteProduct(UI*);
void interfaceShowContent(UI*);
void showProduct(Product*);
#endif