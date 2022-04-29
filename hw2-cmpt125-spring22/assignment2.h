#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H

#include <stdio.h>
#include <inttypes.h>


// The function gets the name of a file, a term and its definition.
// - If the term is not in the file, the function adds
// the term and its definition to the file and returns 1.
// - If the term is already in the file,
// the function does not modify the file and returns 0.
// - If the file does not exist, the function creates a new file
// with the given name, adds the pair to the file and returns 1.
int add_term(const char* file_name, const char* term, const char* definition);


// The function gets the name of a file and a term.
// It searches the file for the given term.
// - If the term is found, the function returns a string containing the definition.
// - If the file does not exist or the term is not in the file, the function returns NULL.
char* find_term(const char* file_name, const char* term);


// fib3 is defined as follows
// fib3(0) = 0
// fib3(1) = 1
// fib3(2) = 2
// fib3(n) = fib3(n-1) + 2*fib3(n-2) + 3*fib3(n-3) for all n>=3
// The first elements of the  sequence are 0, 1, 2, 4, 11, 25, 59, 142, 335, 796, 1892, 4489...
uint64_t fib3(unsigned int n);


// The function gets a string str, and returns the number of tokens in str
// consisting of only lower case letters.
int count_tokens(const char* str);


// The function gets a string str, and returns the array of tokens in str
// consisting of only lower case letters.
char** get_tokens(const char* str);

#endif
