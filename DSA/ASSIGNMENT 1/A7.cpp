#include<iostream>
using namespace std;
struct node{
    node *prev;
    int item;
    node *next;  
};

class cdll{
    private:
        node *start;
    public:
        cdll()
        {
            start = nullptr;
        }

        void insertS(int data)
        {
            node *n = new node;
            n->item = data;
            if(start == nullptr){
                n->next = n;
                n->prev = n;
                start = n;
            }
            else
            {
                n->next = start;
                n->prev = start->prev;
                start->prev->next=n;
                start->prev = n;
                start = n;
            }
        }

        void insertE(int data)
        {
            node *n = new node;
            n->item = data;
            if(start == nullptr){
                n->next = n;
                n->prev = n;
                start = n;
            }
            else
            {
                n->next = start;
                n->prev = start->prev;
                start->prev->next = n;
                start->prev = n;
            }
        }

        node* search(int data)
        {
            node *t;
            if(start == nullptr)
                return nullptr;
            t = start;
            do
            {
                if(t->item == data)
                    return t;
                t=t->next;
            }while(t->next != start);
            return nullptr;
        }

        void insertA(node* temp,int data)
        {
            node *n;
            if(temp != nullptr)
            {
                n= new node;
                n->item = data;
                n->next = temp->next;
                n->prev = temp;
                temp->next->prev = n;
                temp->next = n;
            }
        }

        void delStart()
        {
            node *t;
            if(start != nullptr)
            {
                t = start;
                start->prev->next = start->next;
                start->next->prev = start->prev;
                if(start -> next == start)
                    start = nullptr;
                else
                    start = start->next;
                delete t;
            }
        }

        void delLast()
        {
            node *t;
            if(start != nullptr)
            {
                t = start->prev;
                if(start == start->next)
                {
                    delete start;
                    start = nullptr;
                }
                else{
                    t->prev->next = start;
                    start->prev = t->prev;
                    delete t;
                }
            }
        }

        void delNode(int data)
        {
            node* temp = search(data);
            if(temp != nullptr){
                if(start == temp)
                {
                    delStart();
                }
                else
                {
                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;
                    delete temp;
                }
            }
        }

        ~cdll(){
            while(start!=nullptr)
                delStart();
        }
};
