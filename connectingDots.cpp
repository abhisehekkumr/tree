#include<iostream>
using namespace std;

void makeFalse(bool **visited, int n, int m){
     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++)
          visited[i][j] = false;
     }
}

bool isCycleExits(char **graph, int n, int m, int x, int y, int i, int j, bool **visited, char c, int  k = 0){
     if(i == x && j == y && k >= 4)
          return true;

     if(i < 0 || i >= n)
          return false;

     if(j < 0 || j >= m)
          return false;

     if(graph[i][j] != c)
          return false;

     if(visited[i][j])
          return false;

     visited[i][j] = true;
     //std::cout << i << " " << j << " " << k << '\n';
     if(isCycleExits(graph,n,m,x,y,i-1,j,visited,c,k+1))
          return true;

     if(isCycleExits(graph,n,m,x,y,i+1,j,visited,c,k+1))
          return true;

     if(isCycleExits(graph,n,m,x,y,i,j-1,visited,c,k+1))
          return true;

     if(isCycleExits(graph,n,m,x,y,i,j+1,visited,c,k+1))
          return true;

     visited[i][j] = false;
     return false;
}

bool findCycle(char **graph, int n, int m){
     bool **visited = new bool*[n];
     for(int i = 0; i < n; i++)
          visited[i] = new bool[m];

     makeFalse(visited,n,m);
     bool flag = false;
     for(char c = 'A'; c <= 'A'; c++){
          for(int i = 0; i < n; i++){
               for(int j = 0; j < m; j++){
                    if(isCycleExits(graph,n,m,i,j,i,j,visited,c)){
                         flag = true;
                         break;
                    }
                    else
                         makeFalse(visited,n,m);
               }
               if(flag)
                    break;
          }
          if(flag)
               break;
     }

     for(int i = 0; i < n; i++)
          delete [] visited[i];
     delete [] visited;
     return flag;
}

int main(){
     int n,m;
     cin >> n >> m;

     char **graph = new char*[n];
     for(int i = 0; i < n; i++){
          graph[i] = new char[m];
          for(int j = 0; j < m; j++)
               cin >> graph[i][j];
     }
     std::cout << findCycle(graph,n,m) << '\n';

     for(int i = 0; i < n; i++)
          delete [] graph[i];
     delete [] graph;
     return 0;
}
