#include<iostream>
#include<stack>
using namespace std;

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          string str;
          cin >> str;

          stack<char> s;

          string ans =  "balanced";
          for(int i = 0; i < str.size(); i++){
               if(str[i] == '(' || str[i] == '[' || str[i] == '{')
                    s.push(str[i]);
               else{

                    if(s.empty()){
                         s.push('a');
                         ans = "not balanced";
                         break;
                    }

                    bool flag = false;
                    if(str[i] == ')' && s.top() != '(')
                         flag = true;
                    else if(str[i] == ']' && s.top() != '[')
                         flag = true;
                    else if(str[i] == '}' && s.top() != '{')
                         flag = true;

                    if(flag){
                         ans = "not balanced";
                         break;
                    }
                    s.pop();
               }
          }

          if(s.size() == 0)
               std::cout << "balanced" << '\n';
          else
               std::cout << "not balanced" << '\n';
     }
}
