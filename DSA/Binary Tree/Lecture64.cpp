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

void traverseLeft(Node* root, vector<int>& ans) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;

    ans.push_back(root->data);

    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

void traverseLeaf(Node* root, vector<int>& ans) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node* root, vector<int>& ans) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;

    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);

    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    ans.push_back(root->data);

    // Left part
    traverseLeft(root->left, ans);

    // Leaf nodes
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

    // Right part
    traverseRight(root->right, ans);

    return ans;
}

vector<vector<int>> verticalOrder(Node* root) {
    if (root == NULL) return {};
    vector<vector<int>> ans;

    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto [node, level] = q.front();
        q.pop();

        mp[level].push_back(node->data);

        if (node->left) q.push({node->left, level - 1});
        if (node->right) q.push({node->right, level + 1});
    }

    for (auto& pair : mp) {
        ans.push_back(pair.second);
    }

    return ans;
}

// Leetcode Solution (requires sorting of values for same vertical & horizontal level nodes)
vector<vector<int>> verticalTraversal(Node* root) {
    if (root == NULL) return {};

    vector<vector<int>> ans;

    // queue -> [{ Node*, {int, int} }]
    queue<pair<Node*, pair<int, int>>> q;

    // map -> { [int]: { [int]: multiset<> } }
    map<int, map<int, multiset<int>>> mp;

    q.push({root, {0, 0}});

    while (!q.empty()) {
        auto [node, pair] = q.front();
        auto [hd, level] = pair; // horizontal and vertical distance
        q.pop();

        mp[hd][level].insert(node->data);

        if (node->left) q.push({node->left, {hd - 1, level + 1}});
        if (node->right) q.push({node->right, {hd + 1, level + 1}});
    }

    for (auto& p : mp) {
        vector<int> temp;
        for (auto& pair : p.second) {
            for (auto i : pair.second)
                temp.push_back(i);
        }
        ans.push_back(temp);
    }

    return ans;
}

vector<int> topView(Node* root) {
    if (root == NULL) return {};
    vector<int> ans;

    map<int, int> mp;

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, level] = q.front();
        q.pop();

        if (mp.find(level) == mp.end()) mp[level] = node->data;

        if (node->left) q.push({node->left, level - 1});
        if (node->right) q.push({node->right, level + 1});
    }

    for (auto& pair : mp) {
        ans.push_back(pair.second);
    }

    return ans;
}

vector<int> bottomView(Node* root) {
    // code here
    if (root == NULL) return {};
    vector<int> ans;

    map<int, int> mp;

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, level] = q.front();
        q.pop();

        mp[level] = node->data;

        if (node->left) q.push({node->left, level - 1});
        if (node->right) q.push({node->right, level + 1});
    }

    for (auto& pair : mp) {
        ans.push_back(pair.second);
    }

    return ans;
}

vector<int> leftViewBFS(Node* root) {
    if (root == NULL) return {};

    vector<int> ans;
    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();

            if (i == 0) ans.push_back(node->data);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return ans;
}

void solveLeft(Node* root, vector<int>& ans, int level) {
    if (root == NULL) return;

    if (level == ans.size()) ans.push_back(root->data);

    solveLeft(root->left, ans, level + 1);
    solveLeft(root->right, ans, level + 1);
}

vector<int> leftViewDFS(Node* root) {
    vector<int> ans;
    solveLeft(root, ans, 0);

    return ans;
}

void solveRight(Node* root, vector<int>& ans, int level) {
    if (root == NULL) return;

    if (level == ans.size()) ans.push_back(root->data);

    solveRight(root->right, ans, level + 1);
    solveRight(root->left, ans, level + 1);
}

vector<int> rightViewDFS(Node* root) {
    vector<int> ans;
    solveRight(root, ans, 0);

    return ans;
}

vector<int> rightViewBFS(Node* root) {
    if (root == NULL) return {};

    vector<int> ans;
    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();

            if (i == size - 1) ans.push_back(node->data);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return ans;
}

void solve(Node* root, map<int, vector<int>>& mp, int level) {
    if (root == NULL) return;

    mp[level].push_back(root->data);
    if (root->left) solve(root->left, mp, level + 1);
    if (root->right) solve(root->right, mp, level);
}

vector<int> diagonal(Node* root) {
    if (root == NULL) return {};

    vector<int> ans;
    map<int, vector<int>> mp;
    solve(root, mp, 0);

    for (auto& pair : mp) {
        for (auto i : pair.second)
            ans.push_back(i);
    }

    return ans;
}

int main() {
    // 1. Zig Zag Traversal
    // https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

    // 2. Boundary Traversal
    // https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
    // https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

    // 3. Top View
    // https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

    // 4. Bottom View
    // https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

    // 5. Left View
    // https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

    // 6. Right View
    // https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1

    // 7. Diagonal Traversal
    // https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
}
