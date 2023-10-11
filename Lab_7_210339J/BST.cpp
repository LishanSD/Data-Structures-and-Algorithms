#include <iostream>
using namespace std;

struct Node
{
  int key;
  Node *left, *right;

  Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Utility: Find minimum node in a subtree
Node *minNode(Node *root)
{
  while (root && root->left)
    root = root->left;
  return root;
}

// Inorder traversal (LNR)
void traverseInOrder(const Node *root)
{
  if (!root)
    return;
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
Node *insertNode(Node *root, int key)
{
  if (!root)
    return new Node(key);
  if (key < root->key)
    root->left = insertNode(root->left, key);
  else
    root->right = insertNode(root->right, key);
  return root;
}

// Delete a node
Node *deleteNode(Node *root, int key)
{
  if (!root)
    return nullptr;

  if (key < root->key)
  {
    root->left = deleteNode(root->left, key);
  }
  else if (key > root->key)
  {
    root->right = deleteNode(root->right, key);
  }
  else
  {
    // Node with one child or no child
    if (!root->left)
    {
      Node *temp = root->right;
      delete root;
      return temp;
    }
    else if (!root->right)
    {
      Node *temp = root->left;
      delete root;
      return temp;
    }
    // Node with two children: Get inorder successor
    Node *temp = minNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver
int main()
{
  Node *root = nullptr;

  int operation, operand;
  while (cin >> operation && operation != -1)
  {
    switch (operation)
    {
    case 1: // insert
      cin >> operand;
      root = insertNode(root, operand);
      break;
    case 2: // delete
      cin >> operand;
      root = deleteNode(root, operand);
      break;
    default:
      cout << "Invalid Operator!\n";
      return 0;
    }
  }

  traverseInOrder(root);
  cout << endl;
}
