#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

vector<vector<int>> levelOrderTraversal(Node* root){
    vector<vector<int>>arr;
if(root==NULL)return arr;

queue<Node*>q;
q.push(root);

while(!q.empty()){
    int size=q.size();
    vector<int>level;
    for(int i=0;i<size;i++){
        Node* Node=q.front();
        level.push_back(Node->data);
        q.pop();
        if(Node->left)q.push(Node->left);
        if(Node->right)q.push(Node->right);
    }
    arr.push_back(level);
}
return arr;
}


int main(){
struct Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left= new Node(4);
root->left->right= new Node(5);
root->right->right= new Node(6);
root->right->left= new Node(7);
// root->left->right = new Node(4);
vector<vector<int>>v;
v=levelOrderTraversal(root);
for(auto &it:v){
    for(int it2: it){
        cout<<it2<<" ";
    }
    cout<<endl;
}

}