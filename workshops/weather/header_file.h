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

#pragma once

#ifndef HEADER_FILE_H
#define HEADER_FILE_H

#include <stdio.h>


// Macros
#define NAME_LEN 20
#define MAX_RECORDS 250
#define REGIONS 4
#define LOCATIONS 8
#define MONTHS 12
#define FILE_NAME "weatherdata.txt"

// Structs
struct Date
{
	int year; 
	int month;
};

struct Location
{
	int regionCode;
	char name[NAME_LEN];
};

struct WeatherRecord
{
	struct Date date;
	double precipAmt;
	char unit;
	struct Location location;
};

struct RegionData
{
	int regioncode;
	char area[NAME_LEN];
	int preciAmt;
};

struct Months
{ // Struct holds months with precip value for Function 2
	int month;
	char unit;
	int preciptAmtMm;
};

struct LocationData
{
	char loc_name[NAME_LEN];
	int preciAmt;
};


//Functions

/* File Reading*/

int importWeatherDataFile(FILE* fp, struct WeatherRecord* data, int max);

//Menu
void menuMain(struct WeatherRecord data[], const int numrec);

/*Displaying Data*/

//Displays all fields and rows read from file
void viewAllData(struct WeatherRecord* data, const int numRecords);

//Displays sorted data by regions
void viewByRegion(const struct WeatherRecord data[], const int numrec);

//Displays sorted data by months
void viewByMonth(struct WeatherRecord data[], const int numRecords);

//Displays sorted data by locations
void byLocName(const struct WeatherRecord data[], const int numrec);

/* Input of data */

//Takes input from WeatherRecord and assigns region code, region name and total precipitaion to RegionData struct
void inputRdata(const struct WeatherRecord data[], struct RegionData rdata[], const int numrec);

// Convers cm to mm and assigns precip value to all months
void convertPrecipToMM(struct WeatherRecord data[], struct Months months[], int numRecords);

//Takes input from WeatherRecord and assigns location name, total precipitaion to LocationData struct
void inputLdata(const struct WeatherRecord data[], struct LocationData ldata[], const int numrec);

/* sorting*/

//Sorts data in a descending order of total Precipitaion of every region
void sortRdata(struct RegionData rdata[]);

// Sorts list of months by precip ammount (mm)
void sortByMonth(struct Months* months);

//Sorts data in a descending order of total Precipitaion of every location
void sortLdata(struct LocationData ldata[]);

/* UTILITY FUNCTIONS */

// Returns month in written form
char* printMonth(int month, char* string);

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

//get a valid integer from the keyboard.
int inputInt(void);

/*performs the same operations as inputInt but validates the value entered is between the two arguments received by the function(inclusive).*/
int inputIntRange(int low, int high);

#endif