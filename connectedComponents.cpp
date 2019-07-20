#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void getDfs(int **edges, int n, bool *visited, vector<int> &k, int start){
     k.push_back(start);
     visited[start] = true;
     for(int i = 0; i < n; i++){
          if(i == start)
               continue;
          if(edges[start][i] && !visited[i])
               getDfs(edges,n,visited,k,i);
     }
}

void getConnectedComponents(int **edges, int n, vector<vector<int>> &v){
     bool *visited = new bool[n];
     for(int i = 0; i < n; i++)
          visited[i] = false;

     for(int i = 0; i < n; i++){
          vector<int> k;
          if(!visited[i]){
               getDfs(edges,n,visited,k,i);
               v.push_back(k);
          }
     }
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

     vector<vector<int>> v;
     getConnectedComponents(edges,n,v);
     for(int i = 0; i < v.size(); i++){
          sort(v[i].begin(),v[i].end());
          for(int j = 0; j < v[i].size(); j++)
               std::cout << v[i][j] << ' ';
          std::cout << '\n';
     }

     for(int i = 0; i < n; i++)
          delete [] edges[i];
     delete [] edges;
}
