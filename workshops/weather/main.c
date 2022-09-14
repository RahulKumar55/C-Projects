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
#include <stdlib.h>
#include "header_file.h"

int main(void)
{
	int numrec = 0;
	struct WeatherRecord data[MAX_RECORDS] = {0};
	FILE* fp = fopen(FILE_NAME, "r");
	if (fp != NULL)
	{
		numrec = importWeatherDataFile(fp, &data, MAX_RECORDS);
		
		menuMain(data, numrec);
	}
}