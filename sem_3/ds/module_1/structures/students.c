/*  Create a structure STUDENT consisting of variables of structures:
        i. DOB {day, month (use pointer ), year},
        ii. STU_INFO {reg_no, name(use pointer), address},
        iii. COLLEGE {college_name (use pointer), university_name}

where structure types from i to iii are declared outside the STUDENT independently. 

Show how to read and display member variables of DOB type if pointer variable is 
created for DOB inside STUDENT and STUDENT variable is also a pointer variable.

The program should read and display the values of all members of STUDENT structure.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int day;
	char* month;
	int year;
} DOB;

typedef struct
{
	int regno;
	char* name;
	char address[50];
} STU_INFO;

typedef struct
{
	char* college_name;
	char university_name[50];
} COLLEGE;

typedef struct
{
	DOB* d;
	STU_INFO info;
	COLLEGE clg;
} STUDENT;


void read(STUDENT *s, int n)
{
	int i;
	char temp[100];
	for(i = 0; i < n; i++)
	{
		printf("\nEntering details for student %d\n", i+1);
		printf("\nEnter the day of birth: ");
		(s+i)->d = (DOB*)calloc(1,sizeof(DOB));
    	scanf("%d",&((s+i)->d->day));
    	getchar();

		printf("Enter the month of birth: ");
		gets(temp);
		((s+i)->d->month) = (char*)calloc(strlen(temp), sizeof(char));
		strcpy(((s+i)->d->month),temp);

		printf("Enter the year of birth: ");
        scanf("%d",&((s+i)->d->year));

        printf("\nEnter the registration number: ");
        scanf("%d",&((s+i)->info.regno));
        getchar();

        printf("Enter the name: ");
        gets(temp);
        (s+i)->info.name = (char*)calloc(strlen(temp), sizeof(char));
        strcpy(((s+i)->info.name),temp);

        printf("Enter the address: ");
        gets((s+i)->info.address);

        printf("\nEnter college name: ");
        gets(temp);
        (s+i)->clg.college_name = (char*)calloc(strlen(temp), sizeof(char));
        strcpy(((s+i)->clg.college_name),temp);

        printf("Enter university name: ");
        gets((s+i)->clg.university_name);
	}
}

void display(STUDENT *s,int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("\nDisplaying details for student  %d ",(i+1));
        printf("\nName: %s\nRegistration Number: %d\nCollege Name: %s\nUniversity Name: %s\nDOB: %d %s %d\nAddress: %s\n",(s+i)->info.name,(s+i)->info.regno,(s+i)->clg.college_name,(s+i)->clg.university_name,(s+i)->d->day,(s+i)->d->month,(s+i)->d->year,(s+i)->info.address);
    }
}

int main()
{
	int n;
	printf("Enter the number of students: ");
	scanf("%d", &n);

	STUDENT *s;
	s = (STUDENT*)calloc(n, sizeof(STUDENT));

	read(s,n);
	display(s,n);

	return 0;
}