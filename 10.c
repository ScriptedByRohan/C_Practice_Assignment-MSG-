#include<stdio.h>
int main(){
    // int a = 10;
    // if (a == 0)
    // {
    //     printf("Number is zero");
    // }
    // else if (a > 0)
    // {
    //     printf("Number is greater than 0 means positive");
    // }
    // else
    // {
    //     printf("The number is negative");
    // }

    int a,b,c,d;
    a = 3 ;
    b = 2 ;
    c = 1 ;
    if (a + b > c && b + c > a && a + c > b )
    {
        printf("Triangle");
    }
    else{
        printf("Not a triangle");
    }

}