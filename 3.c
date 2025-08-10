#include<stdio.h>
int main()
{
    char str[100];
    int i=0;
    printf("enter the expression = ");
    gets(str);

    while(str[i] !='\0')
    {

        if(str[i] ==' ')
        {
            i++;
            continue;

        }
        if((str[i] >='a' && str[i] <='z') || (str[i] >='A' && str[i] <='Z'))
        {
            printf("identifier %c",str[i]);
            i++;
        }

         else if(str[i] >='0' && str[i] <='9')
        {
                   printf("numebr = ");
                 while(str[i] >='0' &&  str[i] <='9')
                 {
                     printf("%c",str[i]);
                     i++;
                 }
                printf("\n");

        }

        else if (str[i] == '(' || str[i] == ')') {
            printf("PARENTHESIS: %c\n", str[i]);
            i++;
        }
        // OPERATOR (anything else that’s not space, letter, number, parenthesis)
        else {
            printf("OPERATOR: %c\n", str[i]);
            i++;
        }
    }
    return 0;
}












