#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* prototype of functions
The first function is used to enter the correct password to start the program.
The Second One is used to search for the employee name you need.
*/
void enterPassword();
void searchName();

/*creation of a structure that includes 2 members */
struct employee_info
{
    char name[20];
    int salary;
};

struct employee_info emp[5] = {{"Ahmed" , 1500 } , {"Mostafa" , 1650} , {"Talaat" , 1800} ,
    {"Rasha" , 2000} , {"Mohamed" , 1450}};

/*Main Entry*/
int main(void)
{
    /*Calling the Function */
    enterPassword();
    return 0;
}

/*Defining the Function*/
void enterPassword()
{
    unsigned char i;
    unsigned int password;

    /*you have 3 trials to enter the correct password*/
    for(i = 0; i < 3; i++)
    {
        puts("please , enter the correct password");
        scanf("%d" , &password);
        if(password == 4444)
        {
            /*Calling the Function*/
            searchName();
        }
        else
            puts("wrong password!\n\n");

    }
}

void searchName()
{
    while(1)
            {
                char name_search[15];
                int i , test , index = -1;
                puts("please , enter the name of the employee you are searching for");
                /*request name from user*/
                scanf("%s" , name_search);
                for(i = 0; i < strlen(emp); i++)
                {
                    test = strcmp(name_search , emp[i].name);
                    /* name == employeeNames[i]*/
                    if(test == 0)
                    {
                        index = i;
                        break;
                    }
                }
                if(index == -1)
                    puts("This name is not Found\n\n");
                else
                    printf("The Salary of %s is %d \n" , emp[index].name , emp[index].salary);
            }
}
