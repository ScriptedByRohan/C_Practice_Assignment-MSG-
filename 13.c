#include<stdio.h>
int main(){
    int a;
    int sum = 0;
    printf("Enter a number");
    scanf("%d",&a);
    // for (int i = 0; i <= a; i++)
    // {
    //     sum = sum + i;
    // }
    // printf("The sum of natural number using loop is %d",sum); 

    // for (int i = 0; i <= a; i++)
    // {
    //     if (i % 2 == 0)
    //     {
    //         sum = sum + i;
    //     }
        
    // }
    // printf("The sum of even natural number using loop is %d \n",sum); 

    // sum = 0;

    // for (int i = 0; i <= a; i++)
    // {
    //     if (i % 2 != 0)
    //     {
    //         sum = sum + i;
    //     }
        
    // }
    // printf("The sum of odd natural number using loop is %d",sum); 

    // int square = 1;
    // for (int i = 0; i <= a; i++)
    // {
    //     square = i*i;
    //     sum = sum + square;
    // }
    // printf("The sum of the square of natural number using loop is %d",sum); 

    int square = 1;
    for (int i = 0; i <= a; i++)
    {
        square = i*i*i;
        sum = sum + square;
    }
    printf("The sum of the square of natural number using loop is %d",sum); 


}