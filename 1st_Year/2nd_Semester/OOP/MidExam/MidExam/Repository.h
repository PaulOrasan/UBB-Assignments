#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "SerialTV.h"
#include <vector>
class Repository
{
private:
	std::vector<SerialTV> lista;
public:
	/*
	* Constructor pentru Repository
	*/
	Repository() {}


	/*
	* Adauga un serial in repository 
	* serial - referinta constanta la un obiect de tip SerialTV care descrie serialul
	*/
	void adaugaSerial(const SerialTV& serial);

	/*
	* Gaseste lista de seriale stocata in repo
	* Returneaza o referinta la un std::vector care contine serialele
	*/
	const std::vector<SerialTV>& getSeriale() const {
		return lista;
	}
};
#endif
