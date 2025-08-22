#include <stdio.h>

int main()
{
    int a, b, c, d, option;

    printf ("Enter the first number: ");
    scanf("%d", &a);
    
    printf ("Enter the second number: ");
    scanf("%d", &b);
    
    printf ("Enter the third number: ");
    scanf("%d", &c);
    
    printf ("Enter the option: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        d = a+b+c;
        printf("Addition is %d+%d+%d = %d",a,b,c, d);
        break;
    
    case 2:
        d = a-b-c;
        printf("Subtraction is %d-%d-%d = %d",a,b,c, d);
        break;
    
    case 3:
        d = a*b*c;
        printf("Multiplication is %d*%d*%d = %d",a,b,c,d);
        break;
    
    case 4:
        d = a/b/c;
        printf("Division is %d/%d/%d = %d",a,b,c,d);
        break;
    
    default:
        break;
    }

}