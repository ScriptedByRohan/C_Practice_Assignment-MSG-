#include<stdio.h>
int main(){
    int a ;
    printf("Enter a number");
    scanf("%d",&a);
    // if (a < 0 )
    // {
    //     printf("%d is Negative number",a);
    // }
    // else if (a > 0)
    // {
    //     printf("%d is Positive number",a);
    // }
    // else{
    //     printf("%d is Zero",a);
    // }
    
    // if (a % 5 == 0)
    // {
    //     printf("It\'s divisible by 5");
    // }
    // else{
    //     printf("It\'s not divisible by 5");
    // }
    
    // if (a % 2 == 0)
    // {
    //     printf("It\'s an even number");
    // }
    // else{
    //     printf("It\'s not an even number5");
    // }

    // int c = a / 2;
    // if(a == 2*c ){
    //     printf("ok");
    // }
    // else
    // {
    //     printf("no");
    // }
    
       if (a & 1) {
        printf("%d is odd.\n", a);
    } else {
        printf("%d is even.\n", a);
    }

}