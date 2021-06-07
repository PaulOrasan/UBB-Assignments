#include "Repository.h"
#include <fstream>
Repository::Repository(const std::string& filename) {
	file = filename;
	load();
}

void Repository::load() {
	std::ifstream fin(file);
	if (!fin.is_open()) {
		throw RepositoryError{ "Cannot open file!" };
	}
	std::string id, destination, price;
	while (getline(fin, id)) {
		getline(fin, destination);
		getline(fin, price);
		Trip trip{ stoi(id), destination, stod(price) };
		trips.push_back(trip);
	}
	fin.close();
}

void Repository::store() {
	std::ofstream fout(file);
	for (const auto& el : trips) {
		fout << el.getID() << '\n' << el.getDestination() << '\n' << el.getPrice() << '\n';
	}
	fout.close();
}

void Repository::addTrip(const Trip& trip) {
	for (const auto& element : trips) {
		if (element.getID() == trip.getID())
			throw RepositoryError{ "The trip already exists!" };
	}
	trips.push_back(trip);
	store();
}

void Repository::deleteTrip(int id) {
	for (std::vector<Trip>::iterator it = trips.begin(); it != trips.end(); it++) {
		if (it->getID() == id) {
			trips.erase(it);
			store();
			return;
		}
	}
	throw RepositoryError{ "The trip doesn't exist!" };
}