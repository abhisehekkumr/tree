#include<iostream>
using namespace std;

string copy(int i, int n, string arr){
     string ans = "";
     for(;i < n; i++)
          ans += arr[i];
     return ans;
}

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          string arr;
          cin >> arr;

          int max = 0;
          int i = 0;
          string ans = "";
          while(i < arr.size()){

               // odd length
               int j = i, k = i;
               int count = 0;
               while(j >= 0 && k < arr.size() && arr[j] == arr[k]){
                    j--;
                    k++;
                    count++;
               }

               count = 2*count-1;
               if(count > max){
                    ans = copy(j+1,k,arr);
                    max = count;
                    //std::cout << ans << "  " << "odd" << " " << j+1 << " " << k << arr.substr(j+1,k) << '\n';
               }

               // even length
               j = i, k = i+1;
               count = 0;
               while(j >= 0 && k < arr.size() && arr[j] == arr[k]){
                    j--;
                    k++;
                    count += 2;
               }


               if(count > max){
                    ans = copy(j+1,k,arr);
                    max = count;
                    //std::cout << ans << " " << "even" << " " << j+1 << " " << k << '\n';
               }
               //std::cout << i << " " << ans << '\n';
               i++;
          }

          std::cout << ans << '\n';
     }
}
