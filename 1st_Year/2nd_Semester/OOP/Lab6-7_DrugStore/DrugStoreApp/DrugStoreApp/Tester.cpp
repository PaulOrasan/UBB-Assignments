#include "Tester.h"
#include "Drug.h"
#include "Validation.h"
#include "Repository.h"
#include "Service.h"
#include <cassert>
#include "vector.h"
#include <algorithm>
#include <iostream>
void Tester::runTests() {
	domainTester.runTests();
	validationTester.runTests();
	repositoryTester.runTests();
	serviceTester.runTests();
}

bool equalDoubles(double a, double b) noexcept{
	constexpr double epsilon = 0.0000001;
	return (a - b<epsilon&& a - b>-epsilon);
}

void Tester::DomainTester::runTests() {
	Tester::DomainTester::testGetterSetter();
}

void Tester::DomainTester::testGetterSetter() {
	constexpr int id = 1;
	const std::string name{ "algocalmin" }, producer{ "terapia" }, activeSubstance{ "acetilnofen" };
	constexpr double price = 25.67;
	Drug drugGetterTest{ id, name, producer, activeSubstance, price };
	assert(drugGetterTest.getID() == id);
	assert(drugGetterTest.getName() == name);
	assert(drugGetterTest.getProducer() == producer);
	assert(drugGetterTest.getSubstance() == activeSubstance);
	assert(equalDoubles(drugGetterTest.getPrice(), price));
	Drug drugSetterTest;
	drugSetterTest.setID(id);
	drugSetterTest.setName(name);
	drugSetterTest.setProducer(producer);
	drugSetterTest.setSubstance(activeSubstance);
	drugSetterTest.setPrice(price);
	assert(drugGetterTest.getID() == id);
	assert(drugSetterTest.getName() == name);
	assert(drugSetterTest.getProducer() == producer);
	assert(drugSetterTest.getSubstance() == activeSubstance);
	assert(equalDoubles(drugSetterTest.getPrice(), price));
	assert(equalPrices(drugGetterTest, drugSetterTest));
	assert(drugGetterTest == drugSetterTest);
	Drug drupCopyTest{ drugGetterTest };
	assert(drugGetterTest == drupCopyTest);
}

void Tester::ValidationTester::runTests() {
	testValidateID();
	testValidatePrice();
}

void Tester::ValidationTester::testValidateID() {
	try {
		Validation::validateID("dsghsfdkja");
	}
	catch(const ValidationException& ve) {
		assert(ve.getMessage() == ValidationException::invalidID);
	}
	try {
		Validation::validateID("437298943a");
	}
	catch (const ValidationException& ve) {
		assert(ve.getMessage() == ValidationException::invalidID);
	}
	try {
		Validation::validateID("3210921.4324982");
	}
	catch (const ValidationException& ve) {
		assert(ve.getMessage() == ValidationException::invalidID);
	}
	try {
		Validation::validateID("   ");
	}
	catch (const ValidationException& ve) {
		assert(ve.getMessage() == ValidationException::invalidID);
	}
	Validation::validateID("12334");
}

void Tester::ValidationTester::testValidatePrice() {
	try {
		Validation::validatePrice("dsghsfdkja");
	}
	catch (const ValidationException& ve) {
		assert(ve.getMessage() == ValidationException::invalidPrice);
	}
	try {
		Validation::validatePrice("437298943a");
	}
	catch (const ValidationException& ve) {
		assert(ve.getMessage() == ValidationException::invalidPrice);
	}
	try {
		Validation::validatePrice("3210.921.43249.82");
	}
	catch (const ValidationException& ve) {
		assert(ve.getMessage() == ValidationException::invalidPrice);
	}
	try {
		Validation::validatePrice("   ");
	}
	catch (const ValidationException& ve) {
		assert(ve.getMessage() == ValidationException::invalidPrice);
	}
	Validation::validatePrice("12334.32413");
}

void Tester::RepositoryTester::runTests() {
	testAddDrug();
	testDeleteDrug();
	testUpdateDrug();
	testSearchDrug();
}
void Tester::RepositoryTester::testAddDrug() {
	Repository repoTest;
	constexpr int id = 1;
	const std::string name{ "algocalmin" }, producer{ "terapia" }, activeSubstance{ "acetilnofen" };
	constexpr double price = 25.67;
	Drug drugTest;
	drugTest.setName(name);
	drugTest.setProducer(producer);
	drugTest.setSubstance(activeSubstance);
	drugTest.setPrice(price);
	for (int i = id; i < id + 5; i++) {
		drugTest.setID(i);
		repoTest.addDrug(drugTest);
	}
	assert(repoTest.getSize() == 5);
	//assert(repoTest.getDrugs().back() == drugTest);
	try {
		repoTest.addDrug(drugTest);
	}
	catch (const RepoException& re) {
		assert(re.getMessage() == RepoException::drugExists);
	}
}
void Tester::RepositoryTester::testDeleteDrug() {
	Repository repoTest;
	constexpr int id = 1;
	const std::string name{ "algocalmin" }, producer{ "terapia" }, activeSubstance{ "acetilnofen" };
	constexpr double price = 25.67;
	Drug drugTest;
	drugTest.setName(name);
	drugTest.setProducer(producer);
	drugTest.setSubstance(activeSubstance);
	drugTest.setPrice(price);
	for (int i = id; i < id + 5; i++) {
		drugTest.setID(i);
		repoTest.addDrug(drugTest);
	}
	try {
		repoTest.deleteDrug(id + 100);
	}
	catch (const RepoException& re) {
		assert(re.getMessage() == RepoException::drugDoesntExist);
	}
	for (int i = id; i < id + 5; i++) {
		repoTest.deleteDrug(i);
	}
	assert(repoTest.getSize() == 0);
	try {
		repoTest.deleteDrug(id + 100);
	}
	catch (const RepoException& re) {
		assert(re.getMessage() == RepoException::drugDoesntExist);
	}
}

