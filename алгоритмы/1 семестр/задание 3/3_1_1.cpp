
#include <iostream>
#include <algorithm>
using namespace std ;
struct Node {
    int key;
    Node* left=nullptr;
    Node* right=nullptr;
    Node (int k) {
        key=k;
    }
    void insert (int k) {
        if (k>=key) {
            if (right==nullptr) {
                right= new Node(k);
            } else right->insert(k);
        } else {
            if (left==nullptr) {
                left= new Node(k);
            } else left->insert(k);
        }
    }
    void debAg (){
        if (left!=nullptr) left->debAg();
        cout<<key<<" ";
        if (right!=nullptr) right->debAg();
    }
};
int main () {
    int n, a;
    cin>>n;
    cin>>a;
    Node root(a);
    for (int i(1);i<n;++i) {
        cin>>a;
        root.insert(a);
    }
    root.debAg();
}
