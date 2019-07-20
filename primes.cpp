#include<iostream>
#include<climits>
using namespace std;

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

     int *parent = new int[n];
     for(int i = 0; i < n; i++)
          parent[i] = -1;

     int *weight = new int[n];
     for(int i = 0; i < n; i++)
          weight[i] = INT_MAX;

     bool *visited = new bool[n];
     for(int i = 0; i < n; i++)
          visited[i] = false;
     weight[0] = 0;

     for(int i = 0; i < n; i++){
          int par = INT_MAX;
          int index;
          for(int j = 0; j < n; j++){
               if(weight[j] < par && !visited[j]){
                    par = weight[j];
                    index = j;
               }
          }
          visited[index] = true;
          for(int i = 0; i < n; i++){
               if(arr[index][i] && !visited[i]){
                    if(arr[index][i] < weight[i]){
                         weight[i] = arr[index][i];
                         parent[i] = index;
                    }
               }
          }
     }

     //std::cout << "/* message */" << '\n';
     //for(int i = 0; i < n; i++)
     //     std::cout << i << " " << parent[i] << '\n';
     //std::cout << "/* message */" << '\n';
     for(int i = 1; i < n; i++){
          int smallest = i < parent[i] ? i : parent[i];
          int largest = i > parent[i] ? i : parent[i];
          std::cout << smallest << " " << largest << " " << weight[i] << '\n';
     }
}
