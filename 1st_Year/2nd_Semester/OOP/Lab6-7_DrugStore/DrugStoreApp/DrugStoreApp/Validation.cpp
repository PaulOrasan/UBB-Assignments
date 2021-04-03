#include "Validation.h"
#include <algorithm>
#include "Drug.h"
const std::string ValidationException::invalidID{ "ID is not valid!" };
const std::string ValidationException::invalidPrice{ "Price is not valid!" };
const std::string ValidationException::invalidDrug{ "Drug is not valid!" };

void Validation::validateID(const std::string& id) {
	if (id.empty() || !std::all_of(id.begin(), id.end(), isdigit))
		throw ValidationException{ ValidationException::invalidID };
}
void Validation::validatePrice(const std::string& price) {
	int contor = 0;
	bool notNumber = false;
	for (auto& i : price) {
		if (i == '.')
			contor++;
		if (i != '.' && !isdigit(i))
			notNumber = true;
	}
	if (notNumber || contor > 1 || price.empty()) {
		throw ValidationException{ ValidationException::invalidPrice };
	}
}