#include<iostream>
#include<unordered_map>
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
          unordered_map<int,int> m;
          for(int i = 0; i < n; i++){
               m[arr[i]]++;
          }

          unordered_map<int,int> :: iterator it;
          int max = 0;
          for(it = m.begin(); it != m.end(); it++){
               int count = 0;

               if(m.count(it->first) == 1){
                    for(int j = it->first; m.count(j) == 1; j++){
                         count += 1;
                         m[j] = 0;
                    }
                    max = max > count ? max : count;
               }
          }
          cout << max << endl;
     }
}
