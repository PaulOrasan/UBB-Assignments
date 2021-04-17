#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <vector>
#include "Drug.h"
#include "Error.h"
class Repository
{
	private:
		std::vector<Drug> drugArray;
	public:
		/*
		* implicit constructor for the class Repository
		*/
		Repository() noexcept {}

		/*
		* Method that adds a new drug product in the repository
		* newDrug - const reference to an object of type Drug which must be added in the repository
		* Throws RepoException if the object already exists in the repository
		*/
		void addDrug(const Drug& newDrug);

		/*
		* Method that deletes a drug from the repository
		* id - integer which represents the id of the Drug we want to delete
		* Throws RepoException if the object doesn't exist in the repository
		*/
		void deleteDrug(int id);

		/*
		* Method that deletes a drug from the repository
		* id - integer which represents the id of the drug we want to update
		* newPrice - double value of the new price that must be modified
		* Throws RepoException if the object doesn't exist in the repository
		*/
		void updateDrug(int id, double newPrice);

		/*
		* Method that finds the drug with a given int
		* id - integer which represents the id of the drug we are searching for
		* Throws RepoException if the object doesn't exist in the repository
		*/
		const Drug& searchDrug(int id) const;

		/*
		* Method that finds all the drugs stored in the repository
		* id - integer which represents the id of the drug we are searching for
		* Throws RepoException if the object doesn't exist in the repository
		*/
		const std::vector<Drug>& getDrugs() const noexcept;

		size_t getSize() const noexcept;
};

class RepoException : public Error {
	using Error::Error;
	public:
		static const std::string drugExists, drugDoesntExist;
};
#endif

