#include<iostream>
using namespace std;
#define Q_UNDERFLOW 1;
struct node{
    int item;
    node *prev;
    node *next;
};

class deque{
    private:
        node *front , *rear;
    public:
    deque()
    {
        front = rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    int getFront()
    {
        if(isEmpty())
            return Q_UNDERFLOW;
        return front->item;
    } 

    int getRear()
    {
        if(isEmpty())
            return Q_UNDERFLOW;
        return rear->item;
    } 

    void insertFront(int data)
    {
        node *n = new node;
        n->prev = nullptr;
        n->item = data;
        n->next = front;

        if(!isEmpty())
        {
            front->prev = n;
            front = n;
        }
        else
        {
            front=rear=n;
        }
    }
    void insertRear(int data)
    {
        node *n = new node;
        n->prev = rear;
        n->item = data;
        n->next = nullptr;
         if(!isEmpty())
        {
            rear->next = n;
            rear = n;
        }
        else
        {
            front=rear=n;
        }

    }

    void delFront()
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
        t = front;
        front = front->next;
        front->prev = nullptr;
        delete t;
        }
    }
    void delRare()
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
            t = rear;
            rear = rear->prev;
            rear->next = nullptr;
            delete t;
        }
    }

    ~deque()
    {
        while(!isEmpty())
            delFront();
    }
};