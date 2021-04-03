#ifndef ERROR_H
#define ERROR_H
#include <string>
class Error
{
	private:
		std::string message;
	public:
		/*
		* constructor for class Drug with initialisation
		*/
		explicit Error(const std::string& msg): message { msg } {}

		/*
		* Finds the message of the error and returns it as a string
		*/
		std::string getMessage() const;
};
#endif
