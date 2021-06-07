#ifndef SERIAL_TV_H
#define SERIAL_TV_H
#include <string>
class SerialTV
{
private:
	std::string numeSerie, gen;
	int anAparitie, numarEpisoade, numarEpisoadeVizionate;
public:
	/*
	* Constructor pentru SerialeTV
	* nume - std::string care descrie numele serialului
	* g - std::string care descrie genul serialului
	* an - intreg care descrie anul aparitiei serialului
	* nrEp - intreg care descrie numarul total de episoade al serialului
	* nrEpViz - intreg care descrie numarul de episoade vizionate al serialului
	*/
	SerialTV(std::string nume, std::string g, int an, int nrEp, int nrEpViz) : numeSerie{ nume }, gen{ g }, anAparitie{ an }, 
		numarEpisoade{ nrEp }, numarEpisoadeVizionate{ nrEpViz } {}

	/*
	* Gaseste numele serialului
	* Returneaza referinta la string ce descrie numele
	*/
	const std::string& getNume() const {
		return numeSerie;
	}

	/*
	* Gaseste genul serialului
	* Returneaza referinta la string ce descrie genul serialului
	*/
	const std::string& getGen() const {
		return gen;
	}

	/*
	* Gaseste anul serialului
	* Returneaza un intreg ce descrie anul aparitiei serialului
	*/
	int getAnAparitie() const {
		return anAparitie;
	}

	/*
	* Gaseste numarul de episoade serialului
	* Returneaza un intreg ce descrie numarul de episoade serialului
	*/
	int getNumarEpisoade() const {
		return numarEpisoade;
	}

	/*
	* Gaseste numarul de episoade vizionate ale serialului
	* Returneaza un intreg ce descrie numarul de episoade vizionate ale serialului
	*/
	int getNumarEpisoadeVizionate() const {
		return numarEpisoadeVizionate;
	}
};
#endif

