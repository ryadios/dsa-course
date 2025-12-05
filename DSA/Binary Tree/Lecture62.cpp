#include <bits/stdc++.h>
#include <queue>
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

Node* buildTree(Node* root) {
    cout << "Enter data: ";
    int data;
    cin >> data;

    if (data == -1) return NULL;

    root = new Node(data);

    cout << "Enter data for inserting to left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting to right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        } else {
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

void reverseLevelOrderTraversal(Node* root) {
    queue<Node*> q;
    stack<int> st;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            st.push(-1);
            if (!q.empty()) q.push(NULL);
        } else {
            st.push(temp->data);
            if (temp->right) q.push(temp->right);
            if (temp->left) q.push(temp->left);
        }
    }

    while (!st.empty()) {
        if (st.top() == -1)
            cout << endl;
        else
            cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void inorderTraversal(Node* root) { // LPR
    if (root == NULL) return;

    // inorderTraversal(root->left);  // L
    // cout << root->data << " ";     // P
    // inorderTraversal(root->right); // R

    Node* temp = root;
    stack<Node*> st;
    while (true) {
        if (temp != NULL) {
            st.push(temp);
            temp = temp->left;
        } else {
            if (st.empty()) break;
            temp = st.top();
            st.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
}

void preorderTraversal(Node* root) { // PLR
    if (root == NULL) return;

    cout << root->data << " ";      // P
    preorderTraversal(root->left);  // L
    preorderTraversal(root->right); // R
}

void postorderTraversal(Node* root) { // LRP
    if (root == NULL) return;

    postorderTraversal(root->left);  // L
    postorderTraversal(root->right); // R
    cout << root->data << " ";       // P
}

void buildFromLevelOrder(Node*& root) {
    queue<Node*> q;
    cout << "Enter Data:" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left of " << temp->data << endl;
        int left;
        cin >> left;

        if (left != -1) {
            temp->left = new Node(left);
            q.push(temp->left);
        }

        cout << "Enter right of " << temp->data << endl;
        int right;
        cin >> right;

        if (right != -1) {
            temp->right = new Node(right);
            q.push(temp->right);
        }
    }
}

int main() {
    Node* root = NULL;

    // root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    buildFromLevelOrder(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    levelOrderTraversal(root);

    // cout << "Level Order Traversal" << endl;
    // levelOrderTraversal(root);

    // cout << "Reverse Level Order Traversal" << endl;
    // reverseLevelOrderTraversal(root);

    // cout << "In Order Traversal" << endl;
    // inorderTraversal(root);
    // cout << endl;

    // cout << "Pre Order Traversal" << endl;
    // preorderTraversal(root);
    // cout << endl;

    // cout << "Post Order Traversal" << endl;
    // postorderTraversal(root);
    // cout << endl;
}
