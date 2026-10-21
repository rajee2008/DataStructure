#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* left;
    Node* right;
};

Node* createNode(int x) {
    Node* newNode = new Node;
    newNode->id = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->id)
        root->left = insert(root->left, x);
    else if (x > root->id)
        root->right = insert(root->right, x);

    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->id << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int ids[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)
        root = insert(root, ids[i]);

    cout << "Employee IDs in ascending order: ";
    inorder(root);

    return 0;
}
