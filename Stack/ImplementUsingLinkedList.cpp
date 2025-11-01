#include <bits/stdc++.h>
using namespace std;

// ===========================
// Node class (Template-based)
// ===========================
// Each Node holds a value (data) and a pointer (next) to the next Node.
template <class T>
class Node {
public:
    T data;          // To store the value of the node
    Node<T>* next;   // Pointer to the next node in the stack

    // Constructor to initialize a node with a given value
    Node(T val) {
        data = val;
        next = NULL; // By default, next pointer is NULL
    }
};

// ===========================
// Stack class (Template-based)
// ===========================
// Stack is implemented using a linked list (LIFO structure)
template <class T>
class Stack {
    Node<T>* head;  // Points to the top element of the stack

public:
    // Constructor: initially, stack is empty, so head = NULL
    Stack() {
        head = NULL;
    }

    // ----------------------------
    // push() → Add element on top
    // ----------------------------
    void push(T val) {
        // Create a new node
        Node<T>* newNode = new Node<T>(val);
        // Make new node point to the current head (top element)
        newNode->next = head;

        // Move head to point to the new node (now it's the new top)
        head = newNode;
    }

    // ----------------------------
    // pop() → Remove top element
    // ----------------------------
    void pop() {
        // If stack is empty, nothing to remove
        if (head == NULL) {
            cout << "Stack is empty! Nothing to pop." << endl;
            return;
        }

        // Temporarily store the current head node
        Node<T>* temp = head;

        // Move head to the next node (removing the top one)
        head = head->next;

        // Delete the removed node to free memory
        delete temp;
    }

    // --------------------------------------
    // top() → Return the value of top element
    // --------------------------------------
    T top() {
        // Check if stack is empty before accessing top
        if (head == NULL) {
            throw runtime_error("Stack is empty! No top element.");
        }

        // Return the data of the top element
        return head->data;
    }

    // --------------------------------------
    // isEmpty() → Check if stack is empty
    // --------------------------------------
    bool isEmpty() {
        return head == NULL;
    }
};

// ===========================
// Main Function (Test the Stack)
// ===========================
int main() {
    // Create a stack of integers
    Stack<int> s;

    // Push some values onto the stack
    s.push(3);  // Stack: 3
    s.push(2);  // Stack: 2 -> 3
    s.push(1);  // Stack: 1 -> 2 -> 3

    // Pop and print all elements until stack becomes empty
    while (!s.isEmpty()) {
        cout << s.top() << " "; // Print the top element
        s.pop();                // Remove the top element
    }

    // Output: 1 2 3
    return 0;
}
