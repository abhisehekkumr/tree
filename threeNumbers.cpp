#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<climits>
#include<vector>
#include<algorithm>
#include<unordered_map>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
    int t = 1;
    //cin >> t;

    while(t--){
        int n,k;
        cin >> n >> k;

        int arr[n];

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        sort(arr,arr+n);
        bool found = false;
        for(int i = 0; i < n; i++){
          int l = n-1;
          int j = i+1;
          int sum = k - (arr[i]);
          while(j < l){
               int ans = arr[j] + arr[l];
               if(ans == sum){
                    found = true;
                    break;
               }

               else if(sum > ans)
                    j++;
               else
                    l--;
          }

          if(found)
               break;
        }

        if(found)
          std::cout << 1 << '\n';
        else
          std::cout << 0 << '\n';
    }
}
