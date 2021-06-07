#ifndef SERVICE_H
#define SERVICE_H
#include "Repository.h"
class Service
{
private:
	Repository& repo;
public:
	Service(Repository& repository) :repo{ repository } {}
	void addTrip(int id, std::string destination, double price);
	void deleteTrip(int id);
	const std::vector<Trip>& getTrips() const {
		return repo.getTrips();
	}
	void deleteDestinationTrips(const std::string& destination);
	void updatePrice(int id, double newPrice);
};
#endif
