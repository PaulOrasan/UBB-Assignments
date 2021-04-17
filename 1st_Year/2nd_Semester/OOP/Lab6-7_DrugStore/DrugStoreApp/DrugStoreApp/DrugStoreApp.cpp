#include "Tester.h"
#include "Repository.h"
#include "Service.h"
#include "UI.h"
#include "Prescription.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Tester tester;
	tester.runTests();
	Repository repo;
	Prescription pres;
	const Service serv{ repo, pres };
	UI ui{ serv };
	ui.runApp();
	return 0;
}