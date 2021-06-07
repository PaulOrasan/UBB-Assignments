#ifndef SERVICE_H
#define SERVICE_H
#include "Repository.h"
#include <string>
class Service
{
private:
	Repository& repo;
public:
	/*
	* Constructor pentru Service
	*/
	Service(Repository& repository) : repo{ repository } {}

	/*
	* Adauga un serial 
	* numeSerie - std::string care descrie numele
	* gen - std::string care descrie genul
	* anAparitie - intreg care descrie anul
	* numarEpisoade - intreg care descrie numarul de episoade
	* numarEpisoadeVizionate - intreg care descrie numarul de episoade vizionate 
	*/
	void adaugaSerial(const std::string& numeSerie, const std::string& gen, int anAparitie, int numarEpisoade, int numarEpisoadeVizionate);

	/*
	* Gaseste lista de seriale 
	* Returneaza referinta constanta catre un vector unde sunt inregistrate toate serialele
	*/
	const std::vector<SerialTV>& getSeriale() {
		return repo.getSeriale();
	}
};
#endif

