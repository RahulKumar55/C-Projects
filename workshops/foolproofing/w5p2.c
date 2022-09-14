/*
*****************************************************************************
                          Workshop - #5 (P2)
Full Name  : Rahul kumar
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
#define MIN_YEAR 2012
#define MAX_Year 2022
#define LOG_DAYS 3

int main(void)
{
    int year, month, i;
    const int JAN = 1, DEC = 12;
    double m_rate, e_rate, tot_m_rate = 0, tot_e_rate = 0;
    int mvalues = 0, evalues = 0;

    printf("General Well-being Log\n");
    printf("======================\n");
    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d%*c%d%*c", &year, &month);

        if ((year< MIN_YEAR || year>MAX_Year) && (month<JAN || month>DEC))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else if (month<JAN || month>DEC)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else if (year< MIN_YEAR || year>MAX_Year)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        else
        {
            printf("\n*** Log date set! ***\n");
        }
    } while ((year< MIN_YEAR || year>MAX_Year) || (month<JAN || month>DEC));
   
    for (i = 1; i <= LOG_DAYS; i++)
    {






        printf("\n%d-", year);
        switch (month)
        {
        case 1:
            printf("JAN-0%d\n", i);
            break;
        case 2:
            printf("FEB-0%d\n", i);
            break;
        case 3:
            printf("MAR-0%d\n", i);
            break;
        case 4:
            printf("APR-0%d\n", i);
            break;
        case 5:
            printf("MAY-0%d\n", i);
            break;
        case 6:
            printf("JUN-0%d\n", i);
            break;
        case 7:
            printf("JUL-0%d\n", i);
            break;
        case 8:
            printf("AUG-0%d\n", i);
            break;
        case 9:
            printf("SEP-0%d\n", i);
            break;
        case 10:
            printf("OCT-0%d\n", i);
            break;
        case 11:
            printf("NOV-0%d\n", i);
            break;
        case 12:
            printf("DEC-0%d\n", i);
            break;
        }
        do
        {
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &m_rate);
                if (m_rate < 0.0 || m_rate>5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (m_rate < 0.0 || m_rate>5.0);
            tot_m_rate += m_rate;
            mvalues++;
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &e_rate);
                if (e_rate < 0.0 || e_rate>5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (e_rate < 0.0 || e_rate>5.0);
            tot_e_rate += e_rate;
            evalues++;
        } while ((m_rate < 0.0 || m_rate>5.0) || (e_rate < 0.0 || e_rate>5.0));
    }

    printf("\nSummary");
    printf("\n=======\n");
    printf("Morning total rating: %5.3lf\n", tot_m_rate);
    printf("Evening total rating:  %5.3lf\n", tot_e_rate);
    printf("----------------------------\n");
    printf("Overall total rating: %5.3lf\n\n", tot_m_rate + tot_e_rate);
    printf("Average morning rating:%5.1lf\n", ((float)tot_m_rate / mvalues)); 
    printf("Average evening rating:%5.1lf\n", ((float)tot_e_rate / evalues)); 
    printf("----------------------------\n");
    printf("Average overall rating:%5.1lf\n", ((float)(tot_m_rate + tot_e_rate) / (mvalues + evalues)));
    return 0;
}