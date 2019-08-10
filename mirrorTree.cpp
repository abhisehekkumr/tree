#include<iostream>
using namespace std;

struct TreeNode {
     int data;
     TreeNode *left;
     TreeNode *right;

     TreeNode(int data){
          this->data = data;
          this->left = NULL;
          this->right = NULL;
     }
};

TreeNode *insert(TreeNode *root, int data){
     if(!root)
          return new TreeNode(data);
     if(root->data > data)
          root->left = insert(root->left,data);
     else if(root->data < data)
          root->right = insert(root->right,data);
     return root;
}

void display(TreeNode *root){
     if(!root)
          return;
     display(root->left);
     std::cout << root->data << ' ';
     display(root->right);
}

void preorder(TreeNode *root){
     if(!root)
          return;
     std::cout << root->data << ' ';
     preorder(root->left);
     preorder(root->right);
}

void mirrorTree(TreeNode *root){
     if(!root)
          return;
     TreeNode *temp = root->left;
     root->left = root->right;
     root->right = temp;

     mirrorTree(root->left);
     mirrorTree(root->right);
}

int main(){
     TreeNode *root = NULL;
     while(true){
          int data;
          cin >> data;
          if(data == -1)
               break;
          root = insert(root,data);
     }
     preorder(root);
     std::cout << '\n';
     mirrorTree(root);
     preorder(root);
     std::cout << '\n';
}
