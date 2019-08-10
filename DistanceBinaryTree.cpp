#include<iostream>
#include<queue>
using namespace std;

struct node{
     int data;
     node *left;
     node *right;

     node(int data){
          this->data = data;
          this->left = NULL;
          this->right = NULL;
     }
};

node *insert(node **n){

     int data;
     cin >> data;
     node *root = new node(data);
     queue<node*> q;
     q.push(root);

     while(!q.empty()){
          node *node = q.front();
          q.pop();

          int leftData, rightData;
          cin >> leftData >> rightData;

          if(leftData != -1){
               node->left = new node(leftData);
               q.push(node->left);

               if(leftData == 7)
                    (*n) = node->left;
          }

          if(rightData != -1){
               node->right = new node(rightData);
               q.push(node->right);

               if(rightData == 7)
                    (*n) = node->right;
          }
     }
     return root;
}

void display(node *root){
     if(!root)
          return;
     std::cout << root->data << ' ';
     display(root->left);
     display(root->right);
}

void printSubtree(node *root, int k ,int d){

     if(!root)
          return;
     if(d < 0 || d > k)
          return;
     if(d == k){
          std::cout << root->data << " ";
          return;
     }
     printSubtree(root->left,k,d+1);
     printSubtree(root->right,k,d+1);
}

int findnode(node *root, node *node, bool &found){
     if(!root)
          return 0;

     if(node == root){
          found = true;
          return 1;
     }

     int left = findnode(root->left,node,found);
     if(left > 0 && found)
          return left+1;

     int right = findnode(root->right,node,found);
     if(right > 0 && found)
          return right+1;
     return 0;
}

void print(node *root, node *node, int k){

     if(!root)
          return;

     if(root == node){
          printSubtree(node,k,0);
          return;
     }

     bool found = false;
     int left = findnode(root->left,node,found);

     if(left > 0 && found){
          //std::cout << "from left side" << " " << root->data << '\n';
          if(left == k)
               std::cout << root->data << ' ';
          print(root->left,node,k);
          printSubtree(root->right,k,left+1);
     }

     found = false;
     int right = findnode(root->right,node,found);
     if(right > 0 && found){
          //std::cout << "from right side" << '\n';
          if(right == k)
               cout << root->data << " ";
          printSubtree(root->left,k,right+1);
          print(root->right,node,k);
     }
}

int main(){
     node *n = NULL;
     node *root = insert(&n);
     //display(root);
     //std::cout << '\n';
     //std::cout << n->data << '\n';
     print(root,n,2);
     std::cout << '\n';
}
/*
20 8 22 4 12 -1 -1 -1 -1 10 14 -1 -1 -1 -1
*/
