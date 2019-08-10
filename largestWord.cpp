#include<iostream>
#include<algorithm>
using namespace std;

bool compare(string s1, string s2){
     return s1.size() > s2.size();
}

bool isPossible(string str, string word){

     if(str.size() < word.size())
          return false;

     int j = 0;
     int count = 0;
     int i = 0;

     while(i < word.size() && j < str.size()){

          if(word.size() == count)
               return true;

          if(word[i] == str[j]){
               count += 1;
               j++;
               i++;
          }
          else{
               while(j < str.size() && word[i] != str[j])
                    j++;
          }
     }

     if(count == word.size())
          return true;

     //cout << word.size() << " " << count << " "  << str << " " << word << endl;
     return false;
}

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          int n;
          cin >> n;

          string arr[n];
          for(int i = 0; i < n; i++)
               cin >> arr[i];

          sort(arr,arr+n,compare);
          string str;
          cin >> str;

          for(int i = 0; i < n; i++){
               if(isPossible(str,arr[i])){
                    cout << arr[i] << endl;
                    break;
               }
          }
     }
}
