/*
*****************************************************************************
                          Workshop - #8 (P2)
Full Name  : 
Student ID#: 
Email      : 
Section    : 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>


// User-Defined Libraries
#include "w8p2.h"

int snum, calory;
double priceof, weight;
struct CatFoodInfo info[MaxProducts] = { { 0, 0, 0, 0 } };
struct ReportData Cheapest = { 0 };

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* posi_int)
{
	int i;
	do
	{
		scanf("%d", &i);
		if (i <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (i <= 0);

	if (posi_int != NULL)
	{
		*posi_int = i;
	}
	return i;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* posi_doub)
{
	double i;
	do
	{
		scanf("%lf", &i);
		if (i <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (i <= 0);

	if (posi_doub != NULL)
	{
		*posi_doub = i;
	}
	return i;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numprod)
{
	printf("Cat Food Cost Analysis\n======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.", MaxProducts);
	printf("\nNOTE: A 'serving' is %dg\n", NOofgms);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int seqnum)
{
	printf("\nCat Food Product #%d\n", seqnum + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	info[seqnum].sku = getIntPositive(&snum);

	printf("PRICE         : $");
	info[seqnum].price = getDoublePositive(&priceof);

	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&weight);
	info[seqnum].wginlbs = weight;

	printf("CALORIES/SERV.: ");
	getIntPositive(&calory);
	info[seqnum].caloperserv = calory;

	return info[seqnum];
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skunum, const double prices, const int cal, const double lbs)
{
	printf("%07d %10.2lf %10.1lf %8d\n", skunum, prices, lbs, cal);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(double* pndkg, double* eqkg)
{
	double  i;
	i = *pndkg / lb_kg_unit;
	if (eqkg != NULL)
	{
		*eqkg = i;
	}
	return i;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(double* pndg, int* eqg)
{
	int i;
	i = (convertLbsKg(pndg, NULL)) * 1000;
	if (eqg != NULL)
	{
		*eqg = i;
	}
	return i;
}

// 10. convert lbs: kg and g
void convertLbs(double* pnd, double* eqkg, int* eqg)
{
	*eqkg = convertLbsKg(pnd, NULL);
	*eqg = convertLbsG(pnd, NULL);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servg, const int totg, double* numserv)
{
	double i;
	i = ((double)totg) / servg;
	if (numserv != NULL)
	{
		*numserv = i;
	}
	return i;
}

// 12. calculate: cost per serving
double calculateCostPerServing(double* prodprice, double* totserv, double* costperserv)
{
	double i;
	i = *prodprice / *totserv;
	if (costperserv != NULL)
	{
		*costperserv = i;
	}
	return i;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(double* prodprice, double* totcal, double* costpercal)
{
	double i;
	i = *prodprice / *totcal;
	if (costpercal != NULL)
	{
		*costpercal = i;
	}
	return i;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo rinfo)
{
	struct ReportData data = { 0 };
	double totcal;

		data.sku = rinfo.sku;
		data.prodprice = rinfo.price;
		data.calperserv = rinfo.caloperserv;
		data.wgtlbs = rinfo.wginlbs;
		convertLbs(&data.wgtlbs, &data.wgtkg, &data.wgtg);
		data.totserv = calculateServings(NOofgms, data.wgtg, NULL);
		data.costperserv = calculateCostPerServing(&data.prodprice, &data.totserv, NULL);
		totcal = data.calperserv * data.totserv;
		calculateCostPerCal(&data.prodprice, &totcal, &data.costcal);
	return data;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", NOofgms);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rdata[MaxProducts], int c)
{
	int i;

	for (i = 0; i < MaxProducts; i++)
	{
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", rdata[i].sku, rdata[i].prodprice, rdata[i].wgtlbs, rdata[i].wgtkg, rdata[i].wgtg, rdata[i].calperserv, rdata[i].totserv, rdata[i].costperserv, rdata[i].costcal);
		if (i == c) printf(" ***");
		printf("\n");

	}
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo chinfo)
{
	printf("Final Analysis\n--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%4.2lf\n", chinfo.sku, chinfo.price);
	printf("\nHappy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	int i, j = 0;
	struct ReportData data[MaxProducts] = { {0} };
	openingMessage(MaxProducts);

	for (i = 0; i < MaxProducts; i++)
	{
		getCatFoodInfo(i);
	}

	printf("\n");
	displayCatFoodHeader();

	for (i = 0; i < MaxProducts; i++)
	{
		displayCatFoodData(info[i].sku, info[i].price, info[i].caloperserv, info[i].wginlbs);
	}
	printf("\n");

	for (i = 0; i < MaxProducts; i++)
	{
		data[i] = calculateReportData(info[i]);
	}

	for (i = 1; i < MaxProducts; i++)
	{
		if (data[i].costcal < data[i-1].costcal)
		{
			j = i;
		}
	}

	displayReportHeader();
	displayReportData(data, j);
	printf("\n");
	displayFinalAnalysis(info[j]);
}
