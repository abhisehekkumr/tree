#include<iostream>
#include<vector>
using namespace std;

void dfs(int **edges, int n, bool *visited, int start){
     visited[start] = true;
     for(int i = 1; i <= n; i++){
          if(i == start)
               continue;
          if(edges[start][i] && !visited[i])
          dfs(edges,n,visited,i);
     }
}

int ConnectedComponenets(int **edges, int n,int m, vector<int> u, vector<int> v){
     bool *visited = new bool[n+1];
     for(int i = 0; i <= n; i++)
          visited[i] = false;

     for(int i = 0; i < m; i++){
          edges[u[i]][v[i]] = 1;
          edges[v[i]][u[i]] = 1;
     }

     int count = 0;
     for(int i = 1; i <= n; i++){
          if(!visited[i]){
               count += 1;
               dfs(edges,n,visited,i);
          }
     }
     return count;
}

int main(){
     int n,m;
     cin >> n >> m;

     int **edges = new int*[n+1];
     for(int i = 0; i <= n; i++){
          edges[i] = new int[n+1];
          for(int j = 0; j <= n; j++)
               edges[i][j] = 0;
     }

     vector<int> u;
     vector<int> v;
     for(int i = 0; i < m; i++){
          int c;
          cin >> c;
          u.push_back(c);
     }

     for(int i = 0; i< m; i++){
          int c;
          cin >> c;
          v.push_back(c);
     }

     std::cout << ConnectedComponenets(edges,n,m,u,v) << '\n';
}
