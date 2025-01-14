#include <iostream>
#include <vector>

// Basics, Control Flow, Arrays
int findMax(const std::vector<int>& arr) {
  int max = arr[0];
  for (int num : arr) {
	if (num > max) max = num;
  }
  return max;
}

// Recursion
int factorial(int n) {
  return (n <= 1) ? 1 : n * factorial(n - 1);
}

// Binary Search Tree (BST)
struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
  if (!root) return new Node(val);
  if(val < root->data)
	root->left = insert(root->left, val);
  else
	root->right = insert(root->right, val);
  return root;
}

void inOrderTraversal(Node* root) {
  if (!root) return;
  inOrderTraversal(root->left);
  std::cout << root->data << " ";
  inOrderTraversal(root->right);
}

int main() {
  std::cout << "Hello" << '\n';
  
  // basics (findmax)
  std::vector<int> nums = {2, 5, 8, 3, 9};
  std::cout << "Max: " << findMax(nums) << std::endl;
  
  // recursion (factorial)
  std::cout << "Factorial of 5: " << factorial(5) << std::endl;
  
  // BST
  Node* root = nullptr;
  root = insert(root, 10);
  insert(root, 5);
  insert(root, 15);
  insert(root, 3);
  std::cout << "In-order travesal: ";
  inOrderTraversal(root);
  std::cout << std::endl;

  return 0;
}
