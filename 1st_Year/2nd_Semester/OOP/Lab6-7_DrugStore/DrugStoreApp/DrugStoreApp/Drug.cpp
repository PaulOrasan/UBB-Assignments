#include "Drug.h"
#include <iostream>

Drug::Drug(const Drug& copy) {
	this->id = copy.getID();
	this->name = copy.getName();
	this->producer = copy.getProducer();
	this->activeSubstance = copy.getSubstance();
	this->price = copy.getPrice();
	std::cout << "Copy constructor called\n";
}
bool equalPrices(const Drug& a, const Drug& b) noexcept {
	const double priceA = a.getPrice(), priceB = b.getPrice();
	constexpr double epsilon = 0.000001;
	return ((priceA - priceB) < epsilon && (priceA - priceB) > -epsilon);
}

bool operator==(const Drug& a, const Drug& b) noexcept {
	return a.getID() == b.getID();
}

std::ostream& operator<<(std::ostream& out, const Drug& d) {
	out << d.id << '\n';
	out << d.name << '\n';
	out << d.producer << '\n';
	out << d.activeSubstance << '\n';
	out << d.price << '\n';
	return out;
}