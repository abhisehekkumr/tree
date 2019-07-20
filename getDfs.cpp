#include<iostream>
#include<vector>
using namespace std;

bool getDfs(int **edges, int n, bool *visited, int start, int end, vector<int> &v){
     if(start == end){
          v.push_back(end);
          return true;
     }
     visited[start] = true;
     v.push_back(start);
     for(int i = 0; i < n; i++){

         if(i == start)
            continue;

          if(edges[start][i] && !visited[i]){
               if(getDfs(edges,n,visited,i,end,v))
                    return true;
          }
     }
     v.pop_back();
     return false;
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

     int start,end;
     cin >> start >> end;

    if(start == end)
        return 0;

     bool *visited = new bool[n];
     for(int i = 0; i < n; i++)
          visited[i] = false;

     std::vector<int> v;
     getDfs(edges,n,visited,start,end,v);

     if(v.size()){
          for(int i = v.size()-1; i >= 0; i--)
               std::cout << v[i] << ' ';
          std::cout << '\n';
     }

     for(int i = 0; i < n; i++)
          delete [] edges[i];

     delete [] edges;
     delete [] visited;
     return 0;
}
