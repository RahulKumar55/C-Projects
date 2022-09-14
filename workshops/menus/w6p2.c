/*
*****************************************************************************
                          Workshop - #6 (P2)
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

#include <stdio.h>
#define maxitems 10
#define minitems 1

int main(void)
{
    const double min_income = 500, max_income = 400000, mincost = 100;
    double income, total = 0, cost[maxitems];
    int i, items, priority[maxitems];
    char financed[maxitems];
    int select, count = 0, filter;
    double filtertotal;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");

    do
    {
        printf("\nEnter your monthly NET income: $");
        scanf("%lf", &income);
        if (income < min_income) printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", min_income);
        else if (income > max_income) printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", max_income);

    } while (income <= min_income || income >= max_income);

    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &items);
        if (items < minitems || items > maxitems)
        {
            printf("ERROR: List is restricted to between %d and %d items.\n", minitems, maxitems);
        }
    } while (items <= minitems || items >= maxitems);

    for (i = 0; i < items; i++)
    {
        printf("\nItem-%d Details:\n", i + 1);
        do
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] < mincost) printf("      ERROR: Cost must be at least $%.2lf\n", mincost);
        } while (cost[i] < mincost);

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);
            if (priority[i] < 1 || priority[i] > 3) printf("      ERROR: Value must be between 1 and 3\n");
        } while (priority[i] < 1 || priority[i] > 3);

        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financed[i]);
            if (!(financed[i] == 'y' || financed[i] == 'n')) printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
        } while (!(financed[i] == 'y' || financed[i] == 'n'));

    }

    printf("\nItem Priority Financed        Cost");
    printf("\n---- -------- -------- -----------\n");
    for (i = 0; i < items; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financed[i], cost[i]);
    }
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < items; i++)
    {
        total += cost[i];
    }
    printf("                      $%11.2lf\n", total);
    

    do
    {
        printf("\nHow do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &select);

        if (!(select == 1 || select == 2 || select == 0))
        {
            printf("\nERROR: Invalid menu selection.\n");
        }
        else if (select == 1)
        {
            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", total);
            printf("Forecast: %d years, %d months\n", (int)(total / (income*12)), (int)((total / (income)) + 1) % 12); // +1 because every fraction of a month needs to be counted as one.

            for (i = 0; i < items; i++)
            {
                if (financed[i] == 'y') count++;
            }
            if (count)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
        }
        else if (select == 2)
        {
            
            do
            {
                printf("\nWhat priority do you want to filter by? [1-3]: ");
                scanf(" %d", &filter);
                if (!(filter == 1 || filter == 2 || filter == 3))
                {
                    printf("Choose correct value [1-3]\n\n");
                }
            } while (!(filter == 1 || filter == 2 || filter == 3));
            
            if (filter == 1)
            {
                printf("\n====================================================\n");
                printf("Filter:   by priority (1)\n");

                filtertotal = 0;
                count = 0;
                for ( i = 0; i < items; i++)
                {
                    if (priority[i] == 1)
                    {
                        filtertotal += cost[i];
                        if (financed[i] == 'y') count++;
                    }
                }
                printf("Amount:   $%.2lf\n", filtertotal);
                printf("Forecast: %d years, %d months\n", (int)(filtertotal / (income * 12)), (int)((filtertotal / (income)) + 1) % 12); // +1 because every fraction of a month needs to be counted as one.
                if (count)
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                printf("====================================================\n");
            }
            
            if (filter == 2)
            {
                printf("\n====================================================\n");
                printf("Filter:   by priority (2)\n");

                filtertotal = 0;
                count = 0;
                for (i = 0; i < items; i++)
                {
                    if (priority[i] == 2)
                    {
                        filtertotal += cost[i];
                        if (financed[i] == 'y') count++;
                    }
                }
                printf("Amount:   $%.2lf\n", filtertotal);
                printf("Forecast: %d years, %d months\n", (int)(filtertotal / (income * 12)), (int)((filtertotal / (income)) + 1) % 12); // +1 because every fraction of a month needs to be counted as one.
                if (count)
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                printf("====================================================\n");
            }

            if (filter == 3)
            {
                printf("\n====================================================\n");
                printf("Filter:   by priority (3)\n");

                filtertotal = 0;
                count = 0;
                for (i = 0; i < items; i++)
                {
                    if (priority[i] == 3)
                    {
                        filtertotal += cost[i];
                        if (financed[i] == 'y') count++;
                    }
                }
                printf("Amount:   $%.2lf\n", filtertotal);
                printf("Forecast: %d years, %d months\n", (int)(filtertotal / (income * 12)), (int)((filtertotal / (income)) + 1) % 12); // +1 because every fraction of a month needs to be counted as one.
                if (count)
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                printf("====================================================\n");
            }
        }
        
    } while (select);

    printf("\nBest of luck in all your future endeavours!\n");

    return 0;
}