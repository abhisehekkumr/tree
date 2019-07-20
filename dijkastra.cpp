#include<iostream>
#include<climits>
using namespace std;

inline int min(int a, int b){
     return a < b ? a : b;
}

void disjkastra(int **arr, int n){
     bool *visited = new bool[n];
     for(int i = 0; i < n; i++)
          visited[i] = false;

     int *weight = new int[n];
     for(int i = 0; i < n; i++)
          weight[i] = INT_MAX;

     weight[0] = 0;

     for(int i = 0; i < n-1; i++){
          int minVertex;
          int val = INT_MAX;
          for(int j = 0; j < n; j++){
               if(val > weight[j] && !visited[j]){
                    minVertex = j;
                    val = weight[j];
               }
          }
          visited[minVertex] = true;
          for(int j = 0; j < n; j++){
               if(arr[minVertex][j] && !visited[j]){
                    weight[j] = min(weight[j], arr[minVertex][j] + weight[minVertex]);
               }
          }
     }

     for(int i = 0; i < n; i++)
          std::cout << i << " " <<  weight[i] << '\n';

     delete [] visited;
     delete [] weight;
}

int main(){
     int n,e;
     cin >> n >> e;

     int **arr = new int*[n];
     for(int i = 0; i < n; i++){
          arr[i] = new int[n];
          for(int j = 0; j < n; j++)
               arr[i][j] = 0;
     }

     for(int i = 0; i < e; i++){
          int u,v,w;
          cin >> u >> v >> w;
          arr[u][v] = w;
          arr[v][u] = w;
     }

     disjkastra(arr,n);

     for(int i = 0; i < n; i++)
          delete [] arr[i];
     delete [] arr;
     return 0;
}
