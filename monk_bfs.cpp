#include<iostream>
#include<queue>
using namespace std;

int levelOrder(int **arr, int n){

     bool *visited = new bool[n+1];
     for(int i = 0; i <= n; i++)
          visited[i] = false;

     queue<int> q;
     q.push(-1);
     q.push(1);
     int level = 0;
     visited[1] = true;
     while(!q.empty()){
          int vertex = q.front();
          q.pop();

          if(vertex == -1){
               level += 1;
               q.push(-1);
               continue;
          }

          for(int i = 1; i <= n; i++){
               if(arr[vertex][i] && !visited[i]){
                    if(i == n)
                         return level;
                    q.push(i);
                    visited[i] = true;
               }
          }
     }
     return level;
}

int main(){
     int t;
     cin >> t;

     while(t--){
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

          std::cout << levelOrder(arr,n) << '\n';
     }
}
