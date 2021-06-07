#ifndef TRIP_H
#define TRIP_H
#include <string>
class Trip
{
private:
	int id;
	std::string destination;
	double price;
public:
	Trip(int initID, std::string initDestination, double initPrice) : id{ initID }, destination{ initDestination }, price{ initPrice } {}

	/// <summary>
	/// Finds the id of a trip
	/// </summary>
	/// <returns>an interger which represents the id of the trip</returns>
	int getID() const {
		return id;
	}

	/// <summary>
	/// Modifies the id of the trip
	/// </summary>
	/// <param name="newID">integer which represents the newID</param>
	void setID(int newID) {
		id = newID;
	}

	/*
	* Finds the destination of the trip
	* Returns a const std::string reference to the destination
	*/
	const std::string& getDestination() const {
		return destination;
	}

	/*
	* Modifies the destination of the trip
	*/
	void setDestination(const std::string& newDestination) {
		destination = newDestination;
	}

	/*
	* Finds the price of the trip
	* Returns a double which represents the price of the destination
	*/
	double getPrice() const {
		return price;
	}
	
	/*
	* Modifies the price of the trip
	*/
	void setPrice(double newPrice) {
		price = newPrice;
	}
};
#endif
