#include<iostream>
#include<unordered_map>
#include<climits>
typedef long long ll;
using namespace std;

void getPowers(unordered_map<string,bool> &powers){

     ll p = 1;
     ll maxx = (1LL << 50);

     while(p <= maxx){
          string s = "";
          ll n = p;
          while(n){
               s += (n & 1) == 1 ? '1' : '0';
               n = n >> 1;
          }
          p = p*5;
          powers[s] = true;
     }
}

int cuts(string binary){

     if(binary[0] == '0' || binary[binary.size()-1] == '0')
          return -1;

     unordered_map<string,bool> powers;
     getPowers(powers);

     int dp[binary.size()+1];
     for(int i = 0; i <= binary.size(); i++)
          dp[i] = INT_MAX;

     dp[binary.size()] = 0;
     for(int i = binary.size()-1; i >= 0; i--){
          if(dp[i+1] == INT_MAX)
               continue;

          string s = "";
          for(int j = i; j >= 0; j--){
               s += binary[j];
               if(powers[s]){
                    dp[j] = min(dp[j], dp[i+1]+1);
               }
          }
     }

     if(dp[0] == INT_MAX)
          return -1;
     return dp[0];
}

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          string str;
          cin >> str;
          std::cout << cuts(str) << '\n';
     }
}
