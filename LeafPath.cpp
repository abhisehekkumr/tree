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
     if(root->data < data)
          root->right = insert(root->right,data);
     return root;
}

void display(TreeNode *root){
     if(!root)
          return;
     display(root->left);
     cout << root->data << " ";
     display(root->right);
}

int height(TreeNode *root){
     if(!root)
          return 0;
     int left = height(root->left);
     int right = height(root->right);
     return (left > right ? left : right) + 1;
}

void print(TreeNode *root, int path[], int index){
     if(!root){
          return;
     }

     path[index] = root->data;

     if(root->left == NULL && root->right == NULL){
          for(int i = 0; i <= index; i++)
               cout << path[i] << " ";
          cout << endl;
     }
     print(root->left,path,index+1);
     print(root->right,path,index+1);
}

void printpaths(TreeNode *root){

     if(!root)
          return ;

     int h = height(root);
     int *arr = new int[h];
     print(root,arr,0);
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

     //display(root);
     printpaths(root);
     //cout << endl;
}