void Tester::RepositoryTester::testUpdateDrug() {
	Repository repoTest;
	constexpr int id = 1;
	const std::string name{ "algocalmin" }, producer{ "terapia" }, activeSubstance{ "acetilnofen" };
	constexpr double price = 25.67;
	Drug drugTest{ id, name, producer, activeSubstance, price };
	repoTest.addDrug(drugTest);
	repoTest.updateDrug(id, price + 1);
	//assert(equalDoubles(repoTest.getDrugs().front().getPrice(), price + 1));
	try {
		repoTest.updateDrug(id + 1, price + 2);
	}
	catch (const RepoException& re) {
		assert(re.getMessage() == RepoException::drugDoesntExist);
	}
}
void Tester::RepositoryTester::testSearchDrug() {
	Repository repoTest;
	constexpr int id = 1;
	const std::string name{ "algocalmin" }, producer{ "terapia" }, activeSubstance{ "acetilnofen" };
	constexpr double price = 25.67;
	Drug drugTest{ id, name, producer, activeSubstance, price };
	repoTest.addDrug(drugTest);
	const Drug& ref = repoTest.searchDrug(id);
	assert(ref == drugTest);
	try {
		repoTest.searchDrug(id + 1);
	}
	catch (const RepoException& re) {
		assert(re.getMessage() == RepoException::drugDoesntExist);
	}
}
void Tester::ServiceTester::runTests() {
	testServiceAddDrug();
	testServiceDeleteDrug();
	testServiceUpdateDrug();
	testServiceSearchDrug();
	testServiceSort();
	testServiceFilter();
	testAddDrugsRecipe();
	testGenerateRecipe();
	testCountProducer();
}

void Tester::ServiceTester::testServiceAddDrug() {
	Repository repo;
	Prescription pres;
	const Service serv{ repo, pres };
	constexpr int id = 1;
	const std::string name{ "algocalmin" }, producer{ "terapia" }, activeSubstance{ "acetilnofen" };
	constexpr double price = 25.67;
	Drug drugTest;
	drugTest.setID(id);
	serv.addDrug(id, name, producer, activeSubstance, price);
	assert(serv.getSize() == 1);
	//assert(serv.getDrugs().front() == drugTest);
	try {
		serv.addDrug(id, name, producer, activeSubstance, price);
	}
	catch (const ServiceException& se) {
		assert(se.getMessage() == RepoException::drugExists);
	}
}

void Tester::ServiceTester::testServiceDeleteDrug() {
	Repository repo;
	Prescription pres;
	const Service serv{ repo, pres };
	constexpr int id = 1;
	const std::string name{ "algocalmin" }, producer{ "terapia" }, activeSubstance{ "acetilnofen" };
	constexpr double price = 25.67;
	Drug drugTest;
	serv.addDrug(id, name, producer, activeSubstance, price);
	serv.deleteDrug(id);
	assert(serv.getSize() == 0);
	try {
		serv.deleteDrug(id);
	}
	catch (const ServiceException& se) {
		assert(se.getMessage() == RepoException::drugDoesntExist);
	}
}

void Tester::ServiceTester::testServiceUpdateDrug() {
	Repository repo;
	Prescription pres;
	const Service serv{ repo, pres };
	constexpr int id = 1;
	const std::string name{ "algocalmin" }, producer{ "terapia" }, activeSubstance{ "acetilnofen" };
	constexpr double price = 25.67;
	Drug drugTest;
	serv.addDrug(id, name, producer, activeSubstance, price);
	serv.updateDrug(id, price + 1);
	//assert(equalDoubles(serv.getDrugs().front().getPrice(), price + 1));
	serv.getDrugs();
	try {
		serv.updateDrug(id + 1, price);
	}
	catch (const ServiceException& se) {
		assert(se.getMessage() == RepoException::drugDoesntExist);
	}
}

