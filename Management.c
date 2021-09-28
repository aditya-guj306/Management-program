// A Management System for the elaboration of User System
// INCLUDING HEADER FILES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

// DECLARATION OF FUNCTIONS
void confirm();
void space();
void Time();
void dashboard();
void login();
void create();
void bio();
void database();
int main();

// DECLARATION OF VARIABLES
typedef struct cyber
{
    char Fname[20];
    char Lname[20];
    char user[20];
    char pass[20];
    char a[100];
    char auth[30];
    int b;
    char asd[20];
    char cuser[40];
    char cpass[40];
} cyber;
cyber C_M, p, q, d, f, a, t, s;

// FUNCTION TO ELIMINATE SPACES IN USERNAME
void space()
{
    int i, len, j;
    len = sizeof(C_M.user) / sizeof(C_M.user[20]);

    for (i = 0; i < len; i++)
    {
        if (C_M.user[i] == ' ')
        {
            for (j = i; j < len; j++)
            {
                C_M.user[j] = C_M.user[j + 1];
            }
            len--;
        }
    }
}

// DISPLAYING TIME
void Time()
{
    printf("\n                                                                    WELCOME %s \n", C_M.user);
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Logged in on Date: %d-%d-%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    time_t ti;
    ti = time(NULL);
    struct tm tn;
    tn = *localtime(&ti);
    printf("Logged in at Time: %d:%d:%d\n\n", tn.tm_hour, tn.tm_min, tn.tm_sec);
}

// FUNCTION FOR DASHBOARD
void dashboard()
{
    printf("---------------------------------------------------------------------------------------------------------------------------------\n"
           "|                                                        USER DASHBOARD                                                          |\n"
           "----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Enter 1 for Account Details\nEnter 2 for Management Info\nEnter 3 for Project Details\nEnter 4 to write Bio\nEnter 0 to Log out\n");
    scanf("%d", &C_M.b);
    switch (C_M.b)
    {
    case 0:
        system("cls");
        main();
        break;
    case 1:
        system("cls");
        confirm();
        break;
    case 2:
        printf("  Management is the act of getting people together to accomplish desired goals and objectives using available resources efficiently and effectively. Since organizations can be viewed as systems, management can also be defined as human action, including design, to facilitate the production of useful outcomes from a system. This view opens the opportunity to manage oneself, a pre-requisite to attempting to manage others.        ");
        break;
    case 3:
        printf("  The software is the solution for an Internet cafe. The software provides you with a means to control the workstations, manage customer database, sell products and generate detailed reports and statistics. This is a powerful Cyber Cafe management software that helps with managing customers and employees, controlling computers and printers, securing systems, accounting and billing. It simplifies and automates running your Internet Cafe business. Unlike many other competitive programs, Cyber cafe management system is robust, quick, secure and very intuitive and easy to use. It doesn't matter how big your Internet cafe is - Cyber cafe management system is capable of controlling any number of workstations.      ");
        break;
    case 4:
        system("cls");
        bio();
        break;
    default:
        printf("Invalid Input please Re-");
        break;
    }
    printf("\n\n");
    dashboard();
}

// FUNCTION FOR LOGIN SECTION
void login()
{
    printf("--------------------------------------------------------------------------------------------------------------------------------\n"
           "|                                                      LOGIN CREDINTIALS                                                        |\n"
           "--------------------------------------------------------------------------------------------------------------------------------\n");
    printf("USERNAME : ");
    scanf("%s", C_M.cuser);
    printf("Password : ");
    scanf("%s", C_M.cpass);
    FILE *aa;

    aa = fopen("acc.txt", "r");

    fscanf(aa, "%s %s %s %s", C_M.Fname, C_M.Lname, C_M.user, C_M.pass);

    if (strcmp(C_M.user, C_M.cuser) == 0)
    {
        if (strcmp(C_M.pass, C_M.cpass) == 0)
        {
            system("cls");
            printf("\n\n! User Logged in Successfully !\n\n");
            Time();
            dashboard();
        }
        else
        {
            printf("\n!!!!!!!Invalid Credentials!!!!!\n");
            login();
        }
    }
    else
    {
        printf("\n!!!!!!!Invalid Credentials!!!!!\n");
        login();
    }
    fclose(aa);
}

