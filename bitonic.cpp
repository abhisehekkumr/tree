#include<iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int k){

     if(low > high)
          return -1;

     int mid = (low+high)/2;

     if(arr[mid] == k)
          return mid;

     if(mid == low)
          return binarySearch(arr,mid+1,high,k);

     if(mid == high)
          return binarySearch(arr,low,mid-1,k);

     if(arr[mid+1] == k)
          return mid+1;

     if(arr[mid-1] == k)
          return mid-1;

     if(arr[mid-1] > arr[mid] && arr[mid] > arr[mid+1]){
          if(k > arr[mid])
               return binarySearch(arr,low,mid-1,k);
          return binarySearch(arr,mid+1,high,k);
     }

     if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){

          if(arr[mid-1] < k)
               return binarySearch(arr,mid+1,high,k);
          return binarySearch(arr,low,mid-1,k);
     }

     if(k > arr[mid])
          return binarySearch(arr,mid+1,high,k);
     return binarySearch(arr,low,mid-1,k);
}

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          int n;
          cin >> n;

          int arr[n];
          for(int i = 0; i < n; i++)
               cin >> arr[i];

          int k;
          cin >> k;

          std::cout << binarySearch(arr,0,n-1,k) << '\n';
     }
}
