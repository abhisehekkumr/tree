#include<iostream>
#include<climits>
using namespace std;

int findMinInsertions(string str, int l, int h)
{
	// Base Cases
	if (l > h) return INT_MAX;
	if (l == h) return 0;
	if (l == h - 1) return (str[l] == str[h])? 0 : 1;

	// Check if the first and last characters are
	// same. On the basis of the comparison result,
	// decide which subrpoblem(s) to call
	return (str[l] == str[h])?
					findMinInsertions(str, l + 1, h - 1):
					(min(findMinInsertions(str, l, h - 1),
					findMinInsertions(str, l + 1, h)) + 1);
}

int moves(string str, int i, int j, int **dp){

     if(i > j)
          return INT_MAX;

     if(i == j)
          return 0;

     if(i + 1 == j)
          return str[i] == str[j] ? 0 : 1;

     if(dp[i][j] > -1)
          return dp[i][j];

     int ans;
     if(str[i] == str[j])
          ans = moves(str,i+1,j-1,dp);
     else
          ans = min(moves(str,i,j-1,dp), moves(str,i+1,j,dp))+1;

     dp[i][j] = ans;

     //dp[i][j] =  str[i] == str[j] ? moves(str,i+1,j-1,dp) : (min(moves(str,i,j-1,dp), moves(str,i+1,j,dp))+1);
     return dp[i][j];
}

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          string str;
          cin >> str;
          //std::cout << findMinInsertions(str,0,str.size()-1) << '\n';

          int **arr = new int*[str.size()+1];
          for(int i = 0; i <= str.size(); i++){
               arr[i] = new int[str.size()+1];
               for(int j = 0; j <= str.size(); j++)
                    arr[i][j] = -1;
          }
          std::cout << moves(str,0,str.size()-1,arr) << '\n';
     }
}
