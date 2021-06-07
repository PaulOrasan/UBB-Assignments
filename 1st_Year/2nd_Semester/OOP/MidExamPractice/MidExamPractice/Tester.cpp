#include "Tester.h"
#include "Trip.h"
#include <assert.h>
void Tester::runTests() {
	domainTester.runTests();
}

void Tester::DomainTester::runTests() {
	testGettersSetters();
}

void Tester::DomainTester::testGettersSetters() {
	int id{ 1 };
	std::string destination{ "abcd" };
	double price{ 23.47 }, epsilon{ 0.00001 };
	Trip tripTest{ id, destination, price };
	assert(tripTest.getID() == id);
	assert(tripTest.getDestination() == destination);
	assert(tripTest.getPrice() - price < epsilon&& tripTest.getPrice() - price > -epsilon);
	tripTest.setID(id + 1);
	assert(tripTest.getID() == id + 1);
	tripTest.setDestination(destination);
	tripTest.setPrice(price + 1);
	assert(tripTest.getPrice() == price + 1);
}