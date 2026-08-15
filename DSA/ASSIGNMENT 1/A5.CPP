#include<iostream>
using namespace std;

struct node
{
    node *prev;
    int item;
    node *next;
};

class dll{
    private:
        node *start;
    public:
        dll();
        void insertStart(int);
        void insertLast(int);

        node* search(int data){
            node *t = start;
            while (t != nullptr)
            {
                if(t->item == data){
                    return t;
                }
                t= t->next;
            }
            return nullptr;
        }

        void insertAfter(node* temp,int data)
        {
            node *n;
            if(temp != nullptr)
            {
                n = new node;
                n->item = data;
                n->prev = temp;
                n->next = temp->next;
                if(temp->next!=nullptr){
                    temp->next->prev = n;
                }
                temp->next = n;
            }
        }

        void deleteFirst()
        {
            node *t;
            if(start != nullptr)
            {
                if(start->next == nullptr)
                {
                    delete start;
                    start = nullptr;
                }
                else
                {
                    t = start;
                    t->next->prev = nullptr;
                    start = t->next;
                    delete t;
                }
            }
        }

        void deleteLast()
        {
            node *t;
            if(start != nullptr)
            {
                if(start->next == nullptr)
                {
                    delete start;
                    start = nullptr;
                }
                else
                {
                    t = start;
                    while(t->next->next != nullptr)
                    {
                        t = t->next;
                    }
                    delete t->next;
                    t->next = nullptr;
                }
            }
        }

        ~dll()
        {
            while(start != nullptr)
                deleteFirst();
        }
};

dll::dll(){
    start = nullptr;
}

void dll::insertStart(int data){
    node *n = new node;
    n->item = data;
    n->prev = nullptr; // inserting at start so it is pointing towards the null as it is first element 
    n->next = start;

    if(start != nullptr)
        start->prev = n;
    start = n;
}

void dll::insertLast(int data){
    node *n = new node;
    node *t;
    n->item = data;
    n->next = nullptr;

    if(start == nullptr)
    {
        n->prev = nullptr;
        start = n;
    }
    else
    {
        t = start;
        while(t->next != nullptr){
            t = t->next;
        }
        n->prev = t;
        t->next = n;
    }
}