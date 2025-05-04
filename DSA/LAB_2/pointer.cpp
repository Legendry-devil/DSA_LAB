#include<cstdio>
#include<cstdlib>
#include<cmath>

void Display()
{
    printf("\t\t\t              MENU                \n");
    printf("\t\t\t----------------------------------\n");
    printf("\t\t\t       Choose Your Choice\n");
    printf("\t\t\t----------------------------------\n");
    printf("\t\t\t1.Palindrome number: \n");
    printf("\t\t\t2.Armstrong number: \n");
    printf("\t\t\t3.Perfect number: \n");
    printf("\t\t\t4.Exit: \n");
    printf("\t\t\t----------------------------------\n");
}

int check_palindrome(int* number)
{
    int *original = (int*)malloc(sizeof(int));
    int *temporary = (int*)malloc(sizeof(int));
    int *reverse = (int*)malloc(sizeof(int));
    *original=*number;
    *temporary=*number;
    *reverse=0;

    while(*temporary>0)
    {
        *reverse=(*reverse*10)+(*temporary%10);
        *temporary/=10;
    }
    
    int result=(*original==*reverse);
    free(original);
    free(temporary);
    free(reverse);
    return result;
}

int check_armstrong_number(int* number)
{
    int *original = (int*)malloc(sizeof(int));
    int *sum = (int*)malloc(sizeof(int));
    int *temporary = (int*)malloc(sizeof(int));
    int *digits = (int*)malloc(sizeof(int));

    *original=*number;
    *temporary=*number;
    *sum=0;
    *digits=0;

    while(*temporary>0)
    {
        (*digits)++;
        *temporary/=10;
    }

    *temporary=*number;

    while(*temporary>0)
    {
        *sum+=(int)pow(*temporary%10,*digits);
        *temporary/=10;
    }
    
    int result=(*original==*sum);
    free(original);
    free(sum);
    free(temporary);
    free(digits);

    return result;
}

int check_perfect_number(int* number)
{
    int *original = (int*)malloc(sizeof(int));
    int *i = (int*)malloc(sizeof(int));
    int *sum = (int*)malloc(sizeof(int));
    *original=*number;
    *sum=0;
    *i=1;
    while(*i<=(*original/2))
    {
        if(*original%*i==0)
        {
            *sum+=*i;
        }
        (*i)++;
    }
    int result=(*original==*sum);
    free(original);
    free(sum);
    free(i);
    return result;
}

int main()
{
    int *choice = (int*)malloc(sizeof(int));
    int *number = (int*)malloc(sizeof(int));
    int result;

    printf("Enter the number you want to check: ");
    scanf("%d",number);

    Display();
    while(1)
    {
        printf("\tEnter your choice: ");
        scanf("%d",choice);
        if(*choice>=1&&*choice<=4)
        {
            break;
        }
        else
        {
            printf("INVALID INPUT\n");
            printf("Please enter a number from 1 to 4: \n");
        }
    }
    switch(*choice)
    {
        case 1:
            printf("\n\tYou have choosen to check for palindrome number...... \n");
            result=check_palindrome(number);
            if(result)
            {
                printf("\tThe entered number is a palindrome number.\n");
                printf("\t------------------------------------------\n");
                printf("\t\t   ----CODE EXITED----\n");
                break;
            }
            else
            {
                printf("\tThe entered number is not a palindrome number.\n");
                printf("\t----------------------------------------------\n");
                printf("\t\t   ----CODE EXITED----\n");
                break;
            }

        case 2:
            printf("\n\tYou have choosen to check for Armstrong number...... \n");
            result=check_armstrong_number(number);
            if(result)
            {
                printf("\tThe entered number is a Armstrong number.\n");
                printf("\t-----------------------------------------\n");
                printf("\t\t   ----CODE EXITED----\n");
                break;
            }
            else
            {
                printf("\tThe entered number is not a Armstrong number.\n");
                printf("\t---------------------------------------------\n");
                printf("\t\t   ----CODE EXITED----\n");
                break;
            }

        case 3:
            printf("\n\tYou have choosen to check for Perfect number...... \n");
            result=check_perfect_number(number);
            if(result)
            {
                printf("\tThe entered number is a Perfect number.\n");
                printf("\t---------------------------------------\n");
                printf("\t\t   ----CODE EXITED----\n");
                break;
            }
            else
            {
                printf("\tThe entered number is not a Perfect number.\n");
                printf("\t-------------------------------------------\n");
                printf("\t\t   ----CODE EXITED----\n");
                break;
            }

        case 4:
            printf("\tYou have choosen to exit the code.....\n\n");
            printf("\t\t\t----EXITING THE CODE----\n");
            printf("\t\t\t------CODE EXITED------\n");
            break;
    }
}