#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H
#include <vector>
#include "Drug.h"
#include <fstream>
#include "Observer.h"
class Prescription : public Observable
{
private:
	std::vector<Drug> prescriptionList;
public:
	/*
	* Implicit constructor
	*/
	Prescription() noexcept {}
	/*
	* Method that adds a new drug in the recipe
	* newDrug - const reference to the drug needed to be added
	*/
	void addDrug(const Drug& newDrug);
	/*
	* Method that finds if a drug is in the recipe based on the id
	* Returns True if the id was found and false otherwise
	*/
	bool findDrug(int id) const;
	/*
	* Method that deletes a drug from the recipe based on the id if it exists
	*/
	void deleteDrug(int id);
	/*
	* Method that deletes all drug from the recipe based on the id if it exists
	*/
	void emptyDrugs() noexcept;
	/*
	* Method that gets all drug from the recipe based on the id if it exists
	*/
	const std::vector<Drug>& getAll() noexcept;

	/*
	* Method that writes all the drugs to an output file
	* fout - ofstream reference to a valid opened file
	*/
	void exportList(std::ofstream& fout) const;
};
#endif

