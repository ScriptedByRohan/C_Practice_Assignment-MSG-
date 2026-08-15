#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
void bubbleSort(int a[],int size)
{
    int r,i,t;
    for(r = 1; r< size; r++)
    {
        for(i = 0;i<size-1;i++)
        {
            if(a[i] > a[i+1])
            {
                t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
            }
        }
    }
}

void ModifiedbubbleSort(int a[],int size)
{
    int r,i,t;
    bool flag;
    for(r = 1; r< size; r++)
    {
        flag = false;
        for(i = 0;i<size-1;i++)
        {
            if(a[i] > a[i+1])
            {
                flag = true;
                t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
            }
        }
        if(flag == false)
            break;
    }
}

void insertionSort(int a[], int size)
{
    int i,j,temp;
    for( i =1;i<size;i++)
    {
        temp = a[i];
        for(j = i-1;j>= 0 ; j--)
        {
            if(temp<a[j])
                a[j+1] = a[j];
            else    
                break;
        }
        a[j+1] = temp;
    }
}

int minValueIndex(int a[] , int size, int j)//j for from where we are searchinh)
    {
        int i , min , minIndex;
        min= a[j];
        minIndex = j;
        for(i = j+1; i<= size ; i++)
        {
            if(min>a[i])
            {
                min=a[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

void selectionSort(int a[], int size)
{
    int t,i,minIndex;
    for(i = 0 ; i <= size-2 ; i++)
    {
        minIndex = minValueIndex(a,size,i);
        t = a[i];
        a[i] = a[minIndex];
        a[minIndex] = t;
    }
}

int quick(int a[], int left , int right)
{
    int loc = left;
    int t;

    while(left<right)
    {
        while (left<right && a[loc]<= a[right])
            right--;
        if(left == right)
            break;
        t = a[loc];
        a[loc] = a[right];
        a[right] = t;
        loc = right;
        while(left<right && a[left] <= a[loc])
            left++;
        if(left == right)
            break;
        t = a[loc];
        a[loc] = a[left];
        a[left] = t;
        loc = left;        
    }
    return loc;
}

void quicSort(int a[], int l, int u)
{
    int loc = quick(a,l,u);
    if(loc>l+1)
        quicSort(a,l,loc-1);
    if(loc<u-1)
        quicSort(a,loc+1,u);
}

void QuickSortLoop(int a[], int l , int u)
{
    int loc,i,j;
    stack<int,deque<int>> lower;
    stack<int,deque<int>> upper;
    lower.push(l);
    upper.push(u);
    while(!lower.empty())
    {
        i = lower.top();
        j = upper.top();
        loc = quick(a,i,j);
        lower.pop();
        upper.pop();
        if(loc>i+1)
        {
            lower.push(i);
            upper.push(loc-1);
        }
        if(loc<j-1)
        {
            lower.push(loc+1);
            upper.push(j);
        }
    }
}

void merging(int A[],int l,int m,int u)
{
    int L[m-l+1],R[u-m],i,j,k;
    for(i=0;i<m-l+1;i++)
        L[i]=A[l+i];
    for(j=0;j<u-m;j++)
        R[j]=A[m+1+j];
    for(i=0,j=0,k=l;i<m-l+1 && j<u-m;k++)
    {
        if(L[i]<R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
    while(i<m-l+1)
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<u-m)
    {
        A[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int A[],int l,int u)
{
    int m;
    if(l<u)
    {
        m=(l+u)/2;
        mergeSort(A,l,m);
        mergeSort(A,m+1,u);
        merging(A,l,m,u);
    }
}

//Merge Sort using loop
void merge(int a[],int n1,int i1,int b[],int n2,int i2,int c[],int i3)
{
    int i,j,k;
    for(i=0,j=0,k=0;i<n1 && j<n2; k++)
    {
        if(a[i+i1]<b[j+i2])
        {
            c[k+i3]=a[i+i1];
            i++;
        }
        else
        {
            c[k+i3]=b[j+i2];
            j++;
        }
    }
    while(i<n1)
    {
        c[k+i3]=a[i+i1];
        i++;
        k++;
    }
    while(j<n2)
    {
        c[k+i3]=b[j+i2];
        j++;
        k++;
    }
}
void mergepass(int SRC[],int size,int L,int DEST[])
{
    int j,mergeCount,index,R,S;
    mergeCount=size/2*L;
    S=mergeCount*2*L;
    R=size-S;
    for(j=0;j<mergeCount;j++)
    {
        index=j*2*L;
        merge(SRC,L,index,SRC,L,index+L,DEST,index);
    }
    if(R<=L)
    {
        for(int i=0;i<R;i++)
            DEST[S+i]=SRC[S+i];
    }
    else
        merge(SRC,L,S,SRC,R-L,S+L,DEST,S);
}
void mergeSortLoop(int A[],int size)
{
    int L=1,B[size];
    while(L<size)
    {
        mergepass(A,size,L,B);
        mergepass(B,size,2*L,A);
        L=L*4;
    }
}
class Employee
{
    private:
        int empid;
        char name[20];
        float salary;
    public:
        void setEmpid(int id) { empid=id;}
        void setName(char n[]) { strcpy(name,n);}
        void setSalary(float s) { salary=s;}
        int getEmpid() { return empid;}
        char* getName() { return name;}
        float getSalary() { return salary;}
};
void merging(Employee A[],int l,int m,int u)
{
    Employee L[m-l+1],R[u-m];
    int i,j,k;
    for(i=0;i<m-l+1;i++)
        L[i]=A[l+i];
    for(j=0;j<u-m;j++)
        R[j]=A[m+1+j];
    for(i=0,j=0,k=l;i<m-l+1 && j<u-m;k++)
    {
        if(L[i].getSalary()<R[j].getSalary())
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
    while(i<m-l+1)
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<u-m)
    {
        A[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(Employee A[],int l,int u)
{
    int m;
    if(l<u)
    {
        m=(l+u)/2;
        mergeSort(A,l,m);
        mergeSort(A,m+1,u);
        merging(A,l,m,u);
    }
}
int quick(Employee A[],int left,int right)
{
    int loc=left;
    Employee t;

    while(left<right)
    {
        while(left<right && (strcmp(A[loc].getName(),A[right].getName())<=0))
            right--;
        if(left==right)
            break;
        t=A[loc];
        A[loc]=A[right];
        A[right]=t;
        loc=right;
        while(left<right && (strcmp(A[left].getName(),A[loc].getName())<=0))
            left++;
        if(left==right)
            break;
        t=A[loc];
        A[loc]=A[left];
        A[left]=t;
        loc=left;
    }
    return loc;
}
void quickSort(Employee A[],int l,int u)
{
    int loc;
    loc=quick(A,l,u);
    if(loc>l+1)
        quickSort(A,l,loc-1);
    if(loc<u-1)
        quickSort(A,loc+1,u);
}