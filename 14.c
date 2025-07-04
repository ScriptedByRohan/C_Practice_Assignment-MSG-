#include<stdio.h>
int main(){
    // int a;
    // int fact = 1;
    // int count = 0;
    // printf("Enter a number");
    // scanf("%d",&a);
    // for (int i = 1; i <= a; i++)
    // {
    //     fact = fact * i; 
    // }
    // printf("%d ",fact);

    
    // int i = a;
    // while (i != 0)
    // {
    //     i = i /10;
    //     count++;
    // }
    // printf("%d",count);

    // int prime = 1;
    // int i = 2;
    // while (i <= a/2)
    // {
    //     if (a % i == 0)
    //     {
    //         prime = 0;
    //         break;
    //     }
    //     i++;
    // }
    // if (prime)
    // {
    //     printf("%d is prime",a);
    // }
    
    // else{
    //     printf("%d is not prime",a);
    // }
    
    // int a, b, l;
    // printf("Enter number for lcm");
    // scanf("%d%d",&a,&b);
    
    // for (l= a>b?a:b ; l <= a*b ; l++)
    // {
    //     if (l%a == 0 && l%b == 0 )
    //     {
    //         break;
    //     }
    // }
    // printf("LCM is %d",l);
    
    int a,y=0,r;
    printf("enter");
    scanf("%d",&a);

    while (a)
    {
        r = a % 10 ;
        y = y * 10 + r;
        a = a / 10;
    }
    
    printf("%d",y);
}