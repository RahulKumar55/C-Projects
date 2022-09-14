/*
*****************************************************************************
                        Assignment 1 - Milestone 3
Full Name  : Rahul Kumar
Student ID#: 157197211
Email      : rkumar141@myseneca.ca
Section    : NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #2 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//get a valid integer from the keyboard.
int inputInt(void);

//perform the same operations as inputInt but validates the value entered is greater than 0
int inputIntPositive(void);

/*performs the same operations as inputInt but validates the value entered is between the two arguments received by the function(inclusive).*/
int inputIntRange(int low, int high);

//get a single character value from the keyboard.
char inputCharOption(const char ch[]);

/*obtain user input for a C string value with a length(number of
characters) in the character range specified by the 2nd and 3rd arguments received (inclusive)*/
void inputCString(char* str, int min, int max);

// display an array of 10-character digits as a formatted phone number.
void displayFormattedPhone(const char* stng);

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// checks if a characters is a part of a string
int indexof(const char str[], char ch);


// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H