// FUNCTION TO CREATE ACCOUNT
void create()
{
    printf("---------------------------------------------------------------------------------------------------------------------------------------\n"
           "|                                                          REGISTRATION DETAILS                                                        |\n"
           "----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Enter your First Name:\t");
    scanf("%s", C_M.Fname);
    printf("Enter your Last Name:\t");
    scanf("%s", C_M.Lname);
    fflush(stdin);
    printf("Select the username:\t");
    fgets(C_M.user, 40, stdin);
    space(C_M.user);
    printf("\nEnter the password:\t");
    fgets(C_M.pass, 20, stdin);
    Time();
}

// FUNCTION TO DISPLAY ACCOUNT INFO
void confirm()
{
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n"
           "|                                                           DETAILS CONFIRMATION                                                          |\n"
           "-------------------------------------------------------------------------------------------------------------------------------------------\n");
    FILE *fp;
    fp = fopen("acc.txt", "r");
    fscanf(fp, "%s %s %s %s", &C_M.Fname, &C_M.Lname, &C_M.user, &C_M.pass);

    printf("%s           %s\n%s          %s ", C_M.Fname, C_M.Lname, C_M.user, C_M.pass);
    fclose(fp);
}

// FUNCTION TO WRITE ABOUT THEMSELVES
void bio()
{
    printf("---------------------------------------------------------------------------------------------------------------------------------------------\n"
           "|                                                            DESCRIPTION SECTION                                                            |\n"
           "---------------------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\nWhat is your hobby? - ");
    scanf("%s", &C_M.asd);
    printf("\nWhat is your Favourite Game?- ");
    scanf("%s", p.asd);
    printf("\nEnter Date of birth - ");
    scanf("%s", q.asd);
    printf("\nWhat is Your Occupation - ");
    fflush(stdin);
    fgets(t.asd, 20, stdin);
    printf("\nWhich is your favourite field,why?- ");
    scanf("%s", d.asd);
    fflush(stdin);
    printf("\nWhat is your school/College Name- ");
    fgets(s.asd, 20, stdin);
    printf("\nWhat is ur Aim? -");
    scanf("%s", f.asd);
    printf("\n Will u persue further degree?- ");
    scanf("%s", a.asd);
    fflush(stdin);
    FILE *fp;
    fp = fopen("C_M.auth", "a+");

    if (fp == NULL)
    {
        printf("File Failed to Open.");
    }
    else
    {
        // writing in the file using fgets()
        fgets(C_M.asd, 20, fp);
        fgets(p.asd, 20, fp);
        fgets(q.asd, 20, fp);
        fgets(t.asd, 20, fp);
        fgets(d.asd, 20, fp);
        fgets(s.asd, 20, fp);
        fgets(f.asd, 20, fp);
        fgets(a.asd, 20, fp);
        printf("Data has been Recorded\n");
    }
    fclose(fp);
}

// FUNCTION FOR DATABASE/STORE DATA OF USER
void database()
{
    FILE *fp;
    fp = fopen("acc.txt", "w");
    fprintf(fp, "%s %s %s %s", C_M.Fname, C_M.Lname, C_M.user, C_M.pass);
    fclose(fp);
    printf("Data has been Recorded\n");
}

// MAIN FUNCTION
int main()
{
    int ch;
    char ch1;
    printf("----------------------------------------------------------------------------------------------------------------------------------\n"
           "#########################################################    USER.IO    #########################################################\n"
           "----------------------------------------------------------------------------------------------------------------------------------\n");

    printf("|||||||||||||||||||||||||||||||||||||||||||||||||     welcome to the Management..    |||||||||||||||||||||||||||||||||||||||||||||||||||\n");

    printf("To Login Press (1)\nTo Create Account Press (2)\n To Exit code Press(0)\n\t\t\t\t");
    scanf("%d", &ch);
    switch (ch)
    {
    case 0:
        exit(0);
    case 1:
        login();
        break;
    case 2:
        create();
        database();
        printf("\nPress (c) to Confirm Details:\nPress (m) to Enter Main Menu: \n\t\t");
        scanf("%c", &ch1);
        switch (ch1)
        {
        case 'c':
            system("cls");
            confirm();
            break;
        case 'm':
            system("cls");
            main();
            break;
        }
        break;
    default:
        system("cls");
        main();
        break;
    }
    return 0;
}