void Tester::ServiceTester::testServiceSearchDrug() {
	Repository repo;
	Prescription pres;
	const Service serv{ repo, pres };
	constexpr int id = 1;
	const std::string name{ "algocalmin" }, producer{ "terapia" }, activeSubstance{ "acetilnofen" };
	constexpr double price = 25.67;
	Drug drugTest;
	drugTest.setID(id);
	serv.addDrug(id, name, producer, activeSubstance, price);
	assert(serv.findDrug(id) == drugTest);
	try {
		serv.findDrug(id + 1);
	}
	catch (const ServiceException& se) {
		assert(se.getMessage() == RepoException::drugDoesntExist);
	}
}

void Tester::ServiceTester::testServiceSort() {
	Repository repo;
	Prescription pres;
	const Service serv{ repo, pres };
	serv.addDrug(1, "algocalmin", "terapia", "acetilnofenil", 1.23);
	serv.addDrug(2, "paracetamol", "bayer", "acetilnofenil", 2.35);
	serv.addDrug(3, "mizocalm", "paranus", "hotil", 0.29);
	std::vector<Drug> sorted1{ serv.sort("name") };
	std::vector<std::string> elems1;
	assert(std::is_sorted(elems1.begin(), elems1.end()));
	std::vector<Drug> sorted2{ serv.sort("producer") };
	std::vector<std::string> elems2;
	assert(std::is_sorted(elems2.begin(), elems2.end()));
	std::vector<Drug>sorted3{ serv.sort("substance&price") };
	assert(sorted3.size() == 3);
	try {
		std::vector<Drug>sorted4{ serv.sort("fdsaf") };
	}
	catch (const ServiceException& e) {
		assert(e.getMessage() == ServiceException::invalidSortingCriteria);
	}
}

void Tester::ServiceTester::testServiceFilter() {
	Repository repo;
	Prescription pres;
	const Service serv{ repo, pres };
	serv.addDrug(1, "algocalmin", "terapia", "acetilnofen", 1);
	serv.addDrug(2, "paracetamol", "bayer", "acetilnofenil", 1);
	serv.addDrug(3, "mezocalm", "paranus", "acetilnofenil", 0.99);
	std::vector<Drug> v{ serv.filterPrice(1) }, k{ serv.filterSubstance("acetilnofenil") };
	assert(v.size() == 2);
	assert(k.size() == 2);
}

void Tester::ServiceTester::testAddDrugsRecipe() {
	Repository repo;
	Prescription pres;
	const Service serv{ repo, pres };
	serv.addDrug(1, "algocalmin", "terapia", "acetilnofen", 1);
	serv.addDrug(2, "paracetamol", "bayer", "acetilnofenil", 1);
	serv.addDrug(3, "mezocalm", "paranus", "acetilnofenil", 0.99);
	serv.addDrugRecipe("paracetamol");
	try {
		serv.addDrugRecipe("paracetamol");
	}
	catch (const ServiceException& e) {
		assert(e.getMessage() == ServiceException::drugsAlreadyAddedOrNotFound);
	}
	assert(serv.getRecipe().size() == 1);
	serv.deleteDrug(2);
	assert(serv.getRecipe().size() == 0);
	serv.addDrug(2, "paracetamol", "bayer", "acetilnofenil", 1);
	serv.addDrug(4, "paracetamol", "bayer", "acetilnofenil", 1);
	serv.addDrugRecipe("paracetamol");
	serv.addDrugRecipe("paracetamol");
	assert(serv.getRecipe().size() == 2);
	serv.emptyRecipe();
	assert(serv.getRecipe().size() == 0);
}

void Tester::ServiceTester::testGenerateRecipe() {
	Repository repo;
	Prescription pres;
	const Service serv{ repo, pres };
	serv.addDrug(1, "algocalmin", "terapia", "acetilnofen", 1);
	serv.addDrug(2, "paracetamol", "bayer", "acetilnofenil", 1);
	serv.addDrug(3, "mezocalm", "paranus", "acetilnofenil", 0.99);
	serv.addDrug(4, "algocalmin", "paranus", "acetilnofenil", 0.99);
	serv.addDrug(5, "mezocalm", "paranus", "acetilnofenil", 0.99);
	try {
		serv.generateRecipe(15);
	}
	catch (const ServiceException& e) {
		assert(e.getMessage() == ServiceException::notEnoughDrugs);
	}
	serv.generateRecipe(4);
	assert(serv.getRecipe().size() == 4);
}

void Tester::ServiceTester::testCountProducer() {
	Repository repo;
	Prescription pres;
	const Service serv{ repo, pres };
	serv.addDrug(1, "algocalmin", "terapia", "acetilnofen", 1);
	serv.addDrug(2, "paracetamol", "bayer", "acetilnofenil", 1);
	serv.addDrug(3, "mezocalm", "paranus", "acetilnofenil", 0.99);
	serv.addDrug(4, "algocalmin", "paranus", "acetilnofenil", 0.99);
	serv.addDrug(5, "mezocalm", "paranus", "acetilnofenil", 0.99);
	auto dict = serv.countProducer();
	assert(dict.size() == 3);
	assert(dict["terapia"].getCount() == 1);
	assert(dict["bayer"].getCount() == 1);
	assert(dict["paranus"].getCount() == 3);
}