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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header_file.h"

 /* File Reading*/
int importWeatherDataFile(FILE* fp, struct WeatherRecord* data, int max)

{

    int recs = 0;



    if (fp != NULL)

    {

        while (recs < max &&

            fscanf(fp, "%d,%d,%lf,%c,%d,%15[^\n]\n",

                &data[recs].date.year, &data[recs].date.month,

                &data[recs].precipAmt, &data[recs].unit,

                &data[recs].location.regionCode,

                data[recs].location.name) == 6)

        {

            recs++;

        }

    }



    return recs;

}

//Menu
void menuMain(struct WeatherRecord data[], const int numrec)
{
    int selection;

    do
    {
        printf("=======================================================\n"
            "         Ontario Weather Analysis Service\n"            "=======================================================\n"
            "1. View all data\n"
            "2. View by region (sorted DESCENDING by precip.)\n"
            "3. View by month (sorted ASCENDING by precip.)\n"
            "4. View by location name (sorted DESCENDING by precip.)\n"
            "-------------------------------------------------------\n"
            "0. Exit\n"
            "-------------------------------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 0:
            if (!selection)
            {
                printf("Application Terminated!");
            }
            break;
        case 1:
            viewAllData(data, numrec);
            break;
        case 2:
            viewByRegion(data, numrec);
            break;
        case 3:
            viewByMonth(data, numrec);
            break;
        case 4:
            byLocName(data, numrec);
            break;
        }
    } while (selection);
}



/* DISPLAYING DATA */
//Displays all fields and rows read from file
void viewAllData(struct WeatherRecord* data, const int numRecords)
{
    int i = 0;
    printf("Year Month Precip.Amt Unit Region Name\n");
    printf("---- ----- ---------- ---- ------ ---------------\n");
    for (i = 0; i < numRecords; i++)
    {
       
            if (i % 15 == 0 && i > 1) // Shows 15 at a time, suspend() is called to wait for user input (<Enter>)
            {
                putchar('\n');
                suspend();
            }
            printf("%4d    %02d %10.1lf %4c %6d %s\n", data[i].date.year, data[i].date.month, data[i].precipAmt, data[i].unit, data[i].location.regionCode, data[i].location.name);
            if (i == numRecords - 1) printf("\n"); // Prints extra line if at the last element for spacing
            
    }
}


//Displays sorted data by regions
void viewByRegion(const struct WeatherRecord data[], const int numrec)
{
    int i, tot = 0;
    double avg = 0;
    struct RegionData rdata[REGIONS] = { 0 };
    

    inputRdata(data, rdata, numrec);

    for (i = 0; i < REGIONS; i++)
    {
        tot += rdata[i].preciAmt;
    }
    avg = (double)tot / REGIONS;


    sortRdata(rdata);

    printf("Region Name     Precip(mm)\n------ -------- ----------\n");
    for ( i = 0; i < REGIONS; i++)
    {
        printf("%6d %-8s %10d\n", rdata[i].regioncode, rdata[i].area, rdata[i].preciAmt);
    }
    printf("------ -------- ----------\n");
    printf("%15s %10d\n", "Total:", tot);
    printf("%15s %10.2lf\n\n", "Average:", avg);

};


//Displays sorted data by months
void viewByMonth(struct WeatherRecord data[], const int numRecords)
{
    int i = 0;
    double precipitationSum = 0;
    struct Months months[MONTHS] = { 0 }; // List of months
    convertPrecipToMM(data, months, numRecords); // Convers cm to mm and assigns precip value to all months
    sortByMonth(months); // Sorts list of months by precip ammount (mm)
    printf("Month     Precip(mm)\n");
    printf("--------- ----------\n");

    for (i = 0; i < MONTHS; i++) // Prints all months
    {
        char stringMonth[15];
        precipitationSum += months[i].preciptAmtMm;
        printf("%-9s %10d\n", printMonth(months[i].month, stringMonth), months[i].preciptAmtMm); // Returns month in written form
    }
    printf("--------- ----------\n");
    printf("%9s %10.0lf\n", "Total:", precipitationSum);
    printf("%9s %10.2lf\n", "Average:", precipitationSum / MONTHS);
    printf("\n");
}


//Displays sorted data by locations
void byLocName(const struct WeatherRecord data[], const int numrec)
{
    int i, tot = 0;
    double avg = 0;
    struct LocationData ldata[LOCATIONS] = { 0 };
    


    inputLdata(data, ldata, numrec);

    for (i = 0; i < LOCATIONS; i++)
    {
        tot += ldata[i].preciAmt;
    }
    avg = (double)tot / LOCATIONS;

    sortLdata(ldata);

    printf("Location        Precip(mm)\n--------------- ----------\n");
    for ( i = 0; i < LOCATIONS; i++)
    {
        printf("%15s %10d\n", ldata[i].loc_name, ldata[i].preciAmt);
    }
    printf("--------------- ----------\n");
    printf("%15s %10d\n", "Total:", tot);
    printf("%15s %10.2lf\n\n", "Average:", avg);
}
