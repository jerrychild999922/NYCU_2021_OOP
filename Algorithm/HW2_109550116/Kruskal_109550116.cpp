#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
class Edge{
public:
    int src;
    int dest;
    int wt;
};
 
bool compare(Edge e1,Edge e2){
    return e1.wt<e2.wt;
}
 
int getParent(int v,int parent[]){
    if(parent[v]==v){
        //cout<<"yes";
        return v;
    }
    //cout<<"no";
    return getParent(parent[v],parent);
}
 
int main()
{
    int n,E;
    int sum;
    cin>>n>>E;
    Edge edges[E];
    for(int i=0;i<E;i++){
        cin>>edges[i].src>>edges[i].dest>>edges[i].wt;
    }
    
    //Kruskal algo
    
    //sorted the edges array in increasing order
    clock_t start = (int)clock();
    sort(edges,edges+E,compare);
    
    //Edge output[n-1];
    
    //Union find algorithm to detect cycle
    int parent[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    
    int count=0;
    int i=0;
    while(count<n-1){
        Edge currentEdge=edges[i];
        //cout<<currentEdge.src;
        //cout<<parent[currentEdge.src];
        int p1=getParent(currentEdge.src,parent);
        //cout<<"\n";
        //cout<<currentEdge.dest;
        //cout<<parent[currentEdge.dest];
        int p2=getParent(currentEdge.dest,parent);
        //cout<<"\n";
        
        if(p1!=p2){
            //output[count]=currentEdge;
            count++;
            parent[p1]=p2;
            sum=sum+currentEdge.wt;
        }
        i++;
    }
    
    /*Printing the MST
    for(int i=0;i<n-1;i++){
        if(output[i].src<output[i].dest){
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].wt<<endl;
        }
        else cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].wt<<endl;
    }*/
    cout<<sum<<endl;
    printf("%0.5fms", (float)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}