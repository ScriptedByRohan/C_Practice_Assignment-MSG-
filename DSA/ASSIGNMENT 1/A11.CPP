#include<iostream>
using namespace std;
#define Q_UNDERFLOW 1
struct node{
    int item;
    node* next;
};

class q{
    private:
        node *front;
        node *rear;
        int count; // for counting 
    public:
        q()
        {
            front = nullptr;
            rear = nullptr;
            count = 0;
        }

        bool isEmpty(){
            return front == nullptr;
        }
        
        int getFront()
        {
            if(isEmpty())
                throw Q_UNDERFLOW;
            return front->item;
        }
        
        int getRear()
        {
            if(isEmpty())
                throw Q_UNDERFLOW;
            return rear->item;
        }

        void insert(int data)//insert always last
        {
            node*n = new node;
            n->item = data;
            n->next = nullptr;
            if(isEmpty())
                front = rear = n;
            else
            {
                rear->next = n;
                rear = n;
            }
            count++;
        }

        void del()
        {
            if(isEmpty())
                throw Q_UNDERFLOW;
            if(front == rear)
            {
                delete front;
                front = rear = nullptr;
            }
            else
            {
                node *t;
                t = front ;
                front = front->next;
                delete t;
            }
            count--;
        }

        int getCount()
        {
            return count;
        }

        ~q()
        {
            while(!isEmpty())
                del();
        }


};
