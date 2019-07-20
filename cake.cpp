#include<iostream>
using namespace std;

inline int max(int a, int b){
     return a > b ? a : b;
}

void makeFalse(bool **visited, int n){
     for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++)
               visited[i][j] = false;
     }
}
int count = 0;
int largestBite(char **arr, int n, int i, int j, bool **visited){
     if(i < 0 || i >= n || j < 0 || j >= n)
          return 0;

     if(visited[i][j])
          return 0;

     if(arr[i][j] == '0')
          return 0;

     visited[i][j] = true;
     count++;
     int ans1 = largestBite(arr,n,i+1,j,visited);
     int ans2 = largestBite(arr,n,i-1,j,visited);
     int ans3 = largestBite(arr,n,i,j+1,visited);
     int ans4 = largestBite(arr,n,i,j-1,visited);

     int ans5 = max(ans1,ans2);
     int ans6 = max(ans4,ans3);
     std::cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << '\n';
     //ans = ans1 + ans2 + ans3 + ans4;
     //visited[i][j] = false;
     return max(ans5,ans6)+1;
}

int cake(char **arr, int n){
     bool **visited = new bool*[n];
     for(int i = 0; i < n; i++)
          visited[i] = new bool[n];

     makeFalse(visited,n);
     int max = 0;
     for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
               if(arr[i][j] == '1' && visited[i][j] == false){
                    int ans = largestBite(arr,n,i,j,visited);
                    max = max > count ? max : count;
                    count = 0;
               }
          }
     }

     for(int i = 0; i < n; i++)
          delete [] arr[i];
     delete [] arr;
     return max;
}

int main(){
     int n;
     cin >> n;
     char **arr = new char*[n];
     for(int i = 0; i < n; i++){
          arr[i] = new char[n];
     }

     for(int i = 0; i < n; i++){
          //std::cout << "this is " << i << '\n';
          for(int j = 0; j < n; j++)
               cin >> arr[i][j];
     }
     //std::cout << "/* message */" << '\n';
     std::cout << cake(arr,n) << '\n';
     std::cout << count << '\n';
     for(int i = 0; i < n; i++)
          delete [] arr[i];
     delete [] arr;
}
