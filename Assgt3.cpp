#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int src;
        int dest;
        int wt;

        Edge(int src, int dest, int wt){
            this->src = src;
            this->dest = dest;
            this->wt = wt;
        }
};

void bellmanford(list<Edge> graph[], int src,int vt){
    int dist[vt];
    int pred[vt];
    list<int> path;
    for(int i=0;i<vt;i++){
        if(i!=src){
            dist[i] = INT16_MAX;
        }
        else{
            dist[i]= 0;
        }
    }

    for(int i=0;i<vt-1;i++){
        for(int j=0;j<vt;j++){
            for(auto it:graph[j]){
                int u = it.src;
                int v = it.dest;
                int wt = it.wt;

                if(dist[u]+wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    pred[v] = u;
                }
            }
        }
    }


    cout<<"Vertex"<<"\t"<<" Distance from source"<<"\t"<<"Path from source"<<endl;
    for(int i=0;i<vt;i++){
        cout<<i<<"\t\t"<<dist[i]<<"\t\t";

        int p = i;
        vector<int> path;
        while(p != src){
            path.push_back(p);
            p = pred[p];
        }

        cout<<src;
        for(int j=path.size()-1;j>=0;j--){
            cout<<"->"<<path[j];
        }
        cout<<endl;
    }
}

int main(){
    // int v = 5;
    int v;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    list<Edge> graph[v];

    for(int i=0;i<v;i++){
        graph[i] = list<Edge>();
    }

    int e;
    cout<<"Enter the number of edges: ";
    cin>>e;

    int src,dest,w;
    for(int i=0;i<e;i++){
        cout<<"Enter src, dest, weight: ";
        cin>>src>>dest>>w;
        graph[src].push_back(Edge(src,dest,w));
    }

    // // 0 vertex
    // graph[0].push_back(Edge(0,1,2));
    // graph[0].push_back(Edge(0,2,4));

    // // 1 vertex
    // graph[1].push_back(Edge(1,2,-4));
    
    // // 2 vertex
    // graph[2].push_back(Edge(2,3,2));

    // // 3 vertex
    // graph[3].push_back(Edge(3,4,4));

    // // 4 vertex
    // graph[4].push_back(Edge(4,1,-1));
    
    cout<<"Src"<<"\t"<<"Dest"<<"\t"<<"Weight"<<endl;
    for(int i=0;i<v;i++){
        for(auto it:graph[i]){
            cout<<it.src<<"\t"<<it.dest<<"\t"<<it.wt<<endl;
        }
    }
    cout<<endl;

    bellmanford(graph,0,v);


    return 0;
}