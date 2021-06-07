#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <vector>
#include <string>
#include "Trip.h"
class Repository
{
private:
	std::vector<Trip> trips;
	std::string file;

	void load();
	void store();
public:
	Repository(const std::string& filename);

	void addTrip(const Trip& newTrip);

	void deleteTrip(int deletionID);

	const std::vector<Trip>& getTrips() const {
		return trips;
	}
};

class RepositoryError {
private:
	std::string message;
public:
	RepositoryError(const std::string& msg) : message{ msg } {}
	const std::string& getMessage() const {
		return message;
	}
};
#endif
