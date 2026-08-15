//Circular linked list
#include<iostream>
using namespace std;
struct node{
    int item;
    node *next;
};

class cll{
    private:
        node *last;
    public:
        cll()
        {
            last = nullptr;
        }

        void insertStart(int data)
        {
            node *n;
            n->item = data;
            if(last == nullptr)
            {
                n->next = n;
                last = n;
            }
            else
            {
                n->next = last->next;//last node next contains first element and first's next contains the second element . 
                last->next = n;
            }
        }

        void insertLast(int data)
        {
             node *n;
            n->item = data;
            if(last == nullptr)
            {
                n->next = n;
                last = n;
            }
            else
            {
                n->next = last->next;//last node next contains first element and first's next contains the second element . 
                last->next = n;
                last = n;
            }
        }

        node* search(int data)
        {
            node *t;
            if(last == nullptr)
                return nullptr;
            t = last->next;
            do{
                if(t->item == data)
                    return t;
                t=t->next;
            }while(t !=last->next);
            return nullptr;
        }

        void insertAfter(node *temp , int data)
        {
            node *n ;
            if(temp != nullptr)
            {
                if(temp == last)
                    insertLast(data);
                else
                {
                n = new node;
                n->item = data;
                n->next = temp->next;
                temp->next = n;
                }
            }
        }

        void deleteStart(){
            node *t;
            if(last != nullptr){
                if(last->next == last){
                    delete last;
                    last = nullptr;
                }
                else{
                t = last->next;
                last->next = t->next;
                delete t;
                }
            }
        }

        void deleteLast(){
        node *t;
            if(last != nullptr){
                if(last->next == last){
                    delete last;
                    last = nullptr;
                }
                else{
                t = last->next;
                while(t->next != last)
                {
                    t = t->next;
                }
                t->next = last->next;
                delete last;
                last = t;
                }
            }
        }

        void deleteNode(int data){
            node *temp,*t;
            temp = search(data);
            if(temp != nullptr){
                if(last == temp)
                    deleteLast();
                else
                {
                    t = last->next; 
                    while(t->next != temp)
                    {
                        t = t->next;
                    }
                    t->next = temp->next;
                    delete temp;
                }
            }
        }

        ~cll(){
            while(last != nullptr)
                deleteStart();
        }
};