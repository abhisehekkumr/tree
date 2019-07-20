#include<iostream>
#include<climits>
#include<string>
using namespace std;

inline int max(int a, int b){
     return a > b ? a : b;
}

class TrieNode{
public:
     int weight;
     TrieNode **children;

     TrieNode(){
          weight = INT_MIN;
          children = new TrieNode*[26];
          for(int i = 0; i < 26; i++)
               children[i] = NULL;
     }
};

class Trie{
     TrieNode *root;
     void insert(TrieNode *root, string pattern, int number){
          if(pattern.size() == 0)
               return;
          int index = pattern[0]-'a';
          TrieNode *child = root->children[index];
          if(child){
               child->weight = max(child->weight,number);
               insert(child,pattern.substr(1),number);
          }else{
               child = new TrieNode();
               child->weight = number;
               root->children[index] = child;
               insert(child,pattern.substr(1),number);
          }
     }
     int search(TrieNode *root, string pattern, string ans = ""){
          if(pattern.size() == 0){
               //std::cout << ans << '\n';
               return root->weight;
          }
          int index = pattern[0]-'a';
          if(root->children[index])
               return search(root->children[index],pattern.substr(1), ans+pattern[0]);
          return -1;
     }
public:
     Trie(){
          root = new TrieNode();
     }
     void insert(string pattern, int number){
          insert(root,pattern,number);
     }
     int search(string query){
          return search(root,query);
     }
};

int main(){
     int n,q;
     cin >> n >> q;
     Trie tree;
     for(int i = 0; i < n; i++){
          string str;
          int number;
          cin >> str >> number;
          tree.insert(str,number);
     }
     for(int i = 0; i < q; i++){
          string str;
          cin >> str;
          std::cout << tree.search(str) << '\n';
     }
}
