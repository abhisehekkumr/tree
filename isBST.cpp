#include<iostream>
#include<queue>
#include<climits>
using namespace std;

struct Node{
     int data;
     Node *left;
     Node *right;

     Node(int data){
          this->data = data;
          this->left = NULL;
          this->right = NULL;
     }
};

Node *insert(){
     int data;
     cin >> data;

     Node *root = new Node(data);
     queue<Node *> q;
     q.push(root);

     while(!q.empty()){
          Node *node = q.front();
          q.pop();

          int leftData;
          cin >> leftData;
          int rightData;
          cin >> rightData;

          if(leftData != -1){
               node->left = new Node(leftData);
               q.push(node->left);
          }

          if(rightData != -1){
               node->right = new Node(rightData);
               q.push(node->right);
          }
     }
     return root;
}

int TreeMax(Node *root){
     if(!root)
          return INT_MIN;
     int left = TreeMax(root->left);
     int right = TreeMax(root->right);

     int ans = root->data;
     ans = ans > left ? ans : left;
     ans = ans > right ? ans : right;
     return ans;
}

int TreeMin(Node *root){
     if(!root)
          return INT_MAX;

     int left = TreeMin(root->left);
     int right = TreeMin(root->right);

     int ans = root->data;
     ans = ans < left ? ans : left;
     ans = ans < right ? ans : right;
     return ans;
}

bool isBalanced(Node *root){
     if(!root)
          return true;
     int left_max = TreeMax(root->left);
     int right_min = TreeMin(root->right);

     if(root->data < left_max || root->data > right_min)
          return false;
     return isBalanced(root->left) && isBalanced(root->right);
}

bool bst(Node *root, int min = INT_MIN, int max = INT_MAX){
     if(!root)
          return true;
     if(root->data < min || root->data > max)
          return false;
     return bst(root->left,min,root->data) && bst(root->right,root->data,max);
}

void display(Node *root){
     if(!root)
          return;
     cout << root->data << " ";
     display(root->left);
     display(root->right);
}

int main(){
     Node *root = insert();
     display(root);
     cout << endl;
     std::cout << isBalanced(root) << '\n';
     std::cout << "bst : " << bst(root) << '\n';
}
