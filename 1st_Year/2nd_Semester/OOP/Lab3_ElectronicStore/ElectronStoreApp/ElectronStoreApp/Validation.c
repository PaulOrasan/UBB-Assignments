#include "Validation.h"
#include <stdlib.h>
#include <errno.h>
void strtolWrapped(char* str, char** endptr, void* number) {
	/*
		Wrapper function for strtol from string.h specialised in base 10 only
	*/
	*(int*)number=strtol(str, endptr, 10);
}
void strtodWrapped(char* str, char** endptr, void* number) {
	/*
		Wrapper function for strtol from string.h specialised in base 10 only
	*/
	*(double*)number=strtod(str, endptr);
}
int validateString(char* str, void (*func)(char*, char**, void*), void* number) {
	/*
		Function that checks whether a string is valid in accordance to a specific criteria
		str - C-style string
		*func - pointer to a function
		number - pointer with no type
		Returns 1 if the string is valid and the conversion of the string through number and 0 otherwise
	*/
	// scary code syntax but proud it works
	char* endptr = 0;
	errno = 0;
	(*func)(str, &endptr, number);				// can use it either for strtol or strtod
	if (*endptr != '\0' || errno == ERANGE) {
		return 0;
	}
	return 1;

}