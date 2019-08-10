#include<iostream>
using namespace std;

int alive(int n, int k){
     if(n == 1)
          return 0;
     return (alive(n-1,k)+k)%n;
}

int circle(int n, int k){
     if(n == 1)
          return 1;
     return (circle(n-1,k)+k-1)%n+1;
}

int main(){
     int n,k;
     cin >> n >> k;
     std::cout << alive(n,k)+1 << '\n';
     cout << circle(n,k) << endl;
}
