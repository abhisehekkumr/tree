#include<iostream>
using namespace std;

void DFS(int **edges, int n, bool *visited, int start){
     visited[start] = true;
     for(int i = 0; i < n; i++){
          if(i == start)
               continue;

          if(edges[start][i] && !visited[i])
               DFS(edges,n,visited,i);
     }
}

bool isConnected(int **edges, int n){
     bool *visited = new bool[n];
     for(int i = 0; i < n; i++)
          visited[i] = false;
     DFS(edges,n,visited,0);
     for(int i = 0; i < n; i++){
          if(!visited[i])
               return false;
     }
     return true;
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

     if(isConnected(edges,n))
          std::cout << "true" << '\n';
     else
          std::cout << "false" << '\n';

     for(int i = 0; i < n; i++)
          delete [] edges[i];
     delete [] edges;
     return 0;
}
