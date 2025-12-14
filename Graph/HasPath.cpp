#include<bits/stdc++.h>
using namespace std;
class Graph{
     int V;
     list<int>* l;
     public:
        Graph(int V){
            this->V=V;
            l=new list<int>[V];
        }
        void addEdge(int u,int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }
        void printGraph(){
            for(int i=0;i<V;i++){
                cout<<"Vertex:"<<i<<"->";
                list<int> neighbour=l[i];
                for(int v:neighbour){
                    cout<<v<<" ";
                }
                cout<<endl;
            }
        }
        bool hasPathHelper(int src,int dest,vector<bool>&visit){
            if(src==dest){
                return true;
            }
            visit[src]=true;
            for(int v:l[src]){
              if(!visit[v]){
                   if(hasPathHelper(v,dest,visit)){
                    return true;
                }
              }
            }
            return false;
        }
       bool hasPath(int src,int dest){
         vector<bool>visit(V,false);
         return hasPathHelper(src,dest,visit)  ;
       }
       
};
int main()
{   
    Graph graph(7);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(3,1);
    graph.addEdge(4,2);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    // graph.addEdge(5,6);
    bool isPath=graph.hasPath(0,6);
    cout<<isPath<<endl;
    return 0;
}