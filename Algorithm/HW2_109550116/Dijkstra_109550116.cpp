#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <stdio.h>
using namespace std;


int minDistance(int dist[], bool sptSet[],int V)
{
    
    int min = 10000, min_index;
  
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
  
/*void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}*/

/*void dijkstra(int graph[][], int src, int V)
{
    int dist[V]; 
    bool sptSet[V]; 

    for (int i = 0; i < V; i++)
        dist[i] = 10000, sptSet[i] = false;

    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {

        //printSolution(dist);
        int u = minDistance(dist, sptSet,V);
        //cout<<u<<endl;

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != 10000
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
  

    //printSolution(dist);
}*/
  

int main()
{
    int n,e;
    cin>>n>>e;
    int G[n][n];
    int first,des,a,b,c;
    cin>>first>>des;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            G[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        cin>>a>>b>>c;
        G[a][b]=c;
    }
  
    //dijkstra(G, first,n);
    clock_t start = (int)clock();
    int dist[n]; 
    bool sptSet[n]; 

    for (int i = 0; i < n; i++)
        dist[i] = 10000, sptSet[i] = false;

    dist[first] = 0;
    for (int count = 0; count < n - 1; count++) {

        int u = minDistance(dist, sptSet,n);
        /*cout<<u<<endl;
        printf("Vertex \t\t Distance from Source\n");
        for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);*/

        sptSet[u] = true;

        for (int v = 0; v < n; v++)
            if (!sptSet[v] && G[u][v] && dist[u] != 10000
                && dist[u] + G[u][v] < dist[v])
                dist[v] = dist[u] + G[u][v];

    }
    cout<<dist[des]<<endl;
    printf("%0.5fms", (float)(clock() - start) / CLOCKS_PER_SEC);



  
    return 0;
    }