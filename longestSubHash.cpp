#include<iostream>
#include<algorithm>
using namespace std;

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          int n;
          cin >> n;

          int arr[n];
          for(int i = 0; i < n; i++)
               cin >> arr[i];
          sort(arr,arr+n);

          int count = 0;
          int max = 1;

          for(int i = 1; i < n; i++){
               if(arr[i] == arr[i-1]+1)
                    count += 1;
               else
                    count = 1;
               max = max > count ? max : count;
          }
          cout << max << endl;
     }

}
