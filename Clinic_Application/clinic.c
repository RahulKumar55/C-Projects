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


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu (hub) for application
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i = 0, notfound = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            notfound++;
        }
    }
    if (notfound == max)
    {
        printf("*** No records found ***");
    }
    else
    {
        displayPatientTableHeader();
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber != 0)
            {
                displayPatientData(&patient[i], fmt);
            }
        }
    }
    putchar('\n');
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int selection;
    do
    {
        printf("Search Options\n==========================\n");
        printf("1) By patient number\n2) By phone number\n");
        printf("..........................\n0) Previous menu\n..........................\n");
        printf("Selection: ");
        selection = inputIntRange(0, 2);
        switch (selection)
        {
        case 1:
            searchPatientByPatientNumber(patient, max);
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            break;
        }
    } while (selection);
    putchar('\n');
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i, index = -1, k = 0;

    for (i = 0; i < max && k == 0; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            index = i;
            k = 1;
        }
    }

    if (index == -1)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        patient[index].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n\n");
    }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int pid, index;
    printf("Enter the patient number: ");
    pid = inputIntPositive();
    putchar('\n');
    index = findPatientIndexByPatientNum(pid, patient, max);

    if (index == -1)
    {
        printf("\nERROR: Patient record not found!\n\n");
    }
    else
    {
        menuPatientEdit(&patient[index]);

    }

}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int pid, index;
    char del;
    printf("Enter the patient number: ");
    pid = inputIntPositive();
    index = findPatientIndexByPatientNum(pid, patient, max);

    if (index == -1)
    {
        printf("\nERROR: Patient record not found!\n\n");
    }
    else
    {
        putchar('\n');
        displayPatientData(&patient[index], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        del = inputCharOption("yn");

        if (del == 'y')
        {
            patient[index].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
        }
        else
        {
            printf("Operation aborted.\n\n");
        }
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData data[])
{
    int includedate = 1;
    struct Date sdate = { 0 };
    
    displayScheduleTableHeader(&data->appointments->date, includedate);
    
    displaySortedData(data, sdate, includedate);

    putchar('\n');
}


// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData data[])
{
    int syear, smonth, sday, includedate = 0;
    printf("Year        : ");
    syear = inputIntPositive();
    printf("Month (1-12): ");
    smonth = inputIntRange(1, 12);
    switch (smonth)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("Day (1-31)  : ");
        sday = inputIntRange(1, 31);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("Day (1-30)  : ");
        sday = inputIntRange(1, 30);
        break;
    case 2:
        if (syear % 4 == 0)
        {
            printf("Day (1-29)  : ");
            sday = inputIntRange(1, 29);
        }
        else
        {
            printf("Day (1-28)  : ");
            sday = inputIntRange(1, 28);
        }
        break;
    }
    struct Date sdate = { syear,smonth, sday };
    
    putchar('\n');
    displayScheduleTableHeader(&sdate, includedate);

    displaySortedData(data, sdate, includedate);
   
    putchar('\n');

}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment appointments[], int maxAppointments, struct Patient patients[], int maxPatients)
{
    int pnum, i, k = 0;
    struct Date adate = { 0 };
    struct Time atime = { 0 };
    do
    {
        printf("Patient Number: ");
        pnum = inputIntPositive();

        for ( i = 0; i < maxPatients && k == 0; i++)
        {
            if (pnum == patients[i].patientNumber)
            {
                k = 1;
            }
        }
        if (k == 0)
        {
            printf("\nPatient does not exist\n\n");
        }
    } while (k == 0);

    k = 0;
    do
    {
        printf("Year        : ");
        adate.year = inputIntPositive();
        printf("Month (1-12): ");
        adate.month = inputIntRange(1, 12);
        switch (adate.month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("Day (1-31)  : ");
            adate.day = inputIntRange(1, 31);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("Day (1-30)  : ");
            adate.day = inputIntRange(1, 30);
            break;
        case 2:
            if (adate.year % 4 == 0)
            {
                printf("Day (1-29)  : ");
                adate.day = inputIntRange(1, 29);
            }
            else
            {
                printf("Day (1-28)  : ");
                adate.day = inputIntRange(1, 28);
            }
            break;
        }

        timeinput(&atime);


        k = availSlot(appointments, adate, atime, maxAppointments);
        if (k == 1)
        {
            printf("\nERROR: Appointment timeslot is not available!\n\n");
        }

        if (k == 0)
        {
            if ((atime.hour < START_HOUR || atime.hour > END_HOUR) || atime.min % MIN_INTERVALS != 0 || ((atime.hour * 60) + atime.min) > END_HOUR * 60)
            {
                printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", START_HOUR, END_HOUR, MIN_INTERVALS);

                do
                {
                    timeinput(&atime);
                    if ((atime.hour < START_HOUR || atime.hour > END_HOUR) || atime.min % MIN_INTERVALS != 0 || ((atime.hour * 60) + atime.min) > END_HOUR * 60)
                    {
                        printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", START_HOUR, END_HOUR, MIN_INTERVALS);
                        k = 2;
                    }
                    else
                    {
                        k = 0;
                    }

                } while (k != 0);
            }
            
        }
        

    } while (k != 0);

    k = 0;
    for ( i = 0; i < maxAppointments && k == 0; i++)
    {
        if (appointments[i].patientNumber == 0)
        {
            appointments[i].patientNumber = pnum;
            appointments[i].date.year = adate.year;
            appointments[i].date.month = adate.month;
            appointments[i].date.day = adate.day;
            appointments[i].time.hour = atime.hour;
            appointments[i].time.min = atime.min;
            k = 1;
        }
    }

    printf("\n*** Appointment scheduled! ***\n\n");
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment appointments[], int maxAppointments, struct Patient patients[], int maxPatients)
{
    int i, pnum, ryear, rmonth, rday, pos, k = 1;
    char del;
    printf("Patient Number: ");
    pnum = inputIntPositive();
    for ( i = 0; i < maxAppointments && k !=0; i++)
    {
        if (pnum == appointments[i].patientNumber)
        {
            k = 0;
        }
        else
        {
            k++;
        }
    }

    if (k)
    {
        printf("ERROR: Patient record not found!\n\n");
    }

    if (k == 0)
    {
        printf("Year        : ");
        ryear = inputIntPositive();
        printf("Month (1-12): ");
        rmonth = inputIntRange(1, 12);
        switch (rmonth)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("Day (1-31)  : ");
            rday = inputIntRange(1, 31);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("Day (1-30)  : ");
            rday = inputIntRange(1, 30);
            break;
        case 2:
            if (ryear % 4 == 0)
            {
                printf("Day (1-29)  : ");
                rday = inputIntRange(1, 29);
            }
            else
            {
                printf("Day (1-28)  : ");
                rday = inputIntRange(1, 28);
            }
            break;
        }

        for ( i = 0; i < maxAppointments && k == 0; i++)
        {
            if (pnum == appointments[i].patientNumber && ryear == appointments[i].date.year && rmonth == appointments[i].date.month && rday == appointments[i].date.day)
            {
                pos = i;
                for ( i = 0; i < maxPatients && k == 0; i++)
                {
                    if (pnum == patients[i].patientNumber)
                    {
                        printf("\nName  : %s\n", patients[i].name);
                        printf("Number: %05d\n", patients[i].patientNumber);
                        printf("Phone : ");
                        displayFormattedPhone(patients[i].phone.number);

                        printf(" (%s)\n", patients[i].phone.description);

                        k = 2;
                    }
                }
            }
          
        }

        if (k == 2)
        {
            printf("Are you sure you want to remove this appointment (y,n): ");
            del = inputCharOption("yn");

            if (del == 'y')
            {
                appointments[pos].patientNumber = 0;
                printf("\nAppointment record has been removed!\n\n");
            }
            else
            {
                printf("\nOperation aborted.\n\n");
            }
        }

    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int pid, index;
    printf("\nSearch by patient number: ");
    pid = inputIntPositive();
    putchar('\n');
    index = findPatientIndexByPatientNum(pid, patient, max);
    if (index == -1)
    {
        printf("*** No records found ***\n\n");
        suspend();
    }
    else
    {
        displayPatientData(&patient[index], FMT_FORM);
        putchar('\n');
        suspend();
    }
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, k = 0;
    char phnum[PHONE_LEN + 1];
    printf("\nSearch by phone number: ");
    scanf("%s", phnum);
    clearInputBuffer();
    putchar('\n');
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (0 == strcmp(phnum, patient[i].phone.number))
        {
            displayPatientData(&patient[i], FMT_TABLE);
            k++;
        }
    }

    if (k == 0)
    {
        printf("\n*** No records found ***\n\n");
        suspend();
    }
    else
    {
        putchar('\n');
        suspend();
    }
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, higest = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > higest)
        {
            higest = patient[i].patientNumber;
        }
    }
    return higest + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max)
{
    int i, result = -1;
    for (i = 0; i < max; i++)
    {
        if (patientNumber == patient[i].patientNumber)
        {
            result = i;
        }
    }
    return result;
}

