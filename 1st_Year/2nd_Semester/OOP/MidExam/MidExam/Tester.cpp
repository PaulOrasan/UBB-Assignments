#include "Tester.h"
#include "SerialTV.h"
#include "Repository.h"
#include "Service.h"
#include <assert.h>
void Tester::runTests() {
	testDomain();
	testRepository();
	testService();
}

void Tester::testDomain() {
	std::string nume = "abdf", gen = "comedie";
	int an = 2001, nrEp = 10, nrEpV = 5;
	SerialTV serialTest{ nume, gen, an, nrEp, nrEpV };
	assert(serialTest.getNume() == nume);
	assert(serialTest.getGen() == gen);
	assert(serialTest.getAnAparitie() == an);
	assert(serialTest.getNumarEpisoade() == nrEp);
	assert(serialTest.getNumarEpisoadeVizionate() == nrEpV);
}

void Tester::testRepository() {
	std::string nume = "abdf", gen = "comedie";
	int an = 2001, nrEp = 10, nrEpV = 5;
	SerialTV serialTest{ nume, gen, an, nrEp, nrEpV };
	Repository repo;
	assert(repo.getSeriale().size() == 0);
	repo.adaugaSerial(serialTest);
	assert(repo.getSeriale().size() == 1);
}

void Tester::testService() {
	std::string nume = "abdf", gen = "comedie";
	int an = 2001, nrEp = 10, nrEpV = 5;
	Repository repo;
	Service serv{ repo };
	assert(serv.getSeriale().size() == 0);
	serv.adaugaSerial(nume, gen, an, nrEp, nrEpV);
	assert(serv.getSeriale().size() == 1);
}