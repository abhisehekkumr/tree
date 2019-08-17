#include<bits/stdc++.h>
using namespace std;

int find(int arr[], int n, int k, bool &flag,int **dp, int prev = INT_MIN, int sum = 0){

     if(n == 0)
          return INT_MIN;

     if(k == 0){
          flag = true;
          return sum;
     }

     if(dp[n][k] > INT_MIN)
          return dp[n][k];

     int res = INT_MIN;

     if(arr[0] >= prev)
          res = max(res, find(arr+1,n-1,k-1,flag,dp,arr[0],sum+arr[0]));
     res = max(res, find(arr+1,n-1,k,flag,dp,prev,sum));
     dp[n][k] = res;
     return res;
}

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          int n,k;
          cin >> n >> k;

          int arr[n];
          for(int i = 0; i < n; i++)
               cin >> arr[i];

          int dp[n][k+1];
          memset(dp,-1,sizeof(dp));

          for(int i = 0; i < n; i++){
               dp[i][1] = arr[i];
          }

          int ans = -1;

          for(int i = 1; i < n; i++){
               for(int j = 0; j < i; j++){
                    if(arr[i] >= arr[j]){
                         for(int l = 1; l < k; l++){
                              if(dp[j][l] != -1)
                                   dp[i][l+1] = max(dp[i][l+1], dp[j][l] + arr[i]);
                         }
                    }
               }
               ans=max(ans,dp[i][k]);
          }
          //std::cout << ans << '\n';
          std::cout << max(ans, dp[0][k]) << '\n';
     }
}
