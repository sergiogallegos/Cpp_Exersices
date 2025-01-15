#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
struct NodeBST {
  int data;
  NodeBST* left;
  NodeBST* right;

  NodeBST(int val) : data(val), left(nullptr), right(nullptr) {}
};

NodeBST* insert(NodeBST* root, int val) {
  if (!root) return new NodeBST(val);
  if(val < root->data)
	root->left = insert(root->left, val);
  else
	root->right = insert(root->right, val);
  return root;
}

void inOrderTraversal(NodeBST* root) {
  if (!root) return;
  inOrderTraversal(root->left);
  std::cout << root->data << " ";
  inOrderTraversal(root->right);
}

// Linked List
struct Node {
  int data;
  Node* next;

  Node(int val) : data(val), next(nullptr) {}
};

void printList(Node* head) {
  Node* current = head;
  while (current) {
	std::cout << current->data << " ";
	current = current->next;
  }
  std::cout << std::endl;
}

// OOP
class Animal {
protected:
  std::string name;

public:
  Animal(std::string n) : name(n) {}
  virtual void sound() const = 0; // Pure virtual function
};

class Dog : public Animal {
public:
  Dog(std::string n) : Animal(n) {}
  void sound() const override {
  std::cout << name << " says Woof!" << std::endl;
  }
};

// Linear Search Algo
int linearSearch(const std::vector<int>& arr, int target) {
  for (size_t i = 0; i < arr.size(); ++i) {
	if (arr[i] == target) return i; // found, return index
  }
  return -1; // not found
}

// Binary Search Algo
int binarySearch(const std::vector<int> arr, int target) {
  int left = 0, right = arr.size() - 1;
  while (left <= right) {
	int mid = left + (right - left) / 2;
	if (arr[mid] == target) return mid; // found
	else if (arr[mid] < target) left = mid + 1;
	else right = mid - 1;
  }
  return -1; // not found
}

// Bubble Sort
void bubbleSort(std::vector<int>& arr) {
  for (size_t i = 0; i < arr.size() - 1; ++i) {
	for (size_t j = 0; j < arr.size() -i -1; ++j) {
	  if (arr[j] > arr[j + 1]) {
			std::swap(arr[j], arr[j + 1]);
		  }
	}
  }
}

// Quick Sort
void quickSort(std::vector<int>& arr, int low, int high) {
  if (low < high) {
	int pivot = arr[high]; // pivot element
	int i = low - 1;

	for (int j = low; j < high; ++j) {
	  if (arr[j] < pivot) {
		++i;
		std::swap(arr[i], arr[j]);
	  }
	}
	std::swap(arr[i + 1], arr[high]);
	int pi = i + 1; // partition index
	
	quickSort(arr, low, pi - 1); // left partition
	quickSort(arr, pi + 1, high); // right partition
  }
}

// Merge Sort
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // size of the left half
    int n2 = right - mid; // size of the right half

    std::vector<int> L(n1), R(n2); // create a temporary arrays L and R
	
	// fill L with the left half of the array
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
	// fill R with the right half of the array
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Stack using Linked List
class Stack {
private:
    Node* top; // Pointer to the top of the stack
public:
    Stack() : top(nullptr) {}

    // Push an element onto the stack
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    // Pop the top element from the stack
    void pop() {
        if (!top) {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Peek the top element
    int peek() {
        if (!top) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Queue using Linked List
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue
public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue an element at the rear
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (!rear) {
            // If the queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue an element from the front
    void dequeue() {
        if (!front) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr; // If the queue becomes empty
        delete temp;
    }

    // Peek the front element
    int peek() {
        if (!front) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
  std::cout << "Hello" << '\n';
  
  // basics (findmax)
  std::vector<int> nums = {2, 5, 8, 3, 9};
  std::cout << "Max: " << findMax(nums) << std::endl;
  
  // recursion (factorial)
  std::cout << "Factorial of 5: " << factorial(5) << std::endl;
  
  // BST
  NodeBST* root = nullptr;
  root = insert(root, 10);
  insert(root, 5);
  insert(root, 15);
  insert(root, 3);
  std::cout << "In-order travesal: ";
  inOrderTraversal(root);
  std::cout << std::endl;
  
  // Linked List
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  printList(head);

  // OOP
  Dog myDog("Buddy");
  myDog.sound();
  
  // linear search algo
  std::vector<int> nums2 = {10, 20, 30, 40, 50};
  int target = 30;
  int result = linearSearch(nums2, target);
  std::cout << "Element " << target << " found at index: " << result << std::endl;
  
  // binary search algo
  result = binarySearch(nums2, target);
  std::cout << "Element " << target << " found at index: " << result << std::endl; 
  
  // bubble sort
  std::vector<int> nums3 = {5, 2, 9, 1, 5, 6};
  bubbleSort(nums3);
  for (int num: nums3) std::cout << num << " ";
  std::cout << std::endl;
  
  // quick sort
  std::vector<int> nums4 = {3, 4, 1, 5, 9, 3};
  quickSort(nums4, 0, nums4.size() - 1);
  for (int num: nums4) std::cout << num << " ";
  std::cout << std::endl;
  
  // merger sort
  std::vector<int> nums5 = {12, 11, 13, 5, 6, 7};
  mergeSort(nums5, 0, nums5.size() - 1);
  for (int num : nums5) std::cout << num << " ";
  std::cout << std::endl;
  
  // stack
  Stack stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);

  std::cout << "Top of stack: " << stack.peek() << std::endl; // 30

  stack.pop();
  std::cout << "Top of stack after pop: " << stack.peek() << std::endl; // 20

  // queues
  Queue queue;
  queue.enqueue(10);
  queue.enqueue(20);
  queue.enqueue(30);
  queue.enqueue(24);

  std::cout << "Front of queue: " << queue.peek() << std::endl; // 10

  queue.dequeue();
  std::cout << "Front of queue after dequeue: " << queue.peek() << std::endl; // 20

  return 0;
}
