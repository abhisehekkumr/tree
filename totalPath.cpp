#include<iostream>
typedef long long ll;
using namespace std;

ll paths(int n, int m, int i = 0, int j = 0){

     if(i == n-1 && j == m-1)
          return 1;

     if(i < 0 || j < 0 || i >= n || j >= m)
          return 0;
     return paths(n,m,i+1,j) + paths(n,m,i,j+1);
}

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          int n,m;
          cin >> n >> m;
          ll arr[n][m];
          for(int i = 0; i < n; i++)
               arr[i][0] = 1;

          for(int i = 0; i < m; i++)
               arr[0][i] = 1;

          for(int i = 1; i < n; i++){
               for(int j = 1; j < m; j++)
                    arr[i][j]  = arr[i-1][j] + arr[i][j-1];
          }
          std::cout << arr[n-1][m-1] << '\n';
          std::cout << paths(n,m) << '\n';
     }
}
