#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
     TrieNode *left;
     TrieNode *right;
};

void insert(TrieNode *root, int number){
     TrieNode *curr = root;
     for(int i = 31; i >= 0; i--){
          int bit = (number >> i) & 1;
          if(bit == 0){
               if(!curr->left)
                     curr->left = new TrieNode();
               curr = curr->left;
          }else{
               if(!curr->right)
                    curr->right = new TrieNode();
               curr = curr->right;
          }
     }
}

int maxPair(int arr[], int n, TrieNode *root){
     int max =INT_MIN;
     for(int i = 0; i < n; i++){
          int number = arr[i];
          TrieNode *cur = root;
          int curr_xor = 0;
          for(int j = 31; j >= 0; j--){
               int bit = (number >> j) & 1;

                if(bit == 0){
                     if(cur->right){
                          curr_xor += pow(2,j);
                         cur = cur->right;
                    }
                    else
                         cur = cur->left;
                }else{

                     if(cur->left){
                          curr_xor += pow(2,j);
                         cur = cur->left;
                    }
                    else
                         cur = cur->right;
                }
          }
          if(max < curr_xor){
               max = curr_xor;
          }
     }
     return max;
}

void insertXor(TrieNode *root, int number){
     TrieNode *cur = root;
     for(int i = 31; i >= 0; i--){
          int bit = (number >> i) & 1;
          if(bit == 0){
               if(!cur->left)
                    cur->left = new TrieNode();
               cur = cur->left;
          }else{
               if(!cur->right)
                    cur->right = new TrieNode();
               cur = cur->right;
          }
     }
}

int maxXor(TrieNode *root, int number){
     int cur_xor = 0;
     TrieNode *cur = root;
     for(int i = 31; i >= 0; i--){
          int bit = (number >> i) & 1;
          if(bit == 0){
               if(cur->right){
                    cur_xor += pow(2,i);
                    cur = cur->right;
               }else
                    cur = cur->left;
          }else{
               if(cur->left){
                    cur_xor += pow(2,i);
                    cur = cur->left;
               }else
                    cur = cur->right;
          }
     }
     return cur_xor;
}

int maxXorSubArray(int arr[], int n, TrieNode *root){
     int max = INT_MIN;
     int cur_xor = 0;

     for(int i = 0; i < n; i++){
          cur_xor = cur_xor^arr[i];
          insertXor(root,cur_xor);
          int result = maxXor(root,cur_xor);

          if(max < result)
               max = result;

          if(max < cur_xor)
               max = cur_xor;
     }
     return max;
}

int main(){
     TrieNode *root = new TrieNode();
     int n;
     cin >> n;
     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     std::cout << maxXorSubArray(arr,n,root) << '\n';
}
