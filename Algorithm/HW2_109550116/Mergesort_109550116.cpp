#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;



void merge(int arr[], int l, int m, int r)
{
    int a = m - l + 1;
    int b = r - m;
 
    int L[a], R[b];
 
    for (int i = 0; i < a; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < b; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < a && j < b) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < a) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < b) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}



int main()
{
    int n;
    while(1){
        cin>>n;
        int arr[n];
        if(n==0){
            break;
        }
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        clock_t start = (int)clock();
        mergeSort(arr, 0, n-1);
        printf("%0.5fms", (float)(clock() - start) / CLOCKS_PER_SEC);
        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";}
        cout<<"\n";
    }
    return 0;
}