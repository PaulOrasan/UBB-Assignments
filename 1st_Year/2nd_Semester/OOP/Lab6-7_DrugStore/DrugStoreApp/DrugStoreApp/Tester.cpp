#include "Tester.h"
#include "Drug.h"
#include "Validation.h"
#include "Repository.h"
#include "Service.h"
#include <cassert>
#include "vector.h"
void Tester::runTests() {
	domainTester.runTests();
	validationTester.runTests();
	vectorTester.runTests();
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

void Tester::VectorTester::runTests() {
	testAppend();
	testErase();
}

void Tester::VectorTester::testAppend() {
	Vector<int> v, v2;
	constexpr int n{ 4 };
	for (int i = 1; i <= n; i++) {
		v.append(i);
	}
	assert(v.length() == n);
	assert(v2.length() == 0);
	Iterator<int> it{ v };
	for (int i = 1; i <= n; i++) {
		assert(it.getElement() == i);
		it.next();
	}
}
void Tester::VectorTester::testErase() {
	Vector<int> v, v2;
	constexpr int n{ 4 };
	for (int i = 1; i <= n; i++) {
		v.append(i);
	}
	assert(v.length() == n);
	assert(v2.length() == 0);
	Iterator<int> it{ v };
	assert(it.getElement() == 1);
	while (it.valid()) {
		v.erase(it);
	}
	try {
		it.getElement();
	}
	catch (const VectorException& e) {
		assert(e.getMessage() == VectorException::iteratorInvalid);
	}
	try {
		it.next();
	}
	catch (const VectorException& e) {
		assert(e.getMessage() == VectorException::iteratorInvalid);
	}
	try {
		v.erase(it);
	}
	catch (const VectorException& e) {
		assert(e.getMessage() == VectorException::iteratorInvalid);
	}
	const Iterator<int> it2{ v2 };
	try {
		v.erase(it2);
	}
	catch (const VectorException& e) {
		assert(e.getMessage() == VectorException::wrongIterator);
	}
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
}

void Tester::ServiceTester::testServiceAddDrug() {
	Repository repo;
	const Service serv{ repo };
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
	const Service serv{ repo };
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
	const Service serv{ repo };
	constexpr int id = 1;
	const std::string name{ "algocalmin" }, producer{ "terapia" }, activeSubstance{ "acetilnofen" };
	constexpr double price = 25.67;
	Drug drugTest;
	serv.addDrug(id, name, producer, activeSubstance, price);
	serv.updateDrug(id, price + 1);
	//assert(equalDoubles(serv.getDrugs().front().getPrice(), price + 1));
	try {
		serv.updateDrug(id + 1, price);
	}
	catch (const ServiceException& se) {
		assert(se.getMessage() == RepoException::drugDoesntExist);
	}
}

void Tester::ServiceTester::testServiceSearchDrug() {
	Repository repo;
	const Service serv{ repo };
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