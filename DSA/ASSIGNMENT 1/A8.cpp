#include<iostream>
using namespace std;
#define STACK_OVERFLOW 1
#define STACK_UNDERFLOW 2
class stack{
    private:
        int capacity;
        int top;
        int *ptr;
    public:
        stack(int);
        bool isEmpty();
        bool isFull();
        void push(int);
        int pop();
        int peek();
        ~stack();
        int getCapacity()
        {
            return capacity;
        }

        void reverse(stack &s)
        {
            stack s1(s.getCapacity());
            while(!s.isEmpty())
            {
                s1.push(s.pop());
            }
            stack s2(s1.getCapacity());
            while(!s.isEmpty())
            {
                s2.push(s1.pop());
            }
            while(!s2.isEmpty())
            {
                s.push(s2.pop());
            }
        }

        //track minimum value in stack : need to create spcial stack ;like minStack which is a class in that class we have 2 stack s and minStack; which means we are inserting a value like 32 and 32 on both and next value is 14 so we complare and push in both but after if the value is 18 we only push only in s not in minStack so minStack pop will reuturn the minimum value . we have to make sure that when there is pop in s there must be pop also in minStack if the value is same;;;
};

//create stack of specific size
stack::stack(int cap){
    // capacity = cap; // problem capacity should be positive 
    if(cap <= 0 )
        cap = 10;
    capacity = cap;
    top = -1; //-1 because there is no value in stack right now 
    ptr = new int[cap];
}
        
//an stack is empty of not 
bool stack :: isEmpty(){
    return top == -1;  // if last index is -1 than the stack is empty 
}

//push a new element
void stack :: push(int data){
    // only issue is overloading 
    if(isFull())
        throw STACK_OVERFLOW;
    ptr[top+1] = data;
    top++;
}

//is full 
bool stack::isFull(){
    return capacity = top + 1;
}


int stack :: pop(){
    int item;
    if(isEmpty())
        throw STACK_UNDERFLOW;
    item = ptr[top];
    top--;
    return item;
}

//peek element
int stack :: peek(){
    if(isEmpty())
        throw STACK_UNDERFLOW;
    return ptr[top];
}

//destructor
stack :: ~stack(){
    delete[] ptr; 
//delete is the operator for a single item.
// delete[] is the operator for an stack.
}

