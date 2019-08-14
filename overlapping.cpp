#include<iostream>
#include<vector>
using namespace std;

int diagonal(int **arr, int i, int j, int n){

     int count = 0;
     for(; i < n && j < n ; i++, j++){


          if(arr[i][j] == 1)
               count++;
          else
               break;
     }
     return count;
}

string copy(int i, int count, string str){
     string ans = "";
     int j = i;
     while(j < i+count){
          ans += str[j];
          j++;
     }
     return ans;
}

int main(){
     int t = 1;
     cin >> t;

     while(t--){
          string str;
          int k;
          cin >> k;
          cin >> str;

          vector<vector<int>> arr(str.size()+1, vector<int>(str.size()+1));

          int max = -1;
          int index = 0;
          for(int i = 1; i <= str.size(); i++){
               for(int j = i+1; j <= str.size(); j++){
                    if(str[i-1] == str[j-1] && arr[i-1][j-1] < (j-i))
                         arr[i][j] = arr[i-1][j-1]+1;
                    if(max < arr[i][j]){
                         max = arr[i][j];
                         index = j;
                    }
               }
          }

          if(max == -1)
               std::cout << -1 << '\n';
          else
               std::cout << str.substr(index-max,max) << '\n';
     }
}
