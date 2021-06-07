#include "FileRepository.h"
#include <fstream>
FileRepository::FileRepository(const std::string& fname) : MemoryRepository(), filename(fname) {
	load();
}
void FileRepository::load() {
	std::ifstream fin(filename);
	if (!fin.is_open()) {
		throw RepoException{ RepoException::fileFail };
	}
	std::string id, name, producer, substance, price;
	while (std::getline(fin, id)) {
		std::getline(fin, name);
		std::getline(fin, producer);
		std::getline(fin, substance);
		std::getline(fin, price);
		Drug drug{ stoi(id), name, producer, substance, stod(price) };
		MemoryRepository::addDrug(drug);
	}
	fin.close();
}
void FileRepository::store() {
	std::ofstream fout(filename);
	if (!fout.is_open()) {
		throw RepoException{ RepoException::fileFail };
	}
	for (const auto& it : getDrugs()) {
		fout << it;
	}
	fout.close();
}
void FileRepository::addDrug(const Drug& newDrug) {
	MemoryRepository::addDrug(newDrug);
	store();
}
void FileRepository::deleteDrug(int id) {
	MemoryRepository::deleteDrug(id);
	store();
}
void FileRepository::updateDrug(int id, double newPrice) {
	MemoryRepository::updateDrug(id, newPrice);
	store();
}