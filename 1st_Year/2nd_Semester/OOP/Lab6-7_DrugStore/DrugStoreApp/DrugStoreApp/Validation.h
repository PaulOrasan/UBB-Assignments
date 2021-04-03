#ifndef VALIDATION_H
#define VALIDATION_H
#include "Drug.h"
#include "Error.h"
#include <string>
class Validation
{
	public:
		static void validateID(const std::string& id);
		static void validatePrice(const std::string& price);
};

class ValidationException : public Error {
	using Error::Error;
	public:
		static const std::string invalidID, invalidPrice, invalidDrug;
};
#endif
