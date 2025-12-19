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

Node* createParentMapping(Node* root, int target, map<Node*, Node*>& mp) {
    if (root == NULL) return NULL;

    Node* res = NULL;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (node->data == target) res = node;

        if (node->left) {
            mp[node->left] = node;
            q.push(node->left);
        }

        if (node->right) {
            mp[node->right] = node;
            q.push(node->right);
        }
    }

    return res;
}

int minTime(Node* root, int target) {
    map<Node*, Node*> mp;
    queue<Node*> q;

    // crate node to parent mapping and also return the target node
    Node* targetNode = createParentMapping(root, target, mp);
    int count = 0;

    q.push(targetNode);

    map<Node*, bool> visited;
    visited[targetNode] = true;

    while (!q.empty()) {
        bool flag = 0;
        int size = q.size();

        // looping nodes of the current level
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();

            if (node->left && !visited[node->left]) {
                flag = 1;
                q.push(node->left);
                visited[node->left] = true;
            }

            if (node->right && !visited[node->right]) {
                flag = 1;
                q.push(node->right);
                visited[node->right] = true;
            }

            if (mp.find(node) != mp.end() && !visited[mp[node]]) {
                flag = 1;
                q.push(mp[node]);
                visited[mp[node]] = true;
            }
        }

        if (flag) count++;
    }

    return count;
}

int main() {
    // 1. Burning Tree
    // https://www.geeksforgeeks.org/problems/burning-tree/1
}
