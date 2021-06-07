#ifndef SERVICE_H
#define SERVICE_H
#include "MemoryRepository.h"
#include "Repository.h"
#include <string>
#include <vector>
#include "Error.h"
#include "Prescription.h"
#include <map>
#include "ProducerCount.h"
#include "UndoAction.h"
#include <memory>
#include <stack>
class Service
{
	private:
		Repository& repo;
		Prescription& prescription;
		std::stack<std::unique_ptr<UndoAction>> undoList;
	public:
		/*
		* constructor for the Service class
		*/
		Service(Repository& repository, Prescription& pres) noexcept : repo{ repository }, prescription{ pres } {}

		/*
		* Method for adding a new Drug into the repository
		* id - integer which represents the id of the new drug
		* name - constant reference to a string which represents the name of the drug
		* producer - constant reference to a string which represents the name of the producer of the drug
		* activeSubstance - constant reference to a string which represents the active substance of the drug
		* price - double which represents the price of the drug
		* Throws ServiceException if a drug with the same ID already exists in the repository
		*/
		void addDrug(int id, const std::string& name, const std::string& producer, const std::string& activeSubstance, double price);

		/*
		* Method for deleting a Drug from the repository
		* id - integer which represents the id of the new drug
		* Throws ServiceException if a drug with the same ID doesn't exist in the repository
		*/
		void deleteDrug(int id);

		/*
		* Method for deleting a Drug from the repository
		* id - integer which represents the id of the new drug
		* newPrice - double which represents the new price that will be modified
		* Throws ServiceException if a drug with the same ID doesn't exist in the repository
		*/
		void updateDrug(int id, double newPrice);

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
		const std::vector<Drug>& getDrugs() const;

		/*
		* Method for finding the number of elements from the repository
		* Returns an integer which represents the number of elements from the repository
		*/
		size_t getSize() const;

		/*
		* Method that sorts the contents of the repository based on a criteria
		* criteria - const reference to a string which describes the type of sorting used
		* Returns a Vector of Drug elements which represents a copy of the repository that was also sorted
		* Throws ServiceException if the criteria is unrecognisable
		*/
		std::vector<Drug> sort(const std::string& criteria, const std::string& type) const;

		/*
		* Method that filters the contents of the repository based on price
		* condition - double variable which represents the price we filter by
		* Returns a Vector of Drug elements which represents a copy of the repository that was also filtered by price
		*/
		std::vector<Drug> filterPrice(double condition) const;

		/*
		* Method that filters the contents of the repository based on the substance type
		* condition - const reference to a string which represents the substance we filter by
		* Returns a Vector of Drug elements which represents a copy of the repository that was also filtered by substance
		*/
		std::vector<Drug> filterSubstance(const std::string& condition) const;

		/*
		* Method for adding a new Drug into the recipe
		* name - constant reference to a string which represents the name of the drug
		* Throws ServiceException if no durg with that name was found or all drugs with that name are already on the recipe
		*/
		void addDrugRecipe(const std::string& name) const;

		/*
		* Method for getting all the drugs from the recipe
		* Returns a constant reference to the list of drugs from the recipe
		*/
		const std::vector<Drug>& getRecipe() const noexcept;

		/*
		* Method for emptying all the drugs from the recipe
		*/
		void emptyRecipe() const noexcept;

		/*
		* Method for generating a recipe with random drugs 
		* number - integer which represents the number of drugs needed on the recipe
		* Throws ServiceException if the number is higher than the available drugs
		*/
		void generateRecipe(int number) const;

		/*
		* Method for counting the number of drugs for all producers
		*/
		std::map<std::string, ProducerCount> countProducer() const;

		/*
		* Method for exporting the Recipe list in a file
		* Throws ServiceException if the file cannot be opened
		*/
		void servExport(const std::string& file) const;

		/*
		* Method that implements the undo functionality
		*/
		void undo();

		Prescription& getPrescription() const;

		void deleteDrugsProducer(const std::string& s);
};

class ServiceException : public Error {
	using Error::Error;
public:
	static const std::string invalidSortingCriteria;
	static const std::string invalidFilteringCriteria;
	static const std::string drugsAlreadyAddedOrNotFound;
	static const std::string notEnoughDrugs;
	static const std::string fileFail;
	static const std::string undoFail;
};


#endif
