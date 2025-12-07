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

vector<int> zigZagTraversal(Node* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> temp(size);

        for (int i = 0; i < size; i++) {
            Node* front = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            temp[index] = front->data;

            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }

        leftToRight = !leftToRight;

        for (auto i : temp) {
            ans.push_back(i);
        }
    }

    return ans;
}

int main() {
    // 1. Zig Zag Traversal
    // https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

    // 2. Boundary Traversal
    // https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
}
