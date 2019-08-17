#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          int n;
          cin >> n;

          string arr[n];
          for(int i = 0; i < n; i++)
               cin >> arr[i];
          int rr = 0;
          int bb = 0;
          int r = 0, c = 0;
          vector<int> rb;
          vector<int> br;

          for(int i = 0; i < n; i++){
               string str = arr[i];
               if(str[0] == 'R' && str[str.size()-1] == 'R'){
                    rr += str.size();
                    r++;
               }
               else if(str[0] == 'B' && str[str.size()-1] == 'B'){
                    bb += str.size();
                    c++;
               }

               else if(str[0] == 'R' && str[str.size()-1] == 'B')
                    rb.push_back(str.size());
               else
                    br.push_back(str.size());
          }

          if(br.size() == 0 && rb.size() == 0 && rr == 0){
               std::cout << bb << '\n';
               continue;
          }

          if(br.size() == 0 && rb.size() == 0 && bb == 0){
               std::cout << rr << '\n';
               continue;
          }

          if(br.size() == 0 && rb.size() == 0 && n > 2){
               std::cout << max(rr,bb) << '\n';
               continue;
          }

          if(br.size() == 0 || rb.size() == 0){
               std::cout << 0 << '\n';
               continue;
          }

          if(br.size() == 0 && rb.size() == 0){
               std::cout << 0 << '\n';
               continue;
          }

          sort(rb.begin(), rb.end(), greater<int>());
          sort(br.begin(), br.end(), greater<int>());

          int ans = rr + bb;
          for(int  i = 0; i < min(br.size(), rb.size()); i++)
               ans += br[i] + rb[i];

          if(br.size() < rb.size())
               ans += rb[br.size()];
          else if(rb.size() < br.size())
               ans += br[rb.size()];
          std::cout << ans << '\n';
     }
}
