#include<iostream>
typedef long long ll;
using namespace std;

int main(){
     ll t = 1;
     //cin >> t;

     while(t--){
          ll n;
          cin >> n;

          ll arr[n];
          for(ll i = 0; i < n; i++)
               cin >> arr[i];

          ll dp[n];
          dp[0] = arr[0];
          dp[1] = arr[0] > arr[1] ? arr[0] : arr[1];

          for(ll i = 2; i < n; i++)
               dp[i] = max(arr[i] + dp[i-2], dp[i-1]);
          cout << dp[n-1] << endl;
     }
}
