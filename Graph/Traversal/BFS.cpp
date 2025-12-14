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
        void bfs(int src){
            queue<int>q;
            q.push(src);
              vector<bool>visit(V,false);
            visit[src]=true;
            while(!q.empty()){
                 int curr=q.front();
                 q.pop();
                 cout<<curr<<" ";
                 for(int v:l[curr]){
                     if(!visit[v]){
                        q.push(v);
                        visit[v]=true;
                     }
                 }
            }
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
    graph.addEdge(5,6);
    graph.bfs(3);
    return 0;
}