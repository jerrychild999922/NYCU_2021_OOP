
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    
    int V, E;
    struct Edge* edge;
};
 
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}
 

 
int main()
{
    int n,e;
    cin>>n>>e;
    int first,des,a,b,c;
    cin>>first>>des;

    struct Graph* graph = createGraph(n, e);

    for(int i=0;i<e;i++){
        cin>>a>>b>>c;
        graph->edge[i].src = a;
        graph->edge[i].dest = b;
        graph->edge[i].weight = c;
    }
    clock_t start = (int)clock();
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = 100000;
    dist[first] = 0;
 
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != 100000 && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    int jud=0;
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != 100000 && dist[u] + weight < dist[v]) {
            jud=1;
            //printf("Graph contains negative weight cycle");
            break;
        }
    }
    
    if(jud){
        cout<<"Negative loop detected!"<<endl;
    }
    else{
        cout<<dist[des]<<endl;
    }
    printf("%0.5fms", (float)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}