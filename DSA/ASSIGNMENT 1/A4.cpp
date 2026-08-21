#include<iostream>
using namespace std;
struct node{//self refrencial  structure
    int item;//int beacause we are using integer value
    node *next;
};
class sll // singely linked list
{
    private:
        node* start;
    public:
        sll();
        void insertStart(int);
        void insertLast(int);
        void insertAfter(node*,int);
        void delFirst();
        void delLast();
        void delAfter(node*);
        void delAfter(int);
        node* search(int);
        ~sll();

};

sll::sll(){
    start = nullptr;
}

void sll::insertStart(int data)
{
    node *n = new node;
    n->item = data;
    n->next = start;
    start = n;
}

void sll::insertLast(int data)
{
    node *n = new node;
    n->item = data;
    n->next = nullptr;

    node *t;
    if(start == nullptr)
        start= n;
    else
    {
        t = start;
        while(t->next != nullptr){
            t=t->next;
        }
        t->next = n;
    }
}

node* sll::search(int data){
    node *t;
    t = start;
    while(t!=nullptr)
    {
        if( t->item == data)
            return t;
        t=t->next;
    }
    return nullptr;
}

void sll::insertAfter(node *temp,int data){
    if(temp != nullptr)
    {
        //check if temp(node address) is valid node at list
        node *t;
        t = start;
        while(t != nullptr){
            if( t == temp)
                break;
            t=t->next;
        }
        if(t == nullptr)
            cout<<"Speicified node does'nt belong to list ";
        else{
            t = new node;
            t->item = data;
            t->next = temp->next;
            temp->next = t;
        }
    }
}

void sll:: delFirst(){
    if(start != nullptr)
    {
        node *t ;
        t = start;
        start = start->next;
        delete t;
    }
}

void sll:: delLast(){
    if(start != nullptr)
    {
        node *t ;
        if(start->next = nullptr)//that is single node is present only
        {
            delete start;
            start = nullptr;
        }
        else{
            t = start;
            while(t->next->next != nullptr)
            t=t->next;
        }
        delete t->next;
        t->next = nullptr;
    }
}

void sll::delAfter(node *temp)
{
    if(temp != nullptr){
    node *t = search(temp->item);
    if(t == temp){
        t = start;
        if(start == temp){
            delFirst();
        }
        else{
            while(t->next != temp)
                {// loop will stop when t is temp sa phela ala node hai
                    t=t->next;
                }
            t->next = temp->next;
            delete temp;
            }
        }
    }
}

void sll:: delAfter(int data){
    node *temp = search(data);
    if(temp != nullptr)
    {
        node *t;
        t = start;
        if(start == temp){
            delFirst();
        }
        else{
            while(t->next != temp)
                {// loop will stop when t is temp sa phela ala node hai
                    t=t->next;
                }
            t->next = temp->next;
            delete temp;
            }
    }
}

sll:: ~sll(){
    if(start != nullptr)
        delFirst();
}