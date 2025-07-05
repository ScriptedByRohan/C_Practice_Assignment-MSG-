#include<stdio.h>
//Q1
// int main()
// {
//     int i,x;

//     for(x=2;x<100;x++)
//     {
//         for(i=2;i<x;i++)
//         {
//             if(x%i==0)
//                 break;
//         }
//         if(i==x)
//             printf("%d ",x);
//     }
//     printf("\n");
//     return 0;
// }
//Q2
// int main()
// {
//     int i,x,a,b;
//     printf("Enter two numbers");
//     scanf("%d%d",&a,&b);

//     for(x=a+1;x<b;x++)
//     {
//         for(i=2;i<x;i++)
//         {
//             if(x%i==0)
//                 break;
//         }
//         if(i==x)
//             printf("%d ",x);
//     }
//     printf("\n");
//     return 0;
// }
//Q3
int main()
{
    int i,x,num;
    printf("Enter a number");
    scanf("%d",&num);

    for(x=num+1;;x++)
    {
        for(i=2;i<x;i++)
        {
            if(x%i==0)
                break;
        }
        if(i==x){
            printf("%d ",x);
            break;
        }
    }
    printf("\n");
    return 0;
}
//Q4
int main()
{
    int H,a,b;
    printf("Enter two numbers");
    scanf("%d%d",&a,&b);

    for(H=a<b?a:b;H>=1;H--)
    {
        if(a%H==0 && b%H==0)
        {
            printf("HCF is %d",H);
            break;
        }
    }
    printf("\n");
    return 0;
}
//Q5
int main()
{
    int H,a,b;
    printf("Enter two numbers");
    scanf("%d%d",&a,&b);

    for(H=a<b?a:b;H>=1;H--)
    {
        if(a%H==0 && b%H==0)
        {
            break;
        }
    }
    if(H==1)
        printf("%d and %d are co-prime numbers",a,b);
    else
        printf("%d and %d are not co-prime numbers",a,b);
    printf("\n");
    return 0;
}