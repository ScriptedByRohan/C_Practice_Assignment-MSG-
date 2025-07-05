#include<stdio.h>

//Q1
int main()
{
    int a=-1,b=1,c,n;
    printf("Enter a number");
    scanf("%d",&n);
    while(n)
    {
        c=a+b;   
        a=b;
        b=c;
        n--;
    }
    printf("%d ",c);
    printf("\n");
    return 0;
}
//Q2
int main()
{
    int a=-1,b=1,c,n;
    printf("Enter a number");
    scanf("%d",&n);
    while(n)
    {
        c=a+b;
        printf("%d ",c);
        a=b;
        b=c;
        n--;
    }
    printf("\n");
    return 0;
}
//Q3
int main()
{
    int a=-1,b=1,c=0,num;
    printf("Enter a number");
    scanf("%d",&num);

    while(c<=num)
    {
        c=a+b;
        if(num==c){
            printf("%d is in Fibonacci series",num);
            break;
        }
        a=b;
        b=c;   
    }
    if(c>num)
        printf("%d is not in Fibonacci series",num);

    printf("\n");
    return 0;
}
//Q4
int main()
{
    int num,x,count=0,sum=0,digit,i;
    printf("Enter a number");
    scanf("%d",&num);
    x=num;

    //count digits
    while(x)
    {
        x=x/10;
        count++;
    }

    //Sum of digit^count
    for(x=num;x; x=x/10)
    {
        digit=x%10;
        //calculate digit^count (say d)
        for(d=1,i=1;i<=count ;i++)
            d=d*digit;
        sum=sum+ d;
    }
    
    //Compare result with original number
    if(sum==num)
        printf("%d is an Armstrong number",num);
    else
        printf("%d is not an Armstrong number",num);
    return 0;
}
//Q5
int main()
{
    int num,x,count,sum,digit,i;
    for(num=1;num<1000;num++){
        x=num;
        count=0;
        //count digits
        while(x)
        {
            x=x/10;
            count++;
        }

        //Sum of digit^count
        for(sum=0,x=num;x; x=x/10)
        {
            digit=x%10;
            //calculate digit^count (say d)
            for(d=1,i=1;i<=count ;i++)
                d=d*digit;
            sum=sum+ d;
        }
        
        //Compare result with original number
        if(sum==num)
            printf("%d ",num);
    }
    return 0;
}
