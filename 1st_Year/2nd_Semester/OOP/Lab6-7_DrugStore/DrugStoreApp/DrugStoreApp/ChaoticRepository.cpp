#include "ChaoticRepository.h"
#include <random>
/*
	* Method that adds a new drug product in the repository
	* newDrug - const reference to an object of type Drug which must be added in the repository
	*/
void ChaoticRepository::addDrug(const Drug& newDrug) {
	throwProbabilityException();
	if (drugDictionary.find(newDrug.getID()) != drugDictionary.end()) {
		throw RepoException{ RepoException::drugExists };
	}
	drugDictionary[newDrug.getID()] = newDrug;
	drugArray.push_back(newDrug);
}

/*
* Method that deletes a drug from the repository
* id - integer which represents the id of the Drug we want to delete
*/
void ChaoticRepository::deleteDrug(int id) {
	throwProbabilityException();
	if (drugDictionary.find(id) == drugDictionary.end()) {
		throw RepoException{ RepoException::drugDoesntExist };
	}
	drugDictionary.erase(id);
	auto it = find_if(drugArray.begin(), drugArray.end(), [&id](const Drug& drug) {
		return (drug.getID() == id);
		});
	if (it != drugArray.end()) {
		drugArray.erase(it);
	}
}

/*
* Method that deletes a drug from the repository
* id - integer which represents the id of the drug we want to update
* newPrice - double value of the new price that must be modified
*/
void ChaoticRepository::updateDrug(int id, double newPrice) {
	throwProbabilityException();
	if (drugDictionary.find(id) == drugDictionary.end()) {
		throw RepoException{ RepoException::drugDoesntExist };
	}
	drugDictionary[id].setPrice(newPrice);
	auto it = find_if(drugArray.begin(), drugArray.end(), [&id](const Drug& drug) {
		return (drug.getID() == id);
		});
	if (it != drugArray.end()) {
		it->setPrice(newPrice);
	}
}

/*
* Method that finds the drug with a given int
* id - integer which represents the id of the drug we are searching for
*/
const Drug& ChaoticRepository::searchDrug(int id) const {
	throwProbabilityException();
	if (drugDictionary.find(id) == drugDictionary.end()) {
		throw RepoException{ RepoException::drugDoesntExist };
	}
	return drugDictionary.find(id)->second;
}

/*
* Method that finds all the drugs stored in the repository
* id - integer which represents the id of the drug we are searching for
*/
const std::vector<Drug>& ChaoticRepository::getDrugs() const {
	throwProbabilityException();
	return drugArray;
}

size_t ChaoticRepository::getSize() const {
	throwProbabilityException();
	return drugArray.size();
}

void ChaoticRepository::throwProbabilityException() const {
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_real_distribution<double> distr(0, 1);
	double luck = distr(eng);
	if (luck - probability < 0)
		throw RepoException{ RepoException::probabilityException };
}