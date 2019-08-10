#include<iostream>
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

Node *insert(Node *root,int data){
     if(!root)
          return new Node(data);
     if(root->data > data)
          root->left = insert(root->left,data);
     if(root->data < data)
          root->right = insert(root->right,data);
     return root;
}

void display(Node *root){
     if(!root)
          return;
     display(root->left);
     cout << root->data << " ";
     display(root->right);
}

Node *LCA(Node *root, int n1, int n2){
     if(!root)
          return root;
     if(root->data > n1 && root->data > n2)
          return LCA(root->left,n1,n2);
     if(root->data < n1 && root->data < n2)
          return LCA(root->right,n1,n2);
     return root;
}

int main(){
     Node *root = NULL;
     while(true){
          int data;
          cin >> data;

          if(data == -1)
               break;
          root = insert(root,data);
     }

     display(root);
     int n1,n2;
     cin >> n1 >> n2;
     cout << endl;
     Node *node = LCA(root,n1,n2);

     if(node)
          std::cout << node->data << '\n';
     else
          std::cout << "sorry" << '\n';
}
