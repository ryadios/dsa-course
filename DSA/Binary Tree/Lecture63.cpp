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

int height(Node* root) {
    if (root == NULL) return -1;

    int l = height(root->left);
    int r = height(root->right);

    return max(l, r) + 1;
}

pair<int, int> diameterSolve(Node* root) {
    if (root == NULL) return make_pair(0, 0);

    pair<int, int> left = diameterSolve(root->left);
    pair<int, int> right = diameterSolve(root->right);

    int l = left.first;
    int r = right.first;
    int c = left.second + 1 + right.second;

    pair<int, int> ans;
    ans.first = max(max(l, r), c);
    ans.second = max(l, r) + 1;

    return ans;
}

int diameter(Node* root) {
    return diameterSolve(root).first;
}

pair<bool, int> solveBalanced(Node* root) {
    if (root == NULL) return make_pair(true, 0);

    pair<bool, int> left = solveBalanced(root->left);
    pair<bool, int> right = solveBalanced(root->right);

    bool l = left.first;
    bool r = right.first;
    bool c = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.first = l && r && c;
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

bool isBalanced(Node* root) {
    return solveBalanced(root).first;
}

bool isIdentical(Node* r1, Node* r2) {
    if (r1 == NULL && r2 == NULL) return true;
    if (r1 == NULL || r2 == NULL) return false;

    if (r1->data == r2->data) {
        return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    }

    return false;
}

int main() {
    // 1. Height of binary tree
    // https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

    // 2. Diameter of binary tree
    // https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1

    // 3. Check for balanced tree
    // https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

    // 4. Identical Trees
    // https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
}
