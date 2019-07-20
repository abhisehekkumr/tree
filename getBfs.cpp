#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

vector<int> getBfs(int **edges, int n, int start, int end){

     bool *visited = new bool[n];
     for(int i = 0; i < n; i++)
          visited[i] = false;
     vector<int> v;
     unordered_map<int,int> m;
     queue<int> q;
     q.push(start);
     m[start] = start;
     visited[start] = true;
     bool flag = false;
     while(!q.empty()){
          int current = q.front();
          q.pop();
          for(int i = 0; i < n; i++){
               if(i == current)
                    continue;
               if(edges[current][i] && !visited[i]){
                    q.push(i);
                    m[i] = current;
                    visited[i] = true;

                    if(i == end){
                         flag = true;
                         break;
                    }
               }
          }
     }

     if(flag){
          int i = end;
          v.push_back(end);
          while(i != start){
               v.push_back(m[i]);
               i = m[i];
          }
     }
     return v;
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
          int s,f;
          cin >> s >> f;
          edges[f][s] = 1;
          edges[s][f] = 1;
     }
     int start,end;
     cin >> start >> end;
     if(start == end)
          return 0;
     vector<int> v = getBfs(edges,n,start,end);
     if(v.size()){
          for(int i = v.size()-1; i >= 0; i--)
               std::cout << v[i] << ' ';
          std::cout << '\n';
     }
     for(int i = 0; i < n; i++)
          delete [] edges[i];
     delete [] edges;
     return 0;
}
