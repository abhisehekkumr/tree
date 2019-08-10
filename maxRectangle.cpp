#include<iostream>
#include<climits>
using namespace std;

int kednes(int arr[], int n){

     int max_sum = INT_MIN;
     int curr = 0;
     for(int i = 0; i < n; i++){
          curr += arr[i];
          if(max_sum < curr)
               max_sum = curr;
          if(curr < 0)
               curr = 0;
     }
     return max_sum;
}

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          int n,m;
          cin >> n >> m;

          int arr[n][m];
          for(int i = 0; i < n; i++){
               for(int j = 0; j < m; j++)
                    cin >> arr[i][j];
          }

          int max_sum = INT_MIN;

          for(int i = 0; i < m; i++){
               int sum[n];
               for(int j = 0; j < n; j++)
                    sum[j] = 0;

               for(int j = i; j < m; j++){
                    for(int k = 0; k < n; k++)
                         sum[k] += arr[k][j];
                    int ans = kednes(sum,n);
                    max_sum = max_sum > ans ? max_sum : ans;
               }
          }

          cout << max_sum << endl;
     }
}
