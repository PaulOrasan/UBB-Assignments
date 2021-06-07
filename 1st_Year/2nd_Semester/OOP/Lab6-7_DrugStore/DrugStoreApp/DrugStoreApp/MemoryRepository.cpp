#include "MemoryRepository.h"
#include <algorithm>
#include "Repository.h"

void MemoryRepository::addDrug(const Drug& newDrug) {
	if (find(drugArray.begin(), drugArray.end(), newDrug) != drugArray.end()) {
		throw RepoException{ RepoException::drugExists };
	}
	drugArray.push_back(newDrug);
}
void MemoryRepository::deleteDrug(int id) {
	Drug aux;
	aux.setID(id);
	auto it = find(drugArray.begin(), drugArray.end(), aux);
	if (it == drugArray.end()) {
		throw RepoException{ RepoException::drugDoesntExist };
	}
	drugArray.erase(it);
}
void MemoryRepository::updateDrug(int id, double newPrice) {
	Drug aux;
	aux.setID(id);
	auto it = find(drugArray.begin(), drugArray.end(), aux);
	if (it == drugArray.end()) {
		throw RepoException{ RepoException::drugDoesntExist };
	}
	it->setPrice(newPrice);
}

const Drug& MemoryRepository::searchDrug(int id) const {
	Drug aux;
	aux.setID(id);
	auto it = std::find(drugArray.begin(), drugArray.end(), aux);
	if (it == drugArray.end())
		throw RepoException{ RepoException::drugDoesntExist };
	return *it;
}

const std::vector<Drug>& MemoryRepository::getDrugs() const noexcept {
	return drugArray;
}
size_t MemoryRepository::getSize() const noexcept {
	return drugArray.size();
}