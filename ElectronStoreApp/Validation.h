#ifndef VALIDATION_H
#define VALIDATION_H
void strtolWrapped(char*, char**, void*);
void strtodWrapped(char*, char**, void*);
int validateString(char*, void (*func)(char*, char**, void*), void*);

#endif