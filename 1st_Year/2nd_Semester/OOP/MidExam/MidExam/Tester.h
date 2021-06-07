#pragma once
class Tester
{
private:
	/*
	* Functie de test pentru Domeniu
	*/
	void testDomain();

	/*
	* Functie de test pentru Repository
	*/
	void testRepository();

	/*
	* Functie de test pentru Service
	*/
	void testService();
public:
	/*
	* Constructor pentru Tester
	*/
	Tester() {}

	/*
	* Functie care ruleaza toate testele
	*/
	void runTests();
};

