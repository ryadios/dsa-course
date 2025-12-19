#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* find(Node* node) {
    Node* pre = node->left;

    while (pre->right != NULL && pre->right != node)
        pre = pre->right;

    return pre;
}

void morrisTraversal(Node* root) {
    Node* curr = root;

    while (curr != NULL) {
        if (curr->left == NULL) {
            cout << curr->data << " ";
            curr = curr->right;
        } else {
            Node* node = curr->left;

            while (node->right)
                node = node->right;

            if (node->right == NULL) {
                node->right = curr;
                curr = curr->left;
            } else {
                node->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

void flattenRecursion(Node* root, Node*& prev) {
    if (root == NULL) return;

    flattenRecursion(root->right, prev);
    flattenRecursion(root->left, prev);

    root->right = prev;
    root->left = NULL;

    prev = root;
}

void flattenStack(Node* root) {
    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* node = st.top();
        st.pop();

        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);

        if (!st.empty()) {
            node->right = st.top();
        }

        node->left = NULL;
    }
}

void flattenMorrisTraversal(Node* root) {
    Node* curr = root;

    while (curr != NULL) {
        if (curr->left != NULL) {
            Node* node = curr->left;

            while (node->right)
                node = node->right;

            node->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        } else {
            curr = curr->right;
        }
    }
}

int main() {
    // 1. Flatten binary tree to linked list
    // https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
}
