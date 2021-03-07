#include "Repository.h"
#include <stdio.h>
#include "tester.h"
#include "Repository.h"
#include "Controller.h"
#include "UserInterface.h"
int main()
{
	//runTests();
	Repository repo;
	initialiseRepository(&repo);
	Service serv;
	serv.repo = &repo;
	UI app;
	app.serv = &serv;
	run(&app);
	return 0;
}