#include "Service.h"

void Service::addDrug(int id, const std::string& name, const std::string& producer, const std::string& activeSubstance, double price) const {
	Drug newDrug{ id, name, producer, activeSubstance, price };
	try {
		repo.addDrug(newDrug);
	}
	catch (const RepoException& re) {
		throw ServiceException{ re.getMessage() };
	}
}
void Service::deleteDrug(int id) const {
	try {
		repo.deleteDrug(id);
	}
	catch (const RepoException& re) {
		throw ServiceException{ re.getMessage() };
	}
}
void Service::updateDrug(int id, double newPrice) const {
	try {
		repo.updateDrug(id, newPrice);
	}
	catch (const RepoException& re) {
		throw ServiceException{ re.getMessage() };
	}
}

const Drug& Service::findDrug(int id) const {
	try {
		return repo.searchDrug(id);
	}
	catch (const RepoException& re) {
		throw ServiceException{ re.getMessage() };
	}
}
const std::vector<Drug>& Service::getDrugs() const noexcept {
	return repo.getDrugs();
}
size_t Service::getSize() const noexcept {
	return repo.getSize();
}