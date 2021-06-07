#ifndef FILE_REPOSITORY_H
#define FILE_REPOSITORY_H
#include "MemoryRepository.h"
#include <string>

class FileRepository : public MemoryRepository
{
private:
	std::string filename;

	/*
	* Method that loads repository elements from file
	* Throws RepositoryException if the file cannot be opened
	*/
	void load();

	/*
	* Method that stores repository elements to file
	* Throws RepositoryException if the file cannot be opened
	*/
	void store();
public:
	FileRepository(const std::string& fname);

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
	void deleteDrug(int id) override;

	/*
	* Method that deletes a drug from the repository
	* id - integer which represents the id of the drug we want to update
	* newPrice - double value of the new price that must be modified
	* Throws RepoException if the object doesn't exist in the repository
	*/
	void updateDrug(int id, double newPrice) override;

	~FileRepository() override {}
};
#endif
