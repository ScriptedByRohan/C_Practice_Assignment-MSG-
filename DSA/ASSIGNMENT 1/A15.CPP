#include<iostream>
using namespace std;
void printN(int n)
{
    if(n>0)
    {
        printN(n-1);
        cout<<n;
    }
}
void printRev(int n)
{
    if(n>0)
    {
        cout<<n;
        printRev(n-1);
    }
}
void printNodd(int n)
{
    if(n>0)
    {
        printNodd(n-1);
        cout<<2*n-11;
    }
}
void printRevodd(int n)
{
    if(n>0)
    {
        cout<<n*2-1;
        printRevodd(n-1);
    }
}
void printNE(int n)
{
    if(n>0)
    {
        printNodd(n-1);
        cout<<2*n;
    }
}
void printRevE(int n)
{
    if(n>0)
    {
        cout<<n*2;
        printRevE(n-1);
    }
}
void printSquare(int n)
{
    if(n>0)
    {
        printSquare(n-1);
        cout<<n*n;
    }
}
void printRevE(int n)
{
    if(n>0)
    {
        cout<<n*n;
        printSquare(n-1);
    }
}

