#include<iostream>
#include<unordered_map>
#include<vector>
#define MAX 1000000
using namespace std;

void sieve(bool arr[], int n){

     for(int i = 0; i <= n; i++)
          arr[i] = true;

     for(int p = 2; p*p <= n; p++){
          if(arr[p]){
               for(int i = 2*p; i <= n;  i += p)
                    arr[i] = false;
          }
     }
}

int main(){
     int t = 5000;
     //cin >> t;
     int c = 1;
     bool arr[MAX+1];
     sieve(arr,MAX);
     while(t--){
          int l,r;
          //cin >> l >> r;
          l = 1;
          r = 1000000;
          std::cout << c++ << ' ';
          unordered_map<int,int> m;
          int max = 0;
          int d = -1;

          int start = -1, end = -1;

          int hash[10];
          for(int i = 0; i < 10; i++)
               hash[i] = 0;

          for(int i = l; i <= r; i++){
               if(arr[i]){
                    int n = i;
                    while(n){
                         hash[n%10]++;
                         n = n/10;
                    }
               }
          }

          for(int i = 0; i < 10; i++){
               if(hash[i] == max && hash[i] > 0){
                    d = i;
               }

               if(hash[i] > max){
                    max = hash[i];
                    d = i;
               }
          }

          std::cout << "ans : " <<  d << '\n';
     }
}
