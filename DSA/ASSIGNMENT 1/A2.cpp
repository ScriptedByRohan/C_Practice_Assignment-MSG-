#include<iostream>
using namespace std;
#define ARRAY_OVERFLOW 1
#define INVALID_INDEX 2
class array{
    private:
        int capacity;
        int lastindex;
        int *ptr;
    public:
        //create array of specific size
        array(int);

        //copy constructor
        array(array&);

        //copy assignment 
        array& operator=(array&);

        //an array is empty of not 
        bool isEmpty();

        //array is full
        bool isFull();

        //append a new element
        void append(int);

        //insert at specific index
        void insert(int, int);

        //edit at specific 
        void edit(int , int);

        //delete
        void del(int);

        //get element 
        int get(int);

        //count elements
        int count();

        //find 
        int find(int);

        ~array();
};

//create array of specific size
array::array(int cap){
    // capacity = cap; // problem capacity should be positive 
    if(cap <= 0 )
        cap = 10;
    capacity = cap;
    lastindex = -1; //-1 because there is no value in array right now 
    ptr = new int[cap];
}
        
//an array is empty of not 
bool array :: isEmpty(){
    return lastindex == -1;  // if last index is -1 than the array is empty 
}

//append a new element
void array :: append(int data){
    // only issue is overloading 
    if(isFull())
        throw ARRAY_OVERFLOW;
    ptr[lastindex+1] = data;
    lastindex++;
}

//is full 
bool array::isFull(){
    return capacity = lastindex + 1;
}

//insert at specific index
void array :: insert(int index, int data){
    //check for overflow
    if(index < 0 || index > lastindex + 1)
        throw INVALID_INDEX;
    if(isFull)
        throw ARRAY_OVERFLOW;
    int i;
    for ( i = lastindex; i >= index ; i--)
    {
        ptr[i+1] = ptr[i];
    }
    ptr[index] = data;
    lastindex++;
}

//edit at specific 
void array :: edit(int index, int data){
    if(index < 0 || index > lastindex+1)
        throw INVALID_INDEX;
    ptr[index] = data;
}

//delete
void array :: del(int index){
     if(index < 0 || index > lastindex+1)
        throw INVALID_INDEX;
    int i ;
    for(int i = index ;i<lastindex;i++){
        ptr[i] = ptr[i+1];
    }
    lastindex--;
}

//get element
int array :: get(int index){
    if(index < 0 || index > lastindex+1)
        throw INVALID_INDEX;
    return ptr[index];
}

//count elements
int array :: count(){
    return lastindex+1;
}

//destructor
array :: ~array(){
    delete[] ptr; 
//delete is the operator for a single item.
// delete[] is the operator for an array.
}

//find 
int array :: find(int data){
    for(int i = 0 ; i <= lastindex ; i++)
        if(ptr[i] == data)
            return i;
    return -1;
}

//copy constructor 
array :: array (array &arr)
{
    capacity = arr.capacity;
    lastindex = arr.lastindex;
    ptr = new int[capacity];
    for(int i = 0 ; i <= lastindex ; i++)
        ptr[i] = arr.ptr[i];
}

//copy assignment 
// it is not running on creation of oject like copy constructor we have to realase the memory of first array 
array& array :: operator = (array &arr)
{
    delete[] ptr;
    capacity = arr.capacity;
    lastindex = arr.lastindex;
    ptr = new int[capacity];
    for(int i = 0 ; i <= lastindex ; i++)
        ptr[i] = arr.ptr[i];
    return *this;
}