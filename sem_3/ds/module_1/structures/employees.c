/*  Samuel wants to store the data of his employees, which includes the following fields: 
        (i) Name of the employee 
        (ii) Date of birth which is a collection of {day, month, year} 
        (iii) Address which is a collection of {house number, zip code and state}. 
    
    Write a 'C' program to read and display the data of N employees using pointers to array of structures.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int day;
	char month[10];
	int year;
} DOB;

typedef struct
{
	char house[20];
	int zip;
	char state[15];
} ADDRESS;

typedef struct
{
	char name[20];
	DOB d;
	ADDRESS addr;
} EMP;

void read(EMP *s, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("\nInputting details for employee %d", i+1);
		printf("\nEnter the name: ");
		gets((s+i)->name);

		printf("\nEnter the day of birth: ");
		scanf("%d",&((s+i)->d.day));
		getchar();

		printf("Enter the month of birth: ");
		gets((s+i)->d.month);

		printf("Enter the year of birth: ");
		scanf("%d",&((s+i)->d.year));
		getchar();

		printf("\nEnter the street address: ");
		gets((s+i)->addr.house);

		printf("Enter the ZIP code: ");
		scanf("%d",&((s+i)->addr.zip));
		getchar();

		printf("Enter the state: ");
		gets((s+i)->addr.state);
	}
}

void display(EMP *s, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("\nDisplaying details for employee %d", i+1);
		printf("\nName: %s",(s+i)->name);

		printf("\nDate of Birth: %d %s %d",(s+i)->d.day,(s+i)->d.month,(s+i)->d.year);

		printf("\nAddress: %s %s %d\n",(s+i)->addr.house, (s+i)->addr.state, (s+i)->addr.zip);
	}
}

int main()
{
	int n;
	printf("Enter the number of employees: ");
	scanf("%d", &n);
	getchar();

	EMP *e;
	e = (EMP *)calloc(n, sizeof(EMP));

	read(e,n);
	display(e,n);

	return 0;
}