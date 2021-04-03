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
		}
		catch (const Error& e) {
			std::cout << e.getMessage() << '\n';
			continue;
		}
		if (option == "6") {
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
	std::cout << "6. Exit\n";
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
	for (const auto& i : serv.getDrugs()) {
		showDrug(i);
	}
}
void UI::showDrug(const Drug& drug) {
	std::cout << "ID: " << drug.getID() << '\n';
	std::cout << "Name: " << drug.getName() << '\n';
	std::cout << "Producer: " << drug.getProducer() << '\n';
	std::cout << "Active substance: " << drug.getSubstance() << '\n';
	std::cout << "Price: " << drug.getPrice() << '\n';
	std::cout << '\n';
}