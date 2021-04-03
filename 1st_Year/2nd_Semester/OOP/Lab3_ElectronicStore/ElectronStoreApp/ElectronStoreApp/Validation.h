#ifndef VALIDATION_H
#define VALIDATION_H

/*
	Wrapper function for strtol from string.h specialised in base 10 only
*/
void strtolWrapped(char*, char**, void*);

/*
	Wrapper function for strtol from string.h specialised in base 10 only
*/
void strtodWrapped(char*, char**, void*);

/*
	Function that checks whether a string is valid in accordance to a specific criteria
	str - C-style string
	*func - pointer to a function
	number - pointer with no type
	Returns 1 if the string is valid and the conversion of the string through number and 0 otherwise
*/
int validateString(char*, void (*func)(char*, char**, void*), void*);

#endif