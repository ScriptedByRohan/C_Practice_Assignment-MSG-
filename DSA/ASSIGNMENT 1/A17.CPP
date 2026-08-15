#include<iostream>
using namespace std;
#define INVALID_INDEX 1;
class GraphMatrix
{
    private:
        int v_count;
        int e_count;
        int **adj;
    public:
        void createGraph(int vno, int eno)
        {
            int u,v;
            v_count = vno;
            e_count = eno;
            adj = new int*[v_count]; // array of pointer jitna node hai utna hee
            for(int i = 0 ; i <v_count;i++)
                adj[i] = new int[v_count];
            for(int i = 0 ; i <v_count;i++)
                for(int j = 0; j<v_count ; j++)
                    adj[i][j] = 0;
            for(int k = 1 ; k<=e_count;k++)
            {
                cout<<"Enter node number connecting edge";
                cin>>u>>v; // value is given like (1,2) that represent 1---2
                adj[u][v] = 1;
                adj[v][u] = 1;
            }            
        }

        void printMatrix()
        {
            cout<<endl;
            for(int i = 0 ; i<v_count; i++)
            {
                for(int j = 0; j<v_count ; j++)
                    cout<<adj[i][j]<<" ";
                cout<<endl;
            }
        }

        void PrintAdjacentNodes(int v)
        {
            if(v>=v_count || v<0)
                throw INVALID_INDEX;
            for(int i = 0 ; i < v_count ; i++)
            {
                if(adj[v][i] == 1)
                    cout<<" "<<"V"<<i;
            }
        }

        bool IsolatedNode(int v)
        {
            bool flag = true;
            if(v>=v_count || v < 0)
                throw INVALID_INDEX;
            for(int i = 0 ; i<v_count ; i++)
                if(adj[v][i] == 1)
                {
                    flag = false;
                    cout<<endl<<"V"<<i;
                }
            return flag;
        }

        ~GraphMatrix()
        { 
            for(int i = 0 ; i<v_count; i++)
                delete[]adj[i];
            delete []adj;
        }
};