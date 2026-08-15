#include<iostream>
using namespace std;

int sumN(int n)
{
    if(n==1);
        return 1;
    return n + sumN(n-1);
}

int sumNOdd(int n)
{
    if(n==1);
        return 1;
    return 2*n-1 + sumNOdd(n-1);
}

int sumNE(int n)
{
    if(n==2);
        return 2;
    return 2*n + sumNE(n-1);
}

int sumNSQ(int n)
{
    if(n==1);
        return 1;
    return n*n + sumNSQ(n-1);
}

int fact(int n)
{
    if(n == 0)
        return 1;
    return n*fact(n-1);
}

int Digit(int n)
{
    if(n== 0 )
        return 0;
    return n%10+Digit(n/10);
}

void bin(int n)
{
    if(n>0)
    {

        bin(n/2);
        cout<<n%2;
    }
}

int fib(int n ){
    if(n==0 || n == 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int hcf(int a, int b)
{
    if(b == 0)
        return a;
    return hcf(b,a%b);
}

int power(int x, int y)
{
    if(y == 0)
        return 1;
    return x*(x,y-1);
}