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

#ifndef W8P1_H
#define W8P1_H

// ----------------------------------------------------------------------------
// defines/macros

#define MaxProducts 3
#define NOofgms 64
#define lb_kg_unit 2.20462

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
    int sku;
    double price;
    int caloperserv;
    double wginlbs;
};

struct ReportData
{
    int sku;
    double prodprice;
    int calperserv;
    double wgtlbs;
    double wgtkg;
    int wgtg;
    double totserv;
    double costperserv;
    double costcal;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* posi_int);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* posi_doub);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numprod);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int seqnum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skunum, const double prices, const int cal, const double lbs);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(double* pndkg, double* eqkg);

// 9. convert lbs: g
int convertLbsG(double* pndg, int*eqg);

// 10. convert lbs: kg / g
void convertLbs(double* pnd, double* eqkg, int* eqg);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servg, const int totg, double* numserv);

// 12. calculate: cost per serving
double calculateCostPerServing(double* prodprice, double* totserv, double* costperserv);

// 13. calculate: cost per calorie
double calculateCostPerCal(double* prodprice, double* totcal, double* costpercal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo rinfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rdata[MaxProducts], int c);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo chinfo);

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void);

#endif // !W8P1_H