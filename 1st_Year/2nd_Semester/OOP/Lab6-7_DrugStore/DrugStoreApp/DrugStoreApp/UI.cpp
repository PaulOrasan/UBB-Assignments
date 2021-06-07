#include "UI.h"
#include <iostream>
#include "Validation.h"
#include "Service.h"
#include <string>
#include "Error.h"
void UI::runApp() {
	std::string option;
	while (true) {
		showMenu();
		std::getline(std::cin, option);
		std::cout << '\n';
		try {
			if (option == "1") {
				uiAddDrug();
				continue;
			}
			if (option == "2") {
				uiShowAllDrugs();
				continue;
			}
			if (option == "3") {
				uiDeleteDrug();
				continue;
			}
			if (option == "4") {
				uiUpdateDrug();
				continue;
			}
			if (option == "5") {
				uiFindDrug();
				continue;
			}
			if (option == "6") {
				uiSortDrugs();
				continue;
			}
			if (option == "7") {
				uiFilterDrugs();
				continue;
			}
			if (option == "8") {
				uiAddPrescription();
				continue;
			}
			if (option == "9") {
				uiCheckPrescription();
				continue;
			}
			if (option == "10") {
				uiEmptyPrescription();
				continue;
			}
			if (option == "11") {
				uiGeneratePrescription();
				continue;
			}
			if (option == "12") {
				uiCountProducer();
				continue;
			}
			if (option == "13") {
				uiExportRecipe();
				continue;
			}
			if (option == "14") {
				uiUndo();
				continue;
			}
		}
		catch (const Error& e) {
			std::cout << e.getMessage() << '\n';
			continue;
		}
		if (option == "15") {
			break;
		}
		std::cout << "Error: your input is invalid.\n";
	}
}
void UI::showMenu() {
	std::cout << "\n1. Add new drug\n";
	std::cout << "2. Show all existing drugs\n";
	std::cout << "3. Delete existing drug\n";
	std::cout << "4. Modify existing drug\n";
	std::cout << "5. Find existing drug\n";
	std::cout << "6. Sort drugs\n";
	std::cout << "7. Filter drugs\n";
	std::cout << "8. Add drug in prescription\n";
	std::cout << "9. Check prescription\n";
	std::cout << "10. Empty prescription\n";
	std::cout << "11. Generate prescription\n";
	std::cout << "12. Count drugs by producer\n";
	std::cout << "13. Export recipe to file\n";
	std::cout << "14. Undo last add/delete/update\n";
	std::cout << "15. Exit\n";
	std::cout << "Your input: ";
}
void UI::uiAddDrug() {
	std::string id, name, producer, substance, price;
	std::cout << "Please input the new drug's ID: ";
	std::getline(std::cin, id);
	Validation::validateID(id);
	std::cout << "Please input the new drug's name: ";
	std::getline(std::cin, name);
	std::cout << "Please input the new drug's producer: ";
	std::getline(std::cin, producer);
	std::cout << "Please input the new drug's substance: ";
	std::getline(std::cin, substance);
	std::cout << "Please input the new drug's price: ";
	std::getline(std::cin, price);
	Validation::validatePrice(price);
	serv.addDrug(stoi(id), name, producer, substance, stod(price));
}
void UI::uiDeleteDrug() {
	std::string id;
	std::cout << "Please input the ID of the drug you want to delete: ";
	std::getline(std::cin, id);
	Validation::validateID(id);
	serv.deleteDrug(stoi(id));
}
void UI::uiUpdateDrug() {
	std::string id, price;
	std::cout << "Please input the ID of the drug you want to update: ";
	std::getline(std::cin, id);
	Validation::validateID(id);
	std::cout << "Please input the new price of the drug: ";
	std::getline(std::cin, price);
	Validation::validatePrice(price);
	serv.updateDrug(stoi(id), stod(price));
}
void UI::uiFindDrug() {
	std::string id;
	std::cout << "Please input the ID of the drug you want to find: ";
	std::getline(std::cin, id);
	Validation::validateID(id);
	showDrug(serv.findDrug(stoi(id)));
}
void UI::uiShowAllDrugs() {
	if (serv.getSize() == 0) {
		std::cout << "There are no drugs currently stored in the database!\n";
		return;
	}
	std::cout << "The list of drugs:\n";
	showDrugs(serv.getDrugs());
}
void UI::showDrugs(const std::vector<Drug>& v) {
	for (const auto& it : v)
		showDrug(it);
}
void UI::showDrug(const Drug& drug) {
	std::cout << "ID: " << drug.getID() << '\n';
	std::cout << "Name: " << drug.getName() << '\n';
	std::cout << "Producer: " << drug.getProducer() << '\n';
	std::cout << "Active substance: " << drug.getSubstance() << '\n';
	std::cout << "Price: " << drug.getPrice() << '\n';
	std::cout << '\n';
}

void UI::uiSortDrugs() {
	std::string input;
	std::cout << "Please input the criteria used for sorting (either name, producer, substance&price): ";
	std::getline(std::cin, input);
	std::vector<Drug> v{ serv.sort(input) };
	std::cout << "The sorted drugs by " << input << " are:\n";
	showDrugs(v);
}

void UI::uiFilterDrugs() {
	std::string inputCriteria, inputCondition;
	std::cout<< "Please input the criteria used for filtering (either price or substance): ";
	std::getline(std::cin, inputCriteria);
	std::cout << "Please input the condition used for filtering: ";
	std::getline(std::cin, inputCondition);
	if (inputCriteria == "price") {
		Validation::validatePrice(inputCondition);
		std::vector<Drug> v{ serv.filterPrice(stod(inputCondition))};
		std::cout << "The filtered drugs by " << inputCriteria << " are:\n";
		showDrugs(v);
	}
	else if (inputCriteria == "substance") {
		std::vector<Drug> v{ serv.filterSubstance(inputCondition) };
		std::cout << "The filtered drugs by " << inputCriteria << " are:\n";
		showDrugs(v);
	}
	else {
		throw ServiceException{ ServiceException::invalidFilteringCriteria };
	}
}
void UI::uiAddPrescription() {
	std::cout << "Please input the name of the drug you want to add: ";
	std::string name;
	std::getline(std::cin, name);
	serv.addDrugRecipe(name);
}
void UI::uiCheckPrescription() {
	const std::vector<Drug>& copy{ serv.getRecipe() };
	showDrugs(copy);
}
void UI::uiEmptyPrescription() noexcept {
	serv.emptyRecipe();
}
void UI::uiGeneratePrescription() {
	std::cout << "Please input the number of drugs you want on your prescription: ";
	std::string number;
	std::getline(std::cin, number);
	Validation::validateID(number);
	serv.generateRecipe(stoi(number));
}
void UI::uiCountProducer() {
	auto dict = serv.countProducer();
	for (const auto& i : dict) {
		std::cout << "For producer " << i.first << " we found " << i.second.getCount() << " drugs\n";
	}
}

void UI::uiExportRecipe() {
	std::cout << "Please input the name of the file: ";
	std::string file;
	std::getline(std::cin, file);
	serv.servExport(file);
}

void UI::uiUndo() {
	serv.undo();
}