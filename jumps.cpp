#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<climits>
#include<vector>
#include<unordered_map>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int jumps(int arr[], int n, int index){

     if(n == 0)
          return INT_MAX;

     if(index >= n)
          return 0;

     int ans = INT_MAX;
     int next = INT_MIN;
     int k = n;
     bool found = false;
     bool allZeros = true;

     std::cout << index + 1 << " " << arr[index] << '\n';
     for(int i = index+1; i <= index + arr[index]; i++){

          if(index + arr[i] + 2 >= n){
               allZeros = false;
               found = true;
               break;
          }

          if(arr[i] != 0)
               allZeros = false;

          if(arr[i] == 0)
               continue;

          if(next < arr[i]){
               next = arr[i];
               k = i;
          }
     }

     if(allZeros)
          return INT_MAX;

     if(found)
          return 2;
     ans = min(ans, jumps(arr,n,k)+1);
     return ans;
}

int main(){
     int t = 1;
     //cin >>t;

     while(t--){
          int n;
          cin >> n;

          int arr[n];
          for(int i = 0; i < n; i++)
               cin >> arr[i];
          if(arr[0] >= n){
               cout << 1 << endl;
               continue;
          }
          int ans = jumps(arr,n,0);
          if(ans == INT_MAX)
               std::cout << -1 << '\n';
          else
               std::cout << ans << '\n';
     }
}
