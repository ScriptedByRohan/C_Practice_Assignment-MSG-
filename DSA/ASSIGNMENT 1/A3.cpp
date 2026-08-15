//dynamic dynArray
//Now here we change the size like double it or reduce it double so we need to chages old function also like append, etc.
#include<iostream>
using namespace std;
#define ARRAY_OVERFLOW 1
#define INVALID_INDEX 2
class dynArray{
    private:
        int capacity;
        int lastindex;
        int *ptr;

    protected:
        void doublearray();
        void halfarray();

    public:
        //create dyndynArray of specific size
        dynArray(int);

        //an dyndynArray is empty of not 
        bool isEmpty();

        //dyndynArray is full
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

        ~dynArray();
};

//create dynArray of specific size
dynArray::dynArray(int cap){
    // capacity = cap; // problem capacity should be positive 
    if(cap <= 0 )
        cap = 10;
    capacity = cap;
    lastindex = -1; //-1 because there is no value in dynArray right now 
    ptr = new int[cap];
}
        
//an dynArray is empty of not 
bool dynArray :: isEmpty(){
    return lastindex == -1;  // if last index is -1 than the dynArray is empty 
}

//append a new element
void dynArray :: append(int data){
    // only issue is overloading 
    if(isFull())
        doublearray();//size increased
    ptr[lastindex+1] = data;
    lastindex++;
}

//is full 
bool dynArray::isFull(){
    return capacity = lastindex + 1;
}

//insert at specific index
void dynArray :: insert(int index, int data){
    //check for overflow
    if(index < 0 || index > lastindex + 1)
        throw INVALID_INDEX;
    if(isFull)
        doublearray();
    int i;
    for ( i = lastindex; i >= index ; i--)
    {
        ptr[i+1] = ptr[i];
    }
    ptr[index] = data;
    lastindex++;
}

//edit at specific 
void dynArray :: edit(int index, int data){
    if(index < 0 || index > lastindex+1)
        throw INVALID_INDEX;
    ptr[index] = data;
}

//delete
void dynArray :: del(int index){
     if(index < 0 || index > lastindex+1)
        throw INVALID_INDEX;
    int i ;
    for(int i = index ;i<lastindex;i++){
        ptr[i] = ptr[i+1];
    }
    lastindex--;
    if(capacity > 1 && lastindex < capacity/2) //suppose capacity 8 and last index is at 3 so this will run
        halfarray();

}

//get element
int dynArray :: get(int index){
    if(index < 0 || index > lastindex+1)
        throw INVALID_INDEX;
    return ptr[index];
}

//count elements
int dynArray :: count(){
    return lastindex+1;
}

//destructor
dynArray :: ~dynArray(){
    delete[] ptr; 
//delete is the operator for a single item.
// delete[] is the operator for an dynArray.
}

//find 
int dynArray :: find(int data){
    for(int i = 0 ; i <= lastindex ; i++)
        if(ptr[i] == data)
            return i;
    return -1;
}

void dynArray:: doublearray(){
    int *temp;
    temp = new int[capacity*2];
    for (int i = 0; i < lastindex; i++)
        temp[i] = ptr[i];
    delete[] ptr;
    ptr = temp;
    capacity *= 2;
}

void dynArray :: halfarray(){
    int *temp;
    temp = new int[capacity/2];
    for (int i = 0; i < capacity; i++)
        temp[i] = ptr[i];
    delete[] ptr;
    ptr = temp;
    capacity /= 2;    
}
