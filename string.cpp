#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<climits>
#include<vector>
#include<unordered_map>
typedef long long ll;
using namespace std;

int main(){
    int t = 1;
    //cin >> t;

    while(t--){

        string str;
        cin >> str;

        stack<string> s;
        int i = 0;
        while(i < str.size()){
             //std::cout << i << '\n';
            string ans = "";
            while(i < str.size() && str[i] != '.'){
                ans += str[i];
                i++;
            }
            //std::cout << ans << " " << "ans" << '\n';
            if(str[i] == '.')
                i++;

            s.push(ans);
        }

        string ans = "";
        //std::cout << "/* message */" << '\n';
        while(!s.empty()){
            string str = s.top();
            s.pop();

            if(s.empty())
                ans += str;
            else
                ans += str + '.';
        }

        cout << ans << endl;
    }
}
