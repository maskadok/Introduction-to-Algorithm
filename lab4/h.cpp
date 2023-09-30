#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};
class BST {
private:
    Node* root;
    int sum;
    Node* push(Node* cur, int val) {
        if (cur == nullptr){return new Node(val);}
        if (val < cur->val){cur->left = push(cur->left, val);}
        else{cur->right = push(cur->right, val);}
        return cur;
    }
    void greaterSumRecursive(Node* cur){
        if(cur != nullptr){
            greaterSumRecursive(cur->right);
            sum += cur->val;
            cur->val = sum;
            greaterSumRecursive(cur->left);
        }
    }
    void inOrderRecursive(Node* cur){
        if(cur != nullptr){
            inOrderRecursive(cur->right);
            cout << cur->val << " ";
            inOrderRecursive(cur->left);
        }
    }
public:
    BST() : root(nullptr), sum(0){}
    void push(int x){root = push(root, x);}
    void greaterSum(){greaterSumRecursive(root);}
    void inOrder(){inOrderRecursive(root);cout << endl;}
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
    tree.greaterSum();
    tree.inOrder();
    return 0;
}