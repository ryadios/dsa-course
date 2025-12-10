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

void solve(Node* root, int sum, int& maxSum, int len, int& maxLen) {
    if (!root) {
        if (len > maxLen) {
            maxLen = len;
            maxSum = sum;
        } else if (len == maxLen) {
            maxSum = max(sum, maxSum);
        }

        return;
    }

    sum += root->data;

    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongRootToLeafPath(Node* root) {
    int maxSum = 0, maxLen = 0;

    solve(root, 0, maxSum, 0, maxLen);

    return maxSum;
}

Node* lca(Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);

    if (left && right)
        return root;
    else if (!left && right)
        return right;
    else if (left && !right)
        return left;
    else
        return NULL;
}

int solve(Node* root, int k, int currSum, unordered_map<int, int>& prefix) {
    if (root == NULL) return 0;

    int paths = 0;
    currSum += root->data;

    if (currSum == k) paths++;

    paths += prefix[currSum - k];
    prefix[currSum]++;

    paths += solve(root->left, k, currSum, prefix);
    paths += solve(root->right, k, currSum, prefix);

    prefix[currSum]--;

    return paths;
}

int countAllPaths(Node* root, int k) {
    unordered_map<int, int> prefix;
    int res = solve(root, k, 0, prefix);

    return res;
}

Node* solve(Node* root, int& count, int node) {
    if (root == NULL) return NULL;
    if (root->data == node) return root;

    Node* left = solve(root->left, count, node);
    Node* right = solve(root->right, count, node);

    if (left || right) {
        count--;
        if (count == 0) return root;
    }

    return left ? left : right;
}

int kthAncestor(Node* root, int k, int node) {
    int count = k;
    Node* ptr = solve(root, count, node);

    if (count > 0) return -1;
    return ptr->data;
}

pair<int, int> solve(Node* root) {
    if (root == NULL) return {0, 0};

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> res;

    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}
int getMaxSum(Node* root) {
    auto [a, b] = solve(root);

    return max(a, b);
}

int main() {
    // 1. Sum of nodes on longest path
    // https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

    // 2. LCA in binary tree
    // https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

    // 3. K Sum Paths
    // https://www.geeksforgeeks.org/problems/k-sum-paths/1

    // 4. Kth Ancestor
    // https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
}