// displays appointments sorted by date and time
void displaySortedData(struct ClinicData data[], struct Date sdate, int showdate)
{
    int i, j, minPos, var1 = 0, var2 = 0;
    struct Appointment temp = {0};

    for (i = 0; i < (data->maxAppointments - 1); i++)
    {
        minPos = i;
        for (j = i + 1; j < data->maxAppointments; j++)
        {
            var1 = dateinMin(data->appointments[j]);
            var2 = dateinMin(data->appointments[minPos]);

            if (var1 < var2)
            {
                minPos = j;
            }    
        }

        if (minPos != i)
        {
            temp = data->appointments[minPos];
            data->appointments[minPos] = data->appointments[i];
            data->appointments[i] = temp;
        }
    }

   
    
    if (sdate.year == 0)
    {
        for (i = 0; i < data->maxAppointments; i++)
        {
            for (j = 0; j < data->maxPatient; j++)
            {
                if (data->patients[j].patientNumber == data->appointments[i].patientNumber)
                {

                    if (data->appointments[i].date.year && data->patients[j].patientNumber)
                    {
                        displayScheduleData(&data->patients[j], &data->appointments[i], showdate);
                    }
                }
            }
        }
    }
    else
    {
        for (i = 0; i < data->maxAppointments; i++)
        {
            for (j = 0; j < data->maxPatient; j++)
            {
                if (data->patients[j].patientNumber == data->appointments[i].patientNumber)
                {

                    if (data->appointments[i].date.year && data->patients[j].patientNumber)
                    {
                        if (sdate.year == data->appointments[i].date.year && sdate.month == data->appointments[i].date.month && sdate.day == data->appointments[i].date.day)
                        {
                            displayScheduleData(&data->patients[j], &data->appointments[i], showdate);
                        }
                    }
                }
            }
        }
    }

    
}

