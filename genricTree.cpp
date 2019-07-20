#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode{
public:
     T data;
     vector<TreeNode<T>*> children;
     TreeNode(T input){
          this->data = input;
     }

     ~TreeNode(){
          for(int i = 0; i < children.size(); i++)
               delete children[i];
     }
};

void printTree(TreeNode<int> *root){
     if(!root)
          return;
     std::cout << root->data << ':';
     for(int i = 0; i < root->children.size(); i++){
          std::cout << root->children[i]->data << ',';
     }
     std::cout << '\n';
     for(int i = 0; i < root->children.size(); i++)
          printTree(root->children[i]);
}

TreeNode<int> *takeInput(){
     int data;
     std::cout << "Enter data " << ':';
     cin >> data;
     TreeNode<int> *root = new TreeNode<int>(data);
     std::cout << "number of children " << ':';
     int n;
     cin >> n;
     for(int i = 0; i < n; i++){
          TreeNode<int> *child = takeInput();
          root->children.push_back(child);
     }
     return root;
}


void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int> *> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int> *node = q.front();
        q.pop();
        cout << node->data << ":";
        for(int i = 0; i < node->children.size(); i++){
            TreeNode<int>* child = node->children[i];
            if(i == 0)
                cout << child->data;
            else
                cout << "," << child->data;
            q.push(child);
        }
        cout << endl;
    }
}


int sumOfNodes(TreeNode<int>* root) {
    if(!root)
        return 0;
    int sum = root->data;
    for(int i = 0; i < root->children.size(); i++){
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if(!root)
        return 0;
    TreeNode<int> *maxNode = root;
    for(int i = 0; i < root->children.size(); i++){
        TreeNode<int> *node = maxDataNode(root->children[i]);
        if(maxNode->data < node->data)
            maxNode = node;
    }
    return maxNode;
}

int height(TreeNode<int>* root) {
    if(!root)
        return 0;
    int max = 0;
    for(int i = 0; i < root->children.size(); i++){
        int ans = height(root->children[i]);
        max = max > ans ? max : ans;
    }
    return max+1;
}

int numLeafNodes(TreeNode<int>* root) {
    if(!root)
        return 0;
    int ans = 0;
    if(root->children.size() == 0){
        return 1;
    }
    for(int i = 0; i < root->children.size(); i++)
        ans += numLeafNodes(root->children[i]);
    return ans;
}

void postOrder(TreeNode<int>* root) {
    if(!root)
        return;
    for(int i = 0; i < root->children.size(); i++){
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}

// Following is the given Tree node structure
/**************

class TreeNode {

	TreeNode<T>** children;
	int childCount;

	public:
	T data;

	TreeNode(T data);	// Constructor
	    int numChildren();

	void addChild(TreeNode<T>* child);

	TreeNode<T>* getChild(int index);

	void setChild(int index, TreeNode<T>* child);
};

***************/

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
    if(!root)
        return NULL;
    TreeNode<int> *large = NULL;
    if(root->data > n){
        if(!large)
            large = root;
        else
            large = large->data < root->data ? large : root;
        if(!root->getChild(0))
            return large;
    }
    for(int i = 0; root->getChild(i) != NULL; i++){
        TreeNode<int> *node = nextLargerElement(root->getChild(i),n);
        if(node && node->data > n){
            if(!large)
                large = node;
            else
                large = large->data < node->data ? large : node;
        }
    }
    return large;
}

void replaceWithDepthValue(TreeNode<int> *root, int k = 0){

    if(!root)
        return;

    root->data = k;

    for(int i = 0; root->getChild(i) != NULL; i++)
        replaceWithDepthValue(root->getChild(i),k+1);

}

TreeNode<int>* maxSumNode(TreeNode<int> *root){
    if(!root)
        return NULL;
    TreeNode<int> *maxNode = NULL;
    int ans = root->data;
    for(int i = 0; root->getChild(i) != NULL; i++)
        ans += root->getChild(i)->data;
    maxNode = root;
    for(int i = 0; root->getChild(i) != NULL; i++){
        TreeNode<int> *node = maxSumNode(root->getChild(i));
        int max = 0;
        if(node){
            max = node->data;
            for(int i = 0; node->getChild(i) != NULL; i++)
                max += node->getChild(i)->data;
            //cout << "node: " << maxNode->data << " " << ans << " " << max << " " << node->data << endl;
            if(max > ans){
                ans = max;
                maxNode = node;
            }
        }
    }
    return maxNode;
}

/****************************************************************************/
//     fucking second largest element in Genric TreeNode
/****************************************************************************/
class Pair{

    public:
        TreeNode<int> *first;
        TreeNode<int> *second;

        Pair(){
            first = NULL;
            second = NULL;
        }
};

inline TreeNode<int> *max(TreeNode<int> *a, TreeNode<int> *b){
    return a->data > b->data ? a : b;
}

Pair SecondElement(TreeNode<int> *root){

    Pair result;

    if(!root)
        return result;

    if(result.first == NULL)
        result.first = root;

    for(int i = 0; root->getChild(i) != NULL; i++){
        Pair node = SecondElement(root->getChild(i));
        if(result.first->data > node.first->data){
            // result second is null;
            if(!result.second){
                // node second is null then simly node.first
                if(!node.second)
                    result.second = node.first;
                else
                    result.second = max(node.first, node.second);
            }
            // result second is not null
            else{
                // node second is null
                if(!node.second)
                    result.second = max(result.second, node.first);
                else
                    result.second = max(result.second, max(node.first, node.second));
            }
        }

        // both first are equal
        else if(result.first->data == node.first->data){
            if(!result.second && (!node.second))
                result.second = NULL;
            else if(!result.second)
                result.second = node.second;
            else if(!node.second)
                result.second = result.second;
            else
                result.second = max(result.second, node.second);
        }

        // if reult.fist < node.first
        else{
            TreeNode<int> *x = result.first;
            result.first = node.first;
            if(!result.second){
                if(!node.second)
                    result.second = x;
                else
                    result.second = max(x, node.second);
            }
            else{
                if(!node.second)
                    result.second = max(x,result.second);
                else
                    result.second = max(x, max(result.second, node.second));
            }
        }
    }
    return result;
}

TreeNode <int>* secondLargest(TreeNode<int> *root) {

    Pair result = SecondElement(root);
    return result.second;
}



/****************************************************************************/
//     fucking second largest element in Genric TreeNode
/****************************************************************************/

int main(){
     /*
     TreeNode<int> *root = new TreeNode<int>(1);
     TreeNode<int> *child1 = new TreeNode<int>(2);
     TreeNode<int> *child2 = new TreeNode<int>(3);
     root->children.push_back(child1);
     root->children.push_back(child2);
     */

     TreeNode<int> *root = takeInput();
     printTree(root);
}
