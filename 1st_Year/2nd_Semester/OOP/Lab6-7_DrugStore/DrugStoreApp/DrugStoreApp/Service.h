#ifndef SERVICE_H
#define SERVICE_H
#include "Repository.h"
#include <string>
#include <vector>
#include "Error.h"

class Service
{
	private:
		Repository& repo;
	public:
		/*
		* constructor for the Service class
		*/
		Service(Repository& repository) noexcept : repo{ repository } {}

		/*
		* Method for adding a new Drug into the repository
		* id - integer which represents the id of the new drug
		* name - constant reference to a string which represents the name of the drug
		* producer - constant reference to a string which represents the name of the producer of the drug
		* activeSubstance - constant reference to a string which represents the active substance of the drug
		* price - double which represents the price of the drug
		* Throws ServiceException if a drug with the same ID already exists in the repository
		*/
		void addDrug(int id, const std::string& name, const std::string& producer, const std::string& activeSubstance, double price) const;

		/*
		* Method for deleting a Drug from the repository
		* id - integer which represents the id of the new drug
		* Throws ServiceException if a drug with the same ID doesn't exist in the repository
		*/
		void deleteDrug(int id) const;

		/*
		* Method for deleting a Drug from the repository
		* id - integer which represents the id of the new drug
		* newPrice - double which represents the new price that will be modified
		* Throws ServiceException if a drug with the same ID doesn't exist in the repository
		*/
		void updateDrug(int id, double newPrice) const;

		/*
		* Method for finding a Drug from the repository
		* id - integer which represents the id of the new drug
		* Throws ServiceException if a drug with the same ID doesn't exist in the repository
		* Returns a constant reference to the Drug object if it exists in the repository
		*/
		const Drug& findDrug(int id) const;

		/*
		* Method for getting all the drugs from the repository
		* Returns a constant reference to the list of drugs from the repository
		*/
		const Vector<Drug>& getDrugs() const noexcept;

		/*
		* Method for finding the number of elements from the repository
		* Returns an integer which represents the number of elements from the repository
		*/
		size_t getSize() const noexcept;
};

class ServiceException : public Error {
	using Error::Error;
};
#endif
