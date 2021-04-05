#include "Service.h"

const std::string ServiceException::invalidSortingCriteria{ "The comparison criteria is not valid!" };
const std::string ServiceException::invalidFilteringCriteria{ "The condition criteria is not valid!" };
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
const Vector<Drug>& Service::getDrugs() const noexcept {
	return repo.getDrugs();
}
size_t Service::getSize() const noexcept {
	return repo.getSize();
}

Vector<Drug> Service::sort(const std::string& criteria) const {
	Vector<Drug> copy{ getDrugs() };
	if (criteria == "name") {
		copy.sort([](const Drug& first, const Drug& second)noexcept {
			return first.getName() <= second.getName();
			});
		return copy;
	}
	else if (criteria == "producer") {
		copy.sort([](const Drug& first, const Drug& second)noexcept {
			return first.getProducer() < second.getProducer();
			});
		return copy;
	}
	else if (criteria == "substance&price") {
		copy.sort([](const Drug& first, const Drug& second) noexcept {
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

Vector<Drug> Service::filterPrice(double condition) const {
	Vector<Drug> copy{ getDrugs() };
	copy.filter([=](const Drug& element)noexcept {
		return (element.getPrice() - condition <0.00001 && element.getPrice() - condition >-0.00001);
		});
	return copy;
}

Vector<Drug> Service::filterSubstance(const std::string& condition) const {
	Vector<Drug> copy{ getDrugs() };
	copy.filter([=](const Drug& element)noexcept {
		return element.getSubstance() == condition;
		});
	return copy;
}