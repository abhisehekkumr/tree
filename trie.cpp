#include<iostream>
#include<string>
#include<vector>
using namespace std;

class TrieNode{
public:
     char data;
     TrieNode **children;
     bool terminal;

     TrieNode(char data){
          this->data = data;
          children = new TrieNode*[26];
          for(int i = 0; i < 26; i++)
               children[i] = NULL;
          terminal = false;
     }
};

class Trie{
     TrieNode *root;
     void insert(TrieNode *root, string word){
          if(word.size() == 0){
               root->terminal = true;
               return;
          }
          int index = word[0] - 'a';
          TrieNode *child;
          if(root->children[index])
               child = root->children[index];
          else{
               child = new TrieNode(word[0]);
               root->children[index] = child;
          }
          insert(child,word.substr(1));
     }

     bool search(TrieNode *root, string word){
          if(word.size() == 0){
               if(root->terminal)
                    return true;
               return false;
          }
          int index = word[0] - 'a';
          if(root->children[index])
               return search(root->children[index], word.substr(1));
          return false;
     }

     void remove(TrieNode *root, string word){
          if(word.size() == 0){
               root->terminal = false;
               return;
          }

          int index = word[0] - 'a';
          if(root->children[index])
               remove(root->children[index],word.substr(1));
          else
               return;

          TrieNode *child = root->children[index];
          if(child->terminal == false){
               for(int i = 0; i < 26; i++){
                    if(child->children[i])
                         return;
               }
               delete child;
               root->children[index] = NULL;
          }
     }

     bool searchPattern(TrieNode *root, string pattern){
          if(pattern.size() == 0)
               return true;
          int index = pattern[0]-'a';
          if(root->children[index])
               return searchPattern(root->children[index], pattern.substr(1));
          return false;
     }

     string reverse(string str){
          string ans = "";
          for(int i = str.size()-1; i >= 0; i--)
               ans += str[i];
          return ans;
     }

     void printPaths(TrieNode *root, string output){
          if(root->terminal){
               std::cout << output << '\n';
          }
          char c = 'a';
          for(int i = 0; i < 26; i++){
               if(root->children[i])
                    printPaths(root->children[i], output+c);
               c += 1;
          }
     }

     void printAllWords(TrieNode *root, string pattern, string output = ""){
          if(pattern.size() == 0){
               printPaths(root,output);
               return;
          }
          int index = pattern[0]-'a';
          if(root->children[index])
               printAllWords(root->children[index],pattern.substr(1), output + pattern[0]);
     }

public:
     Trie(){
          root = new TrieNode('\0');
     }
     void insert(string word){
          insert(root,word);
     }

     bool search(string word){
          return search(root,word);
     }

     void remove(string word){
          if(search(root,word))
               remove(root,word);
          else
               std::cout << "word doesn't exit in Dictionary" << '\n';
     }

     bool searchPattern(string pattern){
          return searchPattern(root,pattern);
     }

     bool match(vector<string> vect, string pattern){
          for(int i = 0; i < vect.size(); i++){
               for(int j = 0; j < vect[i].size()-1; j++)
                    insert(vect[i].substr(j));
          }
          return searchPattern(pattern);
     }

     bool palindromPair(vector<string> arr){
          for(int i = 0; i < arr.size(); i++){
               insert(arr[i]);
               for(int j = i + 1; j < arr.size(); j++)
                    insert(arr[i] + arr[j]);
          }

          for(int i = 0; i < arr.size(); i++){
               if(search(reverse(arr[i])))
                    return true;

               for(int j = i+1; j < arr.size(); j++){
                    if(search(arr[j] + arr[i]))
                         return true;
               }
          }
          return false;
     }

     void autoCompelete(vector<string> input, string pattern){
          for(int i = 0; i < input.size(); i++)
               insert(input[i]);
          printAllWords(root,pattern);
     }
};

int main(){
     Trie tree;
     int n;
     cin >> n;

     vector<string> vect;
     for(int i = 0; i < n; i++){
          string ans;
          cin >> ans;
          vect.push_back(ans);
     }

     string pattern;
     cin >> pattern;
     tree.autoCompelete(vect,pattern);
}
