#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Repository.h"
#include <stdio.h>
#include "tester.h"
#include "Repository.h"
#include "Controller.h"
#include "UserInterface.h"
#include "DynamicArray.h"
int main()
{
	runTests();
	/*DynamicArray* v = createArray(destroyProduct, copyProduct);
	Repository repo;
	initialiseRepository(&repo, v);
	Service serv;
	serv.repo = &repo;
	UI app;
	app.serv = &serv;
	run(&app);
	destroyArray(v);*/
	_CrtDumpMemoryLeaks();
	return 0;
}