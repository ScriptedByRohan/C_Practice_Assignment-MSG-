#include<iostream>
using namespace std;
#define STACK_UNDERFLOW 1;
struct node{//self refrencial  structure
    int item;//int beacause we are using integer value
    node *next;
};
class stack // singely linked list
{
    private:
        node* top;
    public:
        stack();
        void push(int);
        int pop();
        int peek()
        {
            if(isEmpty())
                return STACK_UNDERFLOW;
            return top->item;
        }
        bool isEmpty()
        {
            return top == nullptr;
        }
        ~stack();
        void reverseStack(stack &s)
        {
            stack s1;
            while(!s.isEmpty())
            {
                s1.push(s.pop());
            }
            stack s2;
            while(!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
            while(!s2.isEmpty())
            {
                s.push(s2.pop());
            }
        }

        bool palindrom(int number)
        {
            stack s;
            int length = 0,digit,i =1;
            int num = number;
            while(number){
                number/=10;
                length++;
            }
            number = num;
            while(i<=length/2){
                digit=number%10;
                s.push(digit);
                i++;
                number/=10;
            }
            if(length %2 == 1)
                number /= 10;

            while(i< length){
                digit = number % 10;
                if(digit != s.pop())
                    return false;
                number/= 10;
                i++;
            }
        }

};

stack::stack(){
    top = nullptr;
}

void stack::push(int data)
{
    node *n = new node;
    n->item = data;
    n->next = top;
    top = n;
}

int stack:: pop(){
    if(top == nullptr)
        throw STACK_UNDERFLOW;
    
        int data;
        node *t ;
        t = top;
        data - t->item;
        top = top->next;
        delete t;
        return data;
}

stack:: ~stack(){
    if(top != nullptr)
        pop();
}