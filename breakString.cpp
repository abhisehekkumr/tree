#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool divide(string str, unordered_map<string,int> &m){

     if(m.count(str) == 1)
          return true;
     for(int i = 1; i < str.size(); i++){
          string left = str.substr(0,i);
          string right = str.substr(i);

          if(m.count(left) && divide(right,m))
               return true;
     }
     return false;
}

int main(){
     string str;
     cin >> str;

     int n;
     cin >> n;

     unordered_map<string,int> m;

     for(int i = 0; i < n; i++){
          string s;
          cin >> s;
          m[s]++;
     }

     std::cout << divide(str,m) << '\n';
}
