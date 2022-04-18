#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H


// gets two ints x and y
//  returns the sum of all ints between x and y, including them
int sum_interval(int x, int y);


// gets a string str
// changes all lower case letters to * (asterisk)
// changes  all upper case letters to $ (dollar sign)
// all other characters remain unchanged
// returns the total number of letters modified
int hide_letters(char* str);


// gets an array of ints of length n
// returns the number of times the maximal element appears in the array
// assumption: n>0
int count_max(const int* arr, int n);


// gets a string representing a positive integer and an int between 0 and 9
// the function multiplies that two numbers and returns the result in a string
char* mult_number_by_digit(const char* num, int digit);


// gets an array of n ints, where each entry in the array is between 0 and 9
// the function multiplies all these numbers and outputs the result as a string
// the reason it needs to output a string (and not an int)
// is because the result might be too large to fit into an int/long.
// assumptions: n>0 and 0 <= digits[i] <=9 for all i=0...n-1
char* mult_digits(const int* digits, int n);


#endif