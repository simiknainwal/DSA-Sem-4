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


vector<vector<int>> levelOrder(Node* root){
vector<vector<int>>ans;
if(root==NULL)return ans;
queue<Node*>q;

q.push(root);

while(!q.empty()){
    int size=q.size();
    vector<int>level;
    for(int i=0;i<size;i++){
        Node* node=q.front();
        q.pop();

        if(node->left)q.push(node->left);
        if(node->right)q.push(node->right);
        level.push_back(node->data);
    }
    // ans.push_back(level);
    ans.insert(ans.begin(),level);
}
return ans;
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
v=levelOrder(root);
for(auto &it:v){
    for(int it2: it){
        cout<<it2<<" ";
    }
    cout<<endl;
}

}