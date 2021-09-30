#include <bits/stdc++.h>
using namespace std;
class bT {
    public:
    int d;
    bT* left;
    bT* right;
    bT(int data, bT* lft, bT* rht) {
        d = data;
        left = lft;
        right = rht;
    }
};
bT* searchRecursive(bT* root, int key) {
    bT* rt = NULL;
    if(root != NULL) {
        if(root->d == key) {
            cout<<"Found"<<endl;
            return root;
        }
        rt = searchRecursive(root->left, key);
        rt = searchRecursive(root->right, key);
    }
    return rt;
}
bT* searchNonRecursive(bT* root, int key) {
    bT* rt = NULL;
    stack<bT*> S;
    if(root != NULL) {
        while(true) {
            while(root != NULL) {
                if(root->d == key) {
                    cout<<"Found"<<endl;
                    return root;
                }
                S.push(root);
                root = root->left;
            }
            if(S.empty()) {
                break;
            }
            root = S.top();
            S.pop();
            root = root->right;
        }
    }
    return rt;
}
int main() {
    bT* one = new bT(1, NULL, NULL);
    one->left = new bT(2, NULL, NULL);
    one->left->right = new bT(3, NULL, NULL);
    one->right = new bT(4, NULL, NULL);
    one->right->left = new bT(5, NULL, NULL);
    one->right->right = new bT(6, NULL, NULL);
    bT* ele = searchNonRecursive(one, 15);
    if(!ele) {
        cout<<"Not Found"<<endl;
    }
}
