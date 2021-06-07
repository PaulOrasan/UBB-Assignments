#include "Service.h"

void Service::addTrip(int id, std::string destination, double price) {
	Trip trip{ id, destination, price };
	repo.addTrip(trip);
}

void Service::deleteTrip(int id) {
	repo.deleteTrip(id);
}

void Service::deleteDestinationTrips(const std::string& destination) {
	bool found = false;
	do {
		found = false;
		for (const auto& i : repo.getTrips()) {
			if (i.getDestination() == destination) {
				repo.deleteTrip(i.getID());
				found = true;
				break;
			}
		}
	} while (found == true);
}

void Service::updatePrice(int id, double newPrice) {

}