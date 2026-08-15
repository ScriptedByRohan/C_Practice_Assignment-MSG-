#include<iostream>
using namespace std;
struct node{
    int item;
    int vertex;
    int edge;
    node* next;
};

class AdjList
{
    private:
        node *start;
        int vertex;
    public:
        AdjList()
        {
            start = nullptr;
        }

        AdjList(int v)
        {   
            start = nullptr;
            vertex = v; 
        }

        node *GetStart()
        {
            return start;
        }
        void setVertex(int v)
        {
            vertex = v; 
        }
        void addVertex(int v ,int data)
        {

            node *n = new node;
            n->item = data;
            n->vertex = v;
            n->next = start;
            start = n;
        }
        void RemoveNode()
        {
            node *r;
            if(start)
            {   
                r = start;
                start = start->next;
                delete r;
            }
        }
        void printList()
        {
            node *t = start;
            while(t)
            {   
                cout<<" ("<<t->vertex<<","<<t->item<<")";
                t=t->next;
            }
        }
        ~AdjList()
        {
            while(start)
                RemoveNode();
        }
};

class graph{
    private:
        int v_count;
        AdjList *arr;
    public:
    graph()
    {
        v_count = 0;
        arr=nullptr;
    }
    int getVcount(){}
    void createGraph(int vno)
    {
        int n,v,data;
        v_count = vno;
        arr = new AdjList[v_count];
        for(int i = 0 ; i < v_count ; i++)
        {
            arr[i].setVertex(i);
            cout<<"\n how many adjacent node of v";
            cin>>n;
            for (int j = 0; j < n; j++)
            {
                cout<<"Enter vertx number";
                cin>>v;
                cout<<"Enter data item fot this vertex";
                cin>>data;
                arr[i].addVertex(v,data);
            }
        }
    }

    void PrintGraph()
    {
        for(int i = 0 ; i <v_count ; i++)
        {
            cout<<endl;
            arr[i].printList();
        }
    }

    ~graph()
    {
        delete[] arr;
    }

};