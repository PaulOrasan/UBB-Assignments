#ifndef MEMORY_REPOSITORY_H
#define MEMORY_REPOSITORY_H
#include <vector>
#include "Repository.h"
#include "Drug.h"
class MemoryRepository : public Repository
{
	private:
		std::vector<Drug> drugArray;
	public:
		/*
		* implicit constructor for the class Repository
		*/
		MemoryRepository() noexcept {}

		/*
		* Method that adds a new drug product in the repository
		* newDrug - const reference to an object of type Drug which must be added in the repository
		* Throws RepoException if the object already exists in the repository
		*/
		void addDrug(const Drug& newDrug) override;

		/*
		* Method that deletes a drug from the repository
		* id - integer which represents the id of the Drug we want to delete
		* Throws RepoException if the object doesn't exist in the repository
		*/
		virtual void deleteDrug(int id) override;

		/*
		* Method that deletes a drug from the repository
		* id - integer which represents the id of the drug we want to update
		* newPrice - double value of the new price that must be modified
		* Throws RepoException if the object doesn't exist in the repository
		*/
		virtual void updateDrug(int id, double newPrice) override;

		/*
		* Method that finds the drug with a given int
		* id - integer which represents the id of the drug we are searching for
		* Throws RepoException if the object doesn't exist in the repository
		*/
		const Drug& searchDrug(int id) const override;

		/*
		* Method that finds all the drugs stored in the repository
		* id - integer which represents the id of the drug we are searching for
		* Throws RepoException if the object doesn't exist in the repository
		*/
		const std::vector<Drug>& getDrugs() const noexcept override;

		size_t getSize() const noexcept override;

		~MemoryRepository() override {}
};


#endif

