#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int>*l;// declare array of list
    public:
       Graph(int V){
        this->V=V;
        l=new list<int>[V];// initialized array of list
       }
       void addEdge(int u,int v){// (U)---(V) node
            l[u].push_back(v);
            l[v].push_back(u);
       }
       void print(){
          for(int i=0;i<V;i++){
            cout<<"Vertex:"<<i<<"->";
             list<int> neibour=l[i];
             for(int v:neibour){
                cout<<v<<" ";
             }
            cout<<endl;

         }
       }
};
int main()
{   
    Graph graph(5);
    graph.addEdge(0,1);
     graph.addEdge(1,2);
      graph.addEdge(3,1);
       graph.addEdge(2,3);
        graph.addEdge(2,4);
        graph.print();

    return 0;
}