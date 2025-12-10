#include "bits/stdc++.h"
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

void createMapping(vector<int>& arr, unordered_map<int, int>& mp) {
    for (int i = 0; i < arr.size(); i++)
        mp[arr[i]] = i;
}

Node* solvePreOrder(vector<int>& inorder, vector<int>& preorder, unordered_map<int, int>& mp,
                    int& index, int start, int end, int n) {
    if (index >= n || start > end) return NULL;

    int element = preorder[index++];
    Node* root = new Node(element);
    int position = mp[element];

    root->left = solvePreOrder(inorder, preorder, mp, index, start, position - 1, n);
    root->right = solvePreOrder(inorder, preorder, mp, index, position + 1, end, n);

    return root;
}

Node* buildPreOrderTree(vector<int>& inorder, vector<int>& preorder) {
    int preOrderIndex = 0;
    int n = preorder.size();
    unordered_map<int, int> nodeToIndex;
    createMapping(inorder, nodeToIndex);
    Node* root = solvePreOrder(inorder, preorder, nodeToIndex, preOrderIndex, 0, n - 1, n);

    return root;
}

Node* solvePostOrder(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& mp,
                     int& index, int start, int end, int n) {
    if (index < 0 || start > end) return NULL;

    int element = postorder[index--];
    Node* root = new Node(element);
    int position = mp[element];

    root->right = solvePostOrder(inorder, postorder, mp, index, position + 1, end, n);
    root->left = solvePostOrder(inorder, postorder, mp, index, start, position - 1, n);

    return root;
}

Node* buildPostOrderTree(vector<int>& inorder, vector<int>& postorder) {
    int n = postorder.size();
    int postOrderIndex = n - 1;
    unordered_map<int, int> nodeToIndex;
    createMapping(inorder, nodeToIndex);

    Node* root = solvePostOrder(inorder, postorder, nodeToIndex, postOrderIndex, 0, n - 1, n);

    return root;
}

int main() {
    // 1. Contruct Tree from Preorder and Inorder
    // https://www.geeksforgeeks.org/problems/construct-tree-1/1

    // 2. Construct Tree from Postorder and Inorder
    // https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
}
