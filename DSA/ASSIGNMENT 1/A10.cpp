#include<iostream>
using namespace std;
#define OVER_FLOW 1;
#define UNDER_FLOW 2;
class q{
    private:
        int capacity;
        int front,rear;
        int *ptr;

    public:
        q(int cap)
        {
            if(cap <= 0)
                capacity = 10;
            capacity = cap;
            front = rear = -1;
            ptr = new int[cap];
        }

        void insert(int data)
        {
            if(isFull())   
                throw OVER_FLOW;
            if(rear == -1)//empty
            {   
                front = rear = 0;
                ptr[rear] = data;
            }
            else if(rear = capacity-1)//front not 0
            {
                rear = 0;
                ptr[rear] = data;
            }
            else
            {
                rear ++;
                ptr[rear] = data;
            }


        }

        bool isFull()
        {
            return(front == 0 and rear == capacity-1|| rear+1 == front);
        }
        bool isEmpty()
        {
            return front==-1;
        }

        int getF()
        {
            if(isEmpty())
                throw UNDER_FLOW;
            return ptr[front];
        }

        int getR()
        {
            if(isEmpty())
                throw UNDER_FLOW;
            return ptr[rear];
        }

        void delf(){
            if(isEmpty())
                throw UNDER_FLOW;
            if(rear == front)
            {
                front = rear = -1;
            }
            else if(front == capacity-1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
        }

        ~q(){
            delete ptr;
        }

        //count 
        int count()
        {
            if(rear >= front)
            {
                return rear-front+1;
            }
            if(front > rear)
            {
                return capacity+1-front-rear;
            }
            if(isEmpty())
                return 0;
        }
};