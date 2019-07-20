#include<iostream>
using namespace std;

bool hasPath(int **edges, int n, bool *visited, int start, int end){
     if(start == end)
          return true;
     //std::cout << start << '\n';
     visited[start] = true;
     for(int i = 0; i < n; i++){
          if(edges[start][i]){
               if(visited[i])
                    continue;
               if(hasPath(edges,n,visited,i,end))
                   return true;
          }
     }
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
          int s,f;
          cin >> f >> s;
          edges[f][s] = 1;
          edges[s][f] = 1;
     }
     int start,end;
     cin >> start >> end;

     if(start == end){
         cout << "true" << endl;
         return 0;
     }


     if(edges[start][end]){
          cout << "true" << end;
          return 0;
     }

     bool *visited = new bool[n];
     for(int i = 0; i < n; i++)
          visited[i] = false;

     if(hasPath(edges,n,visited,start,end))
         cout << "true" << endl;
    else
        cout << "false" <<endl;

     for(int i = 0; i < n; i++)
          delete [] edges[i];
     delete [] edges;
     delete [] visited;
     return 0;
}
