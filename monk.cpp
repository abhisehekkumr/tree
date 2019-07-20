#include<iostream>
#include<climits>
using namespace std;

inline int min(int a, int b){
     return a < b ? a : b;
}

int disjkastra(int **arr, int n){
     bool *visited = new bool[n+1];
     for(int i = 0; i <= n; i++)
          visited[i] = false;

     int *weight = new int[n+1];
     for(int i = 0; i <= n; i++)
          weight[i] = INT_MAX;
     weight[1] = 0;

     for(int i = 1; i <= n; i++){
          int minVertex;
          int val = INT_MAX;

          for(int j = 1; j <= n; j++){
               if(val > weight[j] && !visited[j]){
                    val = weight[j];
                    minVertex = j;
               }
          }
          visited[minVertex] = true;
          for(int j = 1; j <= n; j++){
               if(arr[minVertex][j] && !visited[j]){
                    weight[j] = min(weight[j], 1 + weight[minVertex]);
               }
          }
     }

     int ans = weight[n];
     delete [] visited;
     delete [] weight;
     return ans;
}

int main(){
     int t;
     cin >> t;
     while (t--) {
          int n,m;
          cin >> n >> m;
          int **arr = new int*[n+1];
          for(int i = 0; i <= n; i++){
               arr[i] = new int[n+1];
               for(int j = 0; j <= n; j++)
                    arr[i][j] = 0;
          }
          for(int i = 0; i < m; i++){
               int u,v;
               cin >> u >> v;
               arr[u][v] = 1;
               arr[v][u] = 1;
          }
          std::cout << disjkastra(arr,n) << '\n';
          for(int i = 0; i <= n; i++)
               delete [] arr[i];
          delete [] arr;
     }

}