// Returns the date and time in minutes
int dateinMin(struct Appointment appoint)
{
    int time;
    time = (appoint.date.year * 525600) + (appoint.date.month * 43200) + (appoint.date.day * 1440) + (appoint.time.hour * 60) + (appoint.time.min);
    return time;
}


//Checks if the appointment timeslot is available
int availSlot(struct Appointment appoint[], struct Date adate, struct Time atime, int maxappoints)
{
    int i, result = 0;
    for ( i = 0; i < maxappoints && result == 0; i++)
    {
        if (appoint[i].date.year == adate.year && appoint[i].date.month == adate.month && appoint[i].date.day == adate.day)
        {
            if (appoint[i].time.hour == atime.hour && appoint[i].time.min == atime.min)
            {
                result = 1;
            }
        }
    }
     
    return result;
}

// used to input time to add appointment
void timeinput(struct Time* atime)
{
    printf("Hour (0-23)  : ");
    atime->hour = inputIntRange(0, 23);
    printf("Minute (0-59): ");
    atime->min = inputIntRange(0, 59);
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n------------------\nNumber: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 0 , 15);
    putchar('\n');
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
    int contact;
    char phnum[40];
    printf("Phone Information\n-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n2. Home\n3. Work\n4. TBD\nSelection: ");
    contact = inputIntRange(1, 4);
    putchar('\n');

    switch (contact)
    {
    case 1:
        printf("Contact: CELL\nNumber : ");
        do
        {
            scanf("%s", phnum);
            if (strlen(phnum) != 10)
            {
                printf("Invalid 10-digit number! Number: ");
            }
        } while (strlen(phnum) != 10);
        putchar('\n');
        clearInputBuffer();
        strcpy(phone->number, phnum);
        strcpy(phone->description, "CELL");
        break;
    case 2:
        printf("Contact: HOME\nNumber : ");
        do
        {
            scanf("%s", phnum);
            if (strlen(phnum) != 10)
            {
                printf("Invalid 10-digit number! Number: ");
            }
        } while (strlen(phnum) != 10);
        putchar('\n');
        clearInputBuffer();
        strcpy(phone->number, phnum);
        strcpy(phone->description, "HOME");
        break;
    case 3:
        printf("Contact: WORK\nNumber : ");
        do
        {
            scanf("%s", phnum);
            if (strlen(phnum) != 10)
            {
                printf("Invalid 10-digit number! Number: ");
            }
        } while (strlen(phnum) != 10);
        putchar('\n');
        clearInputBuffer();
        strcpy(phone->number, phnum);
        strcpy(phone->description, "WORK");

        break;
    case 4:
        strcpy(phone->description, "TBD");
        strcpy(phone->number, "");
        break;
    }

}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int i, read = 0;
    FILE *pat = fopen(datafile, "r");

    if (pat != NULL)
    {
        for (i = 0; i < max && (feof(pat) == 0); i++)
        {
            fscanf(pat, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number);
            read++;

        }
        fclose(pat);
    }
    return read;
}


// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int i, read = 0;
    FILE* app = fopen(datafile,"r");

    if (app != NULL)
    {
        for (i = 0; i < max && (feof(app) == 0); i++)
        {
            fscanf(app, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min);
            read++;

        }
        fclose(app);
    }
    return read;
}