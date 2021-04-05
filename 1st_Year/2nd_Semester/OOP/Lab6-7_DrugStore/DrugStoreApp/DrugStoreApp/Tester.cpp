#include "Tester.h"
#include "Drug.h"
#include "Validation.h"
#include "Repository.h"
#include "Service.h"
#include <cassert>
#include "vector.h"
#include <algorithm>
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
	testSort();
	testFilter();
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
	try {
		it.setElement(3);
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
void Tester::VectorTester::testSort() {
	Vector<int> v;
	constexpr int n{ 4 };
	for (int i = 1; i <= n; i++) {
		v.append(i);
	}
	Vector<int>v2{ v };
	assert(v.length() == v2.length());
	Iterator<int> it1{ v }, it2{ v2 };
	while (it1.valid()) {
		assert(it1.getElement() == it2.getElement());
		it1.next();
		it2.next();
	}
	v.sort([](const int& first, const int& second) noexcept {return first >= second; });
	Iterator<int>it3{ v };
	for (int i = n; i >= 1; i--) {
		assert(it3.getElement() == i);
		it3.next();
	}
}
void Tester::VectorTester::testFilter() {
	Vector<int> v;
	constexpr int n{ 4 };
	for (int i = 1; i <= n; i++) {
		v.append(i);
	}
	v.filter([](const int& element) noexcept {return element > 1; });
	assert(v.length() == n - 1);
	Iterator<int>it{ v };
	for (int i = 2; i <= n; i++) {
		assert(it.getElement() == i);
		it.next();
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
	testServiceSort();
	testServiceFilter();
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

void Tester::ServiceTester::testServiceSort() {
	Repository repo;
	const Service serv{ repo };
	serv.addDrug(1, "algocalmin", "terapia", "acetilnofenil", 1.23);
	serv.addDrug(2, "paracetamol", "bayer", "acetilnofenil", 2.35);
	serv.addDrug(3, "mizocalm", "paranus", "hotil", 0.29);
	Vector<Drug> sorted1{ serv.sort("name") };
	std::vector<std::string> elems1;
	Iterator<Drug> it1{ sorted1 };
	while (it1.valid()) {
		elems1.push_back(it1.getElement().getName());
		it1.next();
	}
	assert(std::is_sorted(elems1.begin(), elems1.end()));
	Vector<Drug> sorted2{ serv.sort("producer") };
	std::vector<std::string> elems2;
	Iterator<Drug> it2{ sorted2 };
	while (it2.valid()) {
		elems2.push_back(it2.getElement().getProducer());
		it2.next();
	}
	assert(std::is_sorted(elems2.begin(), elems2.end()));
	Vector<Drug>sorted3{ serv.sort("substance&price") };
	assert(sorted3.length() == 3);
	try {
		Vector<Drug>sorted4{ serv.sort("fdsaf") };
	}
	catch (const ServiceException& e) {
		assert(e.getMessage() == ServiceException::invalidSortingCriteria);
	}
}

void Tester::ServiceTester::testServiceFilter() {
	Repository repo;
	const Service serv{ repo };
	serv.addDrug(1, "algocalmin", "terapia", "acetilnofen", 1);
	serv.addDrug(2, "paracetamol", "bayer", "acetilnofenil", 1);
	serv.addDrug(3, "mezocalm", "paranus", "acetilnofenil", 0.99);
	Vector<Drug> v{ serv.filterPrice(1) }, k{ serv.filterSubstance("acetilnofenil") };
	Iterator<Drug> it1{ v }, it2{ k };
	assert(v.length() == 2);
	assert(equalDoubles(it1.getElement().getPrice(), 1));
	it1.next();
	assert(equalDoubles(it1.getElement().getPrice(), 1));
	assert(k.length() == 2);
	assert(it2.getElement().getSubstance() == "acetilnofenil");
	it2.next();
	assert(it2.getElement().getSubstance() == "acetilnofenil");
}