#include "Service.h"

void Service::adaugaSerial(const std::string& numeSerie, const std::string& gen, int anAparitie, int numarEpisoade, int numarEpisoadeVizionate) {
	SerialTV serial{ numeSerie, gen, anAparitie, numarEpisoade, numarEpisoadeVizionate };
	repo.adaugaSerial(serial);
}