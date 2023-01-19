#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NEMPLOYEES 5

struct Employee
{
    int id;
    int nop;
    char surname[10];
    char job[10];
};

void CodersInfo(struct Employee info[])
{
    int i, k = 0;
    FILE *text;
    text = fopen("coders.txt", "w"); // open txt
    for (i = 0; i < NEMPLOYEES; i++)
    {
        if (strcmp(info[i].job, "Coder") == 0)
        { // I found from stackoverflow
            if (info[i].nop > 10)
            {                                                                           // if number of project greater than 10
                fprintf(text, "%s %d %s\n", info[i].surname, info[i].nop, info[i].job); // write results
                k++;
            }
        }
    }
    fclose(text); // close txt
    printf("\n%d Coders info work more than 10 projects recorded into file! \n\n\n", k);
}

void SortEmployees(int noe, struct Employee emplist[])
{                          // this is bubble sort algorithm I implement
    struct Employee *emp1; // that code to my code
    struct Employee *emp2;
    struct Employee swap;
    int c;
    int d;
    int i;

    for (c = 0; c < noe - 1; c++)
    { // loops
        for (d = 0; d < noe - c - 1; d++)
        {
            emp1 = &emplist[d];     //define arrays
            emp2 = &emplist[d + 1]; // define array's next term
            if (emp1->nop < emp2->nop)
            {                 // condition
                swap = *emp1; // swap part
                *emp1 = *emp2;
                *emp2 = swap;
            }
        }
    }

    printf("Sorted list of employees according to the number of projects:\n");
    printf("Surname \t        Number of Projects\n");
    printf("======================================\n");
    for (i = 0; i < NEMPLOYEES; i++)
    {
        printf("\nSurname: %s\t\tNop: %d\n",
               emp1[i].surname, emp1[i].nop); //printing section
    }
}

int main(void)
{
    int i;
    struct Employee emp[NEMPLOYEES];
    printf("Enter id, surname, number of projects and job for %d employees: \n", NEMPLOYEES);
    for (i = 0; i < NEMPLOYEES; i++)
    {
        scanf("%d %s %d %s",
              &emp[i].id, &emp[i].surname, &emp[i].nop, &emp[i].job);
    }
    CodersInfo(emp);
    SortEmployees(NEMPLOYEES, emp);
    system("pause");
    return 0;
}
