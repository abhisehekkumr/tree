#include<iostream>
#include<string>
using namespace std;

void makeFalse(bool **visited, int n, int m){
     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++)
               visited[i][j] = false;
     }
}

bool found(char **graph, int n, int m, int i, int j, bool **visited, string pattern){

     if(pattern.size() == 0)
          return true;

     if(i < 0 || i >= n)
          return false;

     if(j < 0 || j >= m)
          return false;

     if(visited[i][j])
          return false;

     if(pattern[0] != graph[i][j])
          return false;

     visited[i][j] = true;
     //std::cout << i << " " << j << '\n';
     if(found(graph,n,m,i-1,j-1,visited,pattern.substr(1)))
          return true;

     if(found(graph,n,m,i-1,j,visited,pattern.substr(1)))
          return true;

     if(found(graph,n,m,i-1,j+1,visited,pattern.substr(1)))
          return true;

     if(found(graph,n,m,i,j-1,visited,pattern.substr(1)))
          return true;

     if(found(graph,n,m,i,j+1,visited,pattern.substr(1)))
          return true;

     if(found(graph,n,m,i+1,j-1,visited,pattern.substr(1)))
          return true;

     if(found(graph,n,m,i+1,j,visited,pattern.substr(1)))
          return true;

     if(found(graph,n,m,i+1,j+1,visited,pattern.substr(1)))
          return true;

     visited[i][j] = false;
     return false;
}


bool findNinaja(char **graph, int n, int m){
     bool **visited = new bool*[n];
     for(int i = 0; i < n; i++){
          visited[i] = new bool[m];
          for(int j = 0; j < m; j++)
               visited[i][j] = false;
     }

     bool flag = false;
     string pattern = "CODINGNINJA";

     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
               if(graph[i][j] == 'C'){
                    if(found(graph,n,m,i,j,visited,pattern)){
                         flag = true;
                         break;
                    }
               }
               else{
                    //std::cout << "/* message */" << '\n';
                    makeFalse(visited,n,m);
               }
          }
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

     std::cout << findNinaja(graph,n,m) << '\n';
}
