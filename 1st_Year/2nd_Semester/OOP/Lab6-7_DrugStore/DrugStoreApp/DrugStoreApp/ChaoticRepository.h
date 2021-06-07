#ifndef CHAOTIC_REPOSITORY_H
#define CHAOTIC_REPOSITORY_H
#include "Repository.h"
#include "Drug.h"
#include <vector>
#include <map>
class ChaoticRepository : public Repository
{
private:
	std::map<int, Drug> drugDictionary;
	std::vector<Drug> drugArray;
	double probability;
	void throwProbabilityException() const;
public:
	ChaoticRepository(double p) : probability{ p } {}
	/*
	* Method that adds a new drug product in the repository
	* newDrug - const reference to an object of type Drug which must be added in the repository
	*/
	void addDrug(const Drug& newDrug) override;

	/*
	* Method that deletes a drug from the repository
	* id - integer which represents the id of the Drug we want to delete
	*/
	void deleteDrug(int id) override;

	/*
	* Method that deletes a drug from the repository
	* id - integer which represents the id of the drug we want to update
	* newPrice - double value of the new price that must be modified
	*/
	void updateDrug(int id, double newPrice) override;

	/*
	* Method that finds the drug with a given int
	* id - integer which represents the id of the drug we are searching for
	*/
	const Drug& searchDrug(int id) const override;

	/*
	* Method that finds all the drugs stored in the repository
	* id - integer which represents the id of the drug we are searching for
	*/
	const std::vector<Drug>& getDrugs() const override;

	size_t getSize() const override;

	~ChaoticRepository() override {}
};
#endif

