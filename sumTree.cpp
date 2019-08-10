#include<iostream>
using namespace std;

struct TreeNode{
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

     cout << root->data << " ";
     display(root->left);
     display(root->right);
}

int sumTree(TreeNode *root){
     if(!root)
          return 0;
     if(root->left == NULL && root->right == NULL){
          int ans = root->data;
          root->data = 0;
          return ans;
     }

     int left_answer = sumTree(root->left);
     int right_answer = sumTree(root->right);
     int ans = root->data;
     root->data = left_answer + right_answer;
     return ans + root->data;
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

     display(root);
     cout << endl;
     sumTree(root);
     display(root);
     cout << endl;
}
