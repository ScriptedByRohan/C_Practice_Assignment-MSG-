#include<iostream>
using namespace std;
#define P_EMPTY 1
struct node{
    int item;
    int pno;
    node *next;
};
class p
{
    private:
        node *start;
    public:
        p()
        {
            start = nullptr;
        }

        void insert(int data,int pno)
        {
            node *t;
            node *n = new node;
            n->item = data;
            n->pno = pno;
            n->next = nullptr;
            if(start == nullptr || pno > start->pno)
            {
                n->next = start;
                start = n;
            }
            else
            {
                t = start;
                while(t->next != nullptr && t->next->pno >= pno)
                {
                    t = t->next;
                }
                n->next = t->next;
                t->next = n;
            }
        }

        void del()
        {
            if(start == nullptr)
                throw P_EMPTY;
            node *t;
            t = start;
            delete t;
        }

        int getHighestpriorityyElement()
        {
            if(start == nullptr)
                throw P_EMPTY;
            return start->item;
        }
        int getHighestpriorityNumber()
        {
            if(start == nullptr)
            throw P_EMPTY;
            return start->pno;
        }
        ~p()
        {
            while(start != nullptr)
                del();
        }

        bool isEmpty()
        {
            return start == nullptr;
        }
};