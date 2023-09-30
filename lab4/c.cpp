#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* right;
    Node* left;
    Node(int x) : val(x), right(nullptr), left(nullptr){}
};

class BST{
private:
    Node* root;
    Node* push(Node* cur, int val){
        if(cur == nullptr){return new Node(val);}
        else if(val < cur->val){cur->left = push(cur->left, val);}
        else{cur->right = push(cur->right, val);}
        return cur;
    }
    void preOrderPrint(Node* cur){
        if(cur != nullptr){
            cout << cur->val << " ";
            preOrderPrint(cur->left);
            preOrderPrint(cur->right);
        }
    }
public:
    BST() : root(nullptr){}
    void push(int val){root = push(root, val);}
    void preOrderPrint(int target){
        Node* cur = root;
        while(cur != nullptr && cur->val != target){
            if(target < cur->val){cur = cur->left;}
            else{cur = cur->right;}
        }
        if(cur != nullptr){preOrderPrint(cur);}
    }
};

int main(){
    int n;
    cin >> n;
    BST tree;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.push(x);
    }
    int target;
    cin >> target;
    tree.preOrderPrint(target);
    return 0;
}