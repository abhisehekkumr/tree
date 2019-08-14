#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<climits>
#include<vector>
#include<unordered_map>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;

    for(int i = 0; i < n; i++){

        if(min.size() == 0 && max.size() == 0)
            max.push(arr[i]);

        else if(max.size() > 0 && max.top() > arr[i])
            max.push(arr[i]);
        else
            min.push(arr[i]);

        if(max.size()+1 < min.size()){
            max.push(min.top());
            min.pop();
            //std::cout << "pop from min" << '\n';
        }

        if(min.size()+1 <  max.size()){
            min.push(max.top());
            max.pop();
            //std::cout << "pop from max" << '\n';
        }

        if(min.size() == 0)
            cout << max.top() << endl;

        else if(min.size() == max.size()){
            int ans = min.top() + max.top();
            cout << ans/2 << endl;
            //std::cout << (min.top() + max.top())/2 << '\n';
        }
        else if(min.size()+1 == max.size())
            cout << max.top() << endl;
        else if(max.size()+1 == min.size())
            cout << min.top() << endl;
    }
    //cout << endl;
}
