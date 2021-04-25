#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "Drug.h"
#include "Error.h"
#include <vector>
class Repository
{
public:
	Repository() {}
	/*
	* Method that adds a new drug product in the repository
	* newDrug - const reference to an object of type Drug which must be added in the repository
	*/
	virtual void addDrug(const Drug& newDrug) = 0;

	/*
	* Method that deletes a drug from the repository
	* id - integer which represents the id of the Drug we want to delete
	*/
	virtual void deleteDrug(int id) = 0;

	/*
	* Method that deletes a drug from the repository
	* id - integer which represents the id of the drug we want to update
	* newPrice - double value of the new price that must be modified
	*/
	virtual void updateDrug(int id, double newPrice) = 0;

	/*
	* Method that finds the drug with a given int
	* id - integer which represents the id of the drug we are searching for
	*/
	virtual const Drug& searchDrug(int id) const = 0;

	/*
	* Method that finds all the drugs stored in the repository
	* id - integer which represents the id of the drug we are searching for
	*/
	virtual const std::vector<Drug>& getDrugs() const = 0;

	virtual size_t getSize() const = 0;

	virtual ~Repository() {}
};

class RepoException : public Error {
	using Error::Error;
public:
	static const std::string drugExists, drugDoesntExist, fileFail, probabilityException;
};
#endif

