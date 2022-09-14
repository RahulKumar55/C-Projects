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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//

//get a valid integer from the keyboard.
int inputInt(void)
{
    int input;
    char a = 'a';

    do
    {
        scanf("%d%c", &input, &a);
        if (a != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (a != '\n');
    return input;
}

//perform the same operations as inputInt but validates the value entered is greater than 0
int inputIntPositive(void)
{
    int pos;
    do
    {
        pos = inputInt();
        if (pos <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (pos <= 0);
    return pos;
}

/*performs the same operations as inputInt but validates the value entered is between the two arguments received by the function(inclusive).*/
int inputIntRange(int low, int high)
{
    int irange;
    do
    {
        irange = inputInt();
        if (irange < low || irange > high)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", low, high);
        }
    } while (irange < low || irange > high);
    return irange;
}

//get a single character value from the keyboard.
char inputCharOption(const char ch[])
{
    char input_ch[10];
    int i, k = 0;
    do
    {
        scanf("%[^\n]", input_ch);
       
        if (strlen(input_ch) != 1)
        {
            k = 0;
        }
        else
        {
            for (i = 0; ch[i] != '\0'; i++)
            {
                if (input_ch[0] == ch[i])
                {
                    k = 1;
                }

            }
        }
        clearInputBuffer();
        if (k == 0)
        {
            printf("ERROR: Character must be one of [%s]: ", ch);
        }
    } while (k == 0);
    return input_ch[0];
}

/*obtain user input for a C string value with a length(number of
characters) in the character range specified by the 2nd and 3rd arguments received (inclusive)*/
void inputCString(char str[], int min, int max)
{
    int len;
    char temp[101];

    do
    {

        len = 0;
        scanf("%[^\n]", temp);
        len = strlen(temp);
        clearInputBuffer();
        if (len < min || len > max)
        {
            if (min == max)
            {
                printf("ERROR: String length must be exactly %d chars: ", max);
            }
            else if (len > max)
            {
                printf("ERROR: String length must be no more than %d chars: ", max);
            }
            else if (len < min)
            {
                printf("ERROR: String length must be between 5 and 6 chars: ");
            }
        }

    } while (len < min || len > max);

    strcpy(str, temp);
}

// display an array of 10-character digits as a formatted phone number.
void displayFormattedPhone(const char stng[])
{
    int i = 0, k = 0, len = 0, found = 0;
    char numbers[11] = "0123456789";
    if (&stng[0] != NULL)

    {
        len = strlen(stng);

        if (len != 10)
        {
            printf("(___)___-____");
        }

        if (len == 10)
        {
            for (i = 0; stng[i] != '\0' && k == 0; i++)
            {
                found = indexof(numbers, stng[i]);
                if (found == -1)
                {
                    k = 1;
                }
            }

            if (k == 1)
            {
                printf("(___)___-____");
            }
            else
            {
                len = 0;
                for (i = 0; i < 10; i++)
                {
                    if (len == 0) printf("(");
                    printf("%c", stng[i]);
                    len++;
                    if (len == 3) printf(")");
                    if (len == 6) printf("-");
                }
            }
        }
    }
    else printf("(___)___-____");
}



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// checks if a characters is a part of a string
int indexof(const char str[], char ch)
{
    int i, result = -1;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (ch == str[i])
        {
            result = i;
        }
    }
    return result;
}