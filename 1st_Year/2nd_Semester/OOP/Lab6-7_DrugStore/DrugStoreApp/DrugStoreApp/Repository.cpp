#include "Repository.h"

const std::string RepoException::drugExists{ "Drug already exists!" };
const std::string RepoException::drugDoesntExist{ "Drug doesn't exist!" };

void Repository::addDrug(const Drug& newDrug) {
	drugArray.append(newDrug);
}
void Repository::deleteDrug(int id) {
	Iterator<Drug> it{drugArray};
	while (it.valid()) {
		if (it.getElement().getID() == id) {
			drugArray.erase(it);
			return;
		}
		it.next();
	}
	throw RepoException{ RepoException::drugDoesntExist };
}
void Repository::updateDrug(int id, double newPrice) {
	Iterator<Drug> it{ drugArray };
	while (it.valid()) {
		if (it.getElement().getID() == id) {
			Drug newDrug = it.getElement();
			newDrug.setPrice(newPrice);
			it.setElement(newDrug);
			return;
		}
		it.next();
	}
	throw RepoException{ RepoException::drugDoesntExist };
}

const Drug& Repository::searchDrug(int id) const {
	/*auto it = find(drugArray.begin(), drugArray.end(), aux);
	if (it == drugArray.end()) {
		throw RepoException{ RepoException::drugDoesntExist };
	}
	return *it;*/
	Iterator<Drug> it{ drugArray };
	while (it.valid()) {
		if (it.getElement().getID() == id) {
			return it.getElement();
		}
		it.next();
	}
	throw RepoException{ RepoException::drugDoesntExist };
}

const Vector<Drug>& Repository::getDrugs() const noexcept {
	return drugArray;
}
size_t Repository::getSize() const noexcept {
	return drugArray.length();
}