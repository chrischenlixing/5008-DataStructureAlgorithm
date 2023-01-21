//enter your name here
//enter your email here
#include<stdio.h>
int main()
{
    int a,b,c, choice;
    
    printf("Enter your choice\n");
    printf(" 1.addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n");
    scanf("%d",&choice);
    
    printf("Enter a and b values");
    scanf("%d %d", &a, &b);
    
    // Add your code here using switch
    
        switch (choice){
        case 1:
            c = a+b;
            printf("Sum = %d",c);
            break;
        case 2:
            c = a-b;
            printf("Difference = %d",c);
            break;
        case 3:
            c = a*b;
            printf("Product = %d",c);
            break;
        case 4:
            if (b == 0) {
                printf("Divide by zero error");
                break;
            }else{
            int quotient = a/b;
            int remainder = a%b;
            printf("Quotient = %d\n",quotient);
            printf("Remainder = %d\n",remainder);
            break;
            }
        default:
            printf("Invalid option");
            break;

        }		       
    return 0;
}
