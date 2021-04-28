#include "Service.h"
#include <algorithm>
#include <iterator>
#include <fstream>
#include "UndoAdd.h"
#include "UndoDelete.h"
#include "UndoUpdate.h"
#include <random>

const std::string ServiceException::invalidSortingCriteria{ "The comparison criteria is not valid!" };
const std::string ServiceException::invalidFilteringCriteria{ "The condition criteria is not valid!" };
const std::string ServiceException::drugsAlreadyAddedOrNotFound{ "All drugs with that name are already added on the recipe or no drug was found!" };
const std::string ServiceException::notEnoughDrugs{ "Not enough drugs stored to generate that recipe!" };
const std::string ServiceException::fileFail{ "The file cannot be opened!" };
const std::string ServiceException::undoFail{ "Can't do undo anymore!" };

void Service::addDrug(int id, const std::string& name, const std::string& producer, const std::string& activeSubstance, double price) {
	Drug newDrug{ id, name, producer, activeSubstance, price };
	try {
		repo.addDrug(newDrug);
		undoList.push(std::make_unique<UndoAdd>(repo, newDrug));
	}
	catch (const RepoException& re) {
		throw ServiceException{ re.getMessage() };
	}
}
void Service::deleteDrug(int id) {
	try {
		const Drug& drug{ repo.searchDrug(id) };
		undoList.push(std::make_unique<UndoDelete>(repo, drug));
	}
	catch (...) {

	}
	try {
		repo.deleteDrug(id);
		prescription.deleteDrug(id);
	}
	catch (const RepoException& re) {
		throw ServiceException{ re.getMessage() };
	}
}
void Service::updateDrug(int id, double newPrice) {
	try {
		const Drug& drug{ repo.searchDrug(id) };
		undoList.push(std::make_unique<UndoUpdate>(repo, drug));
	}
	catch (...) {

	}
	try {
		repo.updateDrug(id, newPrice);
		prescription.deleteDrug(id);
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
const std::vector<Drug>& Service::getDrugs() const {
	return repo.getDrugs();
}
size_t Service::getSize() const {
	return repo.getSize();
}

std::vector<Drug> Service::sort(const std::string& criteria) const {
	std::vector<Drug> copy{ getDrugs() };
	if (criteria == "name") {
		std::sort(copy.begin(), copy.end(), [](const Drug& first, const Drug& second)noexcept {
			return first.getName() <= second.getName();
			});
		return copy;
	}
	else if (criteria == "producer") {
		std::sort(copy.begin(), copy.end(), [](const Drug& first, const Drug& second)noexcept {
			return first.getProducer() < second.getProducer();
			});
		return copy;
	}
	else if (criteria == "substance&price") {
		std::sort(copy.begin(), copy.end(), [](const Drug& first, const Drug& second) noexcept {
			if (first.getSubstance() == second.getSubstance()) {
				return first.getPrice() < second.getPrice();
			}
			return first.getSubstance() < second.getSubstance();
		});
		return copy;
	}
	else {
		throw ServiceException{ ServiceException::invalidSortingCriteria };
	}
}

std::vector<Drug> Service::filterPrice(double condition) const {
	std::vector<Drug> copy{ getDrugs() };
	auto it = remove_if(copy.begin(), copy.end(), [=](const Drug& element)noexcept {
		return (element.getPrice() - condition <0.00001 && element.getPrice() - condition >-0.00001);
		});
	copy.assign(it, copy.end());
	return copy;
}

std::vector<Drug> Service::filterSubstance(const std::string& condition) const {
	std::vector<Drug> copy{ getDrugs() };
	auto it = remove_if(copy.begin(), copy.end(), [=](const Drug& element)noexcept {
		return element.getSubstance() == condition;
		});
	copy.assign(it, copy.end());
	return copy;
}

void Service::addDrugRecipe(const std::string& name) const {
	const std::vector<Drug>& copy{ getDrugs() };
	Prescription& pres{ prescription };
	auto it = std::find_if(copy.begin(), copy.end(), [&pres, name](const Drug& drug) {return drug.getName() == name && !pres.findDrug(drug.getID()); });
	if (it == copy.end()) {
		throw ServiceException{ ServiceException::drugsAlreadyAddedOrNotFound };
	}
	else {
		prescription.addDrug(*it);
	}
}

const std::vector<Drug>& Service::getRecipe() const noexcept {
	return prescription.getAll();
}

void Service::emptyRecipe() const noexcept {
	prescription.emptyDrugs();
}

void Service::generateRecipe(int number) const {
	if (number > getSize())
		throw ServiceException{ ServiceException::notEnoughDrugs };
	prescription.emptyDrugs();
	std::vector<Drug> copy{ getDrugs() }; 
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(copy.begin(), copy.end(), g);
	Prescription& pres = prescription;
	for_each(copy.begin(), copy.end(), [&pres, &number](const Drug& drug) {
		if (pres.getAll().size() < number) {
			pres.addDrug(drug);
		}
		});
}

std::map<std::string, ProducerCount> Service::countProducer() const {
	std::map<std::string, ProducerCount> dict;
	const std::vector<Drug>& vec{ getDrugs() };
	for (const auto& i : vec) {
		if (dict.find(i.getProducer()) == dict.end()) {
			dict[i.getProducer()] = ProducerCount(i.getProducer());
		}
		else {
			dict[i.getProducer()].incrementCount();
		}
	}
	return dict;
}

void Service::servExport(const std::string& file) const {
	std::ofstream fout;
	fout.open(file, std::ios::out | std::ios::trunc);
	if (!fout.is_open())
		throw ServiceException{ ServiceException::fileFail };
	prescription.exportList(fout);
	fout.close();
}

void Service::undo() {
	if (undoList.size() == 0) {
		throw ServiceException{ ServiceException::undoFail };
	}
	undoList.top()->doUndo();
	undoList.pop();
}