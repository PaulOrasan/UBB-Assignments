#include "Repository.h"
#include <algorithm>
const std::string RepoException::drugExists{ "Drug already exists!" };
const std::string RepoException::drugDoesntExist{ "Drug doesn't exist!" };
void Repository::addDrug(const Drug& newDrug) {
	if (find(drugArray.begin(), drugArray.end(), newDrug) != drugArray.end()) {
		throw RepoException{ RepoException::drugExists };
	}
	drugArray.push_back(newDrug);
}
void Repository::deleteDrug(int id) {
	Drug aux;
	aux.setID(id);
	auto it = find(drugArray.begin(), drugArray.end(), aux);
	if (it == drugArray.end()) {
		throw RepoException{ RepoException::drugDoesntExist };
	}
	drugArray.erase(it);
}
void Repository::updateDrug(int id, double newPrice) {
	Drug aux;
	aux.setID(id);
	auto it = find(drugArray.begin(), drugArray.end(), aux);
	if (it == drugArray.end()) {
		throw RepoException{ RepoException::drugDoesntExist };
	}
	it->setPrice(newPrice);
}

const Drug& Repository::searchDrug(int id) const {
	/*auto it = find(drugArray.begin(), drugArray.end(), aux);
	if (it == drugArray.end()) {
		throw RepoException{ RepoException::drugDoesntExist };
	}
	return *it;*/
	for (const auto& it : drugArray) {
		if (it.getID() == id)
			return it;
	}
	throw RepoException{ RepoException::drugDoesntExist };
}

const std::vector<Drug>& Repository::getDrugs() const noexcept {
	return drugArray;
}
size_t Repository::getSize() const noexcept {
	return drugArray.size();
}