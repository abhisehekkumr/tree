#include<iostream>
#include<queue>
using namespace std;

void printBFS(int **arr, int n, int start){
     bool *visited = new bool[n];
     for(int i = 0; i < n; i++)
          visited[i] = false;
     queue<int> q;
     q.push(start);

     while(!q.empty()){
          int vertex = q.front();
          q.pop();
          std::cout << vertex << ' ';
          visited[start] = true;
          for(int i = 0; i < n; i++){
               if(arr[vertex][i]){
                    if(visited[i])
                         continue;
                    q.push(i);
                    visited[i] = true;
               }
          }
     }
     std::cout << '\n';
     delete [] visited;
}

int main(){
     int n,e;
     cin >> n >> e;

     int **edges = new int*[n];
     for(int i = 0; i < n; i++){
          edges[i] = new int[n];
          for(int j = 0; j < n; j++)
               edges[i][j] = 0;
     }

     for(int i = 0; i < e; i++){
          int f,s;
          cin >> f >> s;
          edges[f][s] = 1;
          edges[s][f] = 1;
     }

     printBFS(edges,n,0);

     for(int i = 0; i < n; i++)
          delete [] edges[i];
     delete [] edges;
     return 0;
}
