#include<iostream>
#include<queue>
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
     display(root->left);
     cout << root->data << " ";
     display(root->right);
}

int width(TreeNode *root){
     queue<TreeNode *> q;

     if(!root)
          return 0;

     q.push(root);
     q.push(NULL);

     int max = 0, count = 0;
     while(!q.empty()){
          TreeNode *node = q.front();
          q.pop();
          if(node == NULL){
               max = max > count ? max : count;
               count = 0;
               if(q.empty())
                    break;
               q.push(NULL);
          }
          else{
               count += 1;
               if(node->left)
                    q.push(node->left);
               if(node->right)
                    q.push(node->right);
          }
     }

     return max;
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
     cout << "width : " << width(root) << endl;
}
