#include<iostream>
#include<algorithm>
using namespace std;

struct train{
     int a;
     int d;
};

bool compare(train t1, train t2){
     if(t1.a < t2.a)
          return true;
     if(t1.a > t2.a)
          return false;
     return t1.d < t2.d;
}

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          int n;
          cin >> n;

          //train arr[n];
          int a[n],d[n];
          for(int i = 0; i < n; i++)
               cin >> a[i];
          for(int i = 0; i < n; i++)
               cin >> d[i];

          sort(a,a+n);
          sort(d,d+n);

          int count = 1;
          int p = 1;
          int i = 1, j = 0;
          while(i < n && j < n){
               if(a[i] <= d[j]){
                    p++;
                    if(p > count)
                         count = p;
                    i++;
               }
               else{
                    p--;
                    j++;
               }
          }
          std::cout << count << '\n';
     }
}
