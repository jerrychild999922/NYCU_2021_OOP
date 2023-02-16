#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999999

int main() {

    int n,e;
    cin>>n>>e;
    int G[n][n];
    int a;
    int b;
    int c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            G[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        cin>>a>>b>>c;
        G[a][b]=c;
        G[b][a]=c;
    }
    clock_t start = (int)clock();
    int sum=0;
    int no_edge;  
    int selected[n];
    memset(selected, false, sizeof(selected));
    no_edge = 0;
    selected[0] = true;

    int x; 
    int y;  

    while (no_edge < n - 1) {

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < n; i++) {
        if (selected[i]) {
            //cout<<i;
            
            for (int j = 0; j < n; j++) {
            if (!selected[j] && G[i][j]) { 
                if (min > G[i][j]) {
                min = G[i][j];
                x = i;
                y = j;
                }
            }
            }
            //cout<<x<<y<<endl;
        }
        
        }
       
        sum=sum+ G[x][y];
        selected[y] = true;
        no_edge++;
    }
    cout<<sum<<endl;
    printf("%0.5fms", (float)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
    }
