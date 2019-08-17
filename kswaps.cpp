#include<iostream>
using namespace std;

void largest(string str, int k, string &max){

     if(k == 0)
          return;

     int n = str.size();
     for(int i = 0; i < n-1; i++){
          for(int j = i+1; j < n; j++){
               if(str[i] < str[j]){
                    char c = str[i];
                    str[i] = str[j];
                    str[j] = c;

                    if(str.compare(max) > 0){
                         max = str;
                    }

                    largest(str,k-1,max);

                    c = str[i];
                    str[i] = str[j];
                    str[j] = c;
               }
          }
     }
}

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          int k;
          cin >> k;
          string str;
          cin >> str;

          string max = str;
          largest(str,k,max);
          std::cout << max << '\n';
     }
}
