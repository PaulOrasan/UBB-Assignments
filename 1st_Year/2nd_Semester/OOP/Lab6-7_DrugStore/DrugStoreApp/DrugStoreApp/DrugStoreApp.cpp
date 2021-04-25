#include "Tester.h"
#include "MemoryRepository.h"
#include "Service.h"
#include "UI.h"
#include "Prescription.h"
#include "FileRepository.h"
#include "ChaoticRepository.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Tester tester;
	tester.runTests();
	/*//Repository repo;
	Prescription pres;
	FileRepository repo { "database.txt" };
	//ChaoticRepository repo{ 0.3 };
	Service serv{ repo, pres };
	UI ui{ serv };
	ui.runApp();*/
	return 0;
}