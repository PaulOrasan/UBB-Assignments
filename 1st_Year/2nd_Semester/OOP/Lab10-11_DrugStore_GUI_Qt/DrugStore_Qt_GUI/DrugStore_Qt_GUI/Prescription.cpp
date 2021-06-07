#include "Prescription.h"
#include <algorithm>
void Prescription::addDrug(const Drug& newDrug) {
	prescriptionList.push_back(newDrug);
	notify();
}

bool Prescription::findDrug(int id) const {
	if (prescriptionList.size() == 0)
		return false;
	return find_if(prescriptionList.begin(), prescriptionList.end(), [&id](const Drug& drug) noexcept { return drug.getID() == id; }) != prescriptionList.end();
}

void Prescription::deleteDrug(int id) {
	// !!! WHEN THE ERROR IS MESSY ALWAYS CHECK CONSTRUCTOR PARAMETERS (MUST HAVE REFERENCE) !!!
	if (findDrug(id)) {
		auto it = find_if(prescriptionList.begin(), prescriptionList.end(), [&id](const Drug& drug) noexcept { return drug.getID() == id; });
		if (it != prescriptionList.end()) {
			prescriptionList.erase(it);
			notify();
		}
	}
}

void Prescription::emptyDrugs() noexcept {
	prescriptionList.clear();
	notify();
}

const std::vector<Drug>& Prescription::getAll() noexcept {
	return prescriptionList;
}

void Prescription::exportList(std::ofstream& fout) const {
	for (const auto& it : prescriptionList)
		fout << it;
}