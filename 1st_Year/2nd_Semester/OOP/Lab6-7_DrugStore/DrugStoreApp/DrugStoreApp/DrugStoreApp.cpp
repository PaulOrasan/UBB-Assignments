#include "Tester.h"
#include "Repository.h"
#include "Service.h"
#include "UI.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Tester tester;
	tester.runTests();
	Repository repo;
	const Service serv{ repo };
	UI ui{ serv };
	ui.runApp();
	return 0;
}