/* Group Members:
    ---
    Name: Sebastián Rubina
    Student ID: 150640217
    Email: srubina-sanchez@myseneca.ca
    ---
    Name: Rahul Kumar
    Student ID: 157197211
    Email: rkumar141@myseneca.ca
 
 */

#define _CRT_SECURE_NO_WARNINGS

#include "header_file.h"
#include <stdlib.h>
#include <string.h>


 /* Input of data */

//Takes input from WeatherRecord and assigns region code, region name and total precipitaion to RegionData struct
void inputRdata(const struct WeatherRecord data[], struct RegionData rdata[], const int numrec)
{
    int i, j, k;

    for (i = 0; i < numrec; i++)
    {
        k = 0;
        for (j = 0; j < REGIONS && k != -1; j++)
        {
            if (data[i].location.regionCode == rdata[j].regioncode)
            {
                k = -1;
            }

            if (k != -1 && rdata[j].regioncode == 0)
            {
                rdata[j].regioncode = data[i].location.regionCode;
                k = -1;
            }

        }

    }


    for (i = 0; i < REGIONS; i++)
    {
        switch (rdata[i].regioncode)
        {
        case 10:
            strcpy(rdata[i].area, "Western");
            break;
        case 20:
            strcpy(rdata[i].area, "Northern");
            break;
        case 30:
            strcpy(rdata[i].area, "Eastern");
            break;
        case 40:
            strcpy(rdata[i].area, "Central");
            break;
        }
    }



    for (i = 0; i < REGIONS; i++)
    {
        for (j = 0; j < numrec; j++)
        {
            if (rdata[i].regioncode == data[j].location.regionCode)
            {
                if (data[j].unit == 'c')
                {

                    rdata[i].preciAmt += (int)(data[j].precipAmt * 10);
                }
                else
                {
                    rdata[i].preciAmt += data[j].precipAmt;
                }
            }
        }
    }

}


// Convers cm to mm and assigns precip value to all months
void convertPrecipToMM(struct WeatherRecord data[], struct Months months[], int numRecords)
{
    int i = 0, j = 0;

    for (i = 0; i < MONTHS; i++)
    {
        months[i].month = i + 1;
        for (j = 0; j < numRecords; j++)
        {
            if (months[i].month == data[j].date.month)
            {
                if (data[j].unit == 'm')
                {
                    months[i].preciptAmtMm += data[j].precipAmt;
                }
                else
                {
                    months[i].preciptAmtMm += (int)(data[j].precipAmt * 10);   
                }
            }
        }
    }
}

//Takes input from WeatherRecord and assigns location name, total precipitaion to LocationData struct
void inputLdata(const struct WeatherRecord data[], struct LocationData ldata[], const int numrec)
{
    int i, j, k;
    for (i = 0; i < numrec; i++)
    {
        k = 0;
        for (j = 0; j < LOCATIONS && k != -1; j++)
        {
            if (strcmp(data[i].location.name, ldata[j].loc_name) == 0)
            {
                k = -1;
            }

            if (k != -1 && strlen(ldata[j].loc_name) == 0)
            {
                strcpy(ldata[j].loc_name, data[i].location.name);
                k = -1;
            }

        }

    }

    for (i = 0; i < LOCATIONS; i++)
    {
        for (j = 0; j < numrec; j++)
        {
            if (strcmp(ldata[i].loc_name, data[j].location.name) == 0)
            {
                if (data[j].unit == 'c')
                {

                    ldata[i].preciAmt += (int)(data[j].precipAmt * 10);
                }
                else
                {
                    ldata[i].preciAmt += data[j].precipAmt;
                }
            }
        }
    }
}


 /* sorting*/

 //Sorts data in a descending order of total Precipitaion of every region
void sortRdata(struct RegionData rdata[])
{
    int i, j, maxPos;
    struct RegionData temp = { 0 };
    for (i = 0; i < (REGIONS - 1); i++)
    {
        maxPos = i;
        for (j = i + 1; j < REGIONS; j++)
        {
            if (rdata[j].preciAmt > rdata[maxPos].preciAmt)
            {
                maxPos = j;
            }
        }

        if (maxPos != i)
        {
            temp = rdata[maxPos];
            rdata[maxPos] = rdata[i];
            rdata[i] = temp;
        }
    }
}


// Sorts list of months by precip ammount (mm)
void sortByMonth(struct Months* months) {
    int i = 0, j = 0;
    for (i = 0; i < MONTHS; i++)
    {
        for (j = 0; j < MONTHS - 1; j++)
        {
            struct Months temp;
            if (months[j].preciptAmtMm > months[j + 1].preciptAmtMm)
            {
                temp = months[j];
                months[j] = months[j + 1];
                months[j + 1] = temp;
            }
        }
    }
}

//Sorts data in a descending order of total Precipitaion of every location
void sortLdata(struct LocationData ldata[])
{
    int i, j, maxPos;
    struct LocationData temp = { 0 };

    for (i = 0; i < (LOCATIONS - 1); i++)
    {
        maxPos = i;
        for (j = i + 1; j < LOCATIONS; j++)
        {
            if (ldata[j].preciAmt > ldata[maxPos].preciAmt)
            {
                maxPos = j;
            }
        }

        if (maxPos != i)
        {
            temp = ldata[maxPos];
            ldata[maxPos] = ldata[i];
            ldata[i] = temp;
        }
    }
}

  /* UTILITY FUNCTIONS */

    // Returns month in written form
char* printMonth(int month, char* string) {
    switch (month) {
        case 1:
            strcpy(string, "January"); // Copies written month to string, returns string
            break;
        case 2:
            strcpy(string, "February");
            break;
        case 3:
            strcpy(string, "March");
            break;
        case 4:
            strcpy(string, "April");
            break;
        case 5:
            strcpy(string, "May");
            break;
        case 6:
            strcpy(string, "June");
            break;
        case 7:
            strcpy(string, "July");
            break;
        case 8:
            strcpy(string, "August");
            break;
        case 9:
            strcpy(string, "September");
            break;
        case 10:
            strcpy(string, "October");
            break;
        case 11:
            strcpy(string, "November");
            break;
        case 12:
            strcpy(string, "December");
            break;
    }
    return string;
}


/* CORE FUNCTIONS */

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
    printf("< Press [ENTER] key to continue >");
    clearInputBuffer();
    putchar('\n');
}

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