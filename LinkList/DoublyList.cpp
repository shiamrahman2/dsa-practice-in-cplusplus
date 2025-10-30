#include <bits/stdc++.h>
using namespace std;

/*
 * Class: Node
 * Purpose: Represents a node in a Doubly Linked List.
 * Each node contains:
 *   - data: stores the value
 *   - next: pointer to the next node
 *   - prev: pointer to the previous node
 */
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor to initialize a node with a given value
    Node(int value) {
        data = value;
        next = prev = NULL;
    }
};

/*
 * Class: Doublylist
 * Purpose: Implements basic operations of a Doubly Linked List:
 *   - push_front() : insert a node at the beginning
 *   - pop_front()  : delete a node from the beginning
 *   - printDoublyList() : print the list in forward direction
 */
class Doublylist {
public:
    Node* head;
    Node* tail;

    // Constructor: initializes an empty list
    Doublylist() {
        head = tail = NULL;
    }

    // Function to insert a new node at the beginning of the list
    void push_front(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) { // If the list is empty
            head = tail = newNode;
        } else { // Insert at the front
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to print all nodes in the doubly linked list
    void printDoublyList() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to delete a node from the beginning of the list
    void pop_front() {
        if (head == NULL) { // List is empty
            cout << "No valid Node" << endl;
        } else {
            Node* temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL; // Update new head's previous pointer
            }
            temp->next = NULL; // Disconnect the deleted node
            delete temp;       // Free memory
        }
    }
};

/*
 * Function: main
 * Purpose: Demonstrates operations on a Doubly Linked List.
 */
int main() {
    Doublylist dl; // Create a doubly linked list object

    // Insert elements at the front
    dl.push_front(5);
    dl.push_front(4);
    dl.push_front(3);
    dl.push_front(2);
    dl.push_front(1);

    // Print the current list
    dl.printDoublyList();

    return 0;
}
