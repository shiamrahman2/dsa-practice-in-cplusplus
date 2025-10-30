#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
    // ~Node()
    // {
    //     if (next != NULL)
    //     {
    //         delete next;
    //         next = NULL;
    //     }
    // }
};
class List
{
public:
    Node *head;
    Node *tail;
    List()
    {
        head = NULL;
        tail = NULL;
    }
    // ~List()
    // {
    //     if (head != NULL)
    //     {
    //         delete head;
    //         head = NULL;
    //     }
    // }
    void push_front(int value)
    { // O(1)
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    Node* reverse(Node* head)
    {
        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Split a linked list into two halves
    Node *spliteAtRight(Node *head)
    {
        Node *slow = head; // Moves one step at a time
        Node *fast = head; // Moves two steps at a time
        Node *prev = NULL; // Tracks node before slow

        // Find middle of the list
        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Break the list into two halves
        if (prev != NULL)
        {
            prev->next = NULL;
        }

        return slow; // Return head of right half
    }
    // Rearrange a linked list in zig-zag (1 → n → 2 → n-1 → 3 → n-2 ...) pattern
/*

Purpose:
To rearrange a linked list in a zig-zag pattern like
1 → n → 2 → n-1 → 3 → n-2 → ...

Step-by-step explanation:

1. Split the list into two halves:
   - Use the spliteAtRight() function to find the middle of the list.
   - This separates the linked list into left and right halves.

2. Reverse the right half:
   - Call the reverse() function to reverse the right half.
   - This makes it easier to merge from both ends alternately.

3. Initialize pointers:
   - left → points to the first half.
   - right → points to the reversed second half.
   - tail → keeps track of the last connected node.

4. Merge alternately (Zig-Zag pattern):
   - Take one node from the left list, then one from the right list.
   - Continue this process until one list becomes empty.
   - Example pattern: Left1 → Right1 → Left2 → Right2 → ...

5. Attach remaining nodes:
   - If any nodes remain in the right half, connect them to the end.

6. Return the new head:
   - The head now points to the zig-zag arranged linked list.

Complexity:
- Time Complexity: O(n)
- Space Complexity: O(1)

*/

Node* zigZagLL(Node* head)
{
    // Step 1: Split the linked list into two halves
    Node* rightHead = spliteAtRight(head);

    // Step 2: Reverse the right half for zig-zag merging
    Node* reverseRightHead = reverse(rightHead);

    // Step 3: Initialize pointers for merging
    Node* left = head;               // Start of the first (left) half
    Node* right = reverseRightHead;  // Start of the reversed (right) half
    Node* tail = right;              // Keeps track of the last connected node

    // Step 4: Merge both halves alternately (zig-zag fashion)
    while (left != NULL && right != NULL)
    {
        Node* nextLeft = left->next;   // Store next node of left half
        Node* nextRight = right->next; // Store next node of right half

        left->next = right;            // Link left node to right node
        right->next = nextLeft;        // Link right node to next left node

        tail = right;                  // Update tail to the last connected node
        left = nextLeft;               // Move left pointer forward
        right = nextRight;             // Move right pointer forward
    }

    // Step 5: If there are remaining nodes in the right half, attach them
    if (tail != NULL)
    {
        tail->next = right;
    }

    // Step 6: Return the new head of the zig-zag arranged linked list
    return head;
}


};
int main()
{
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();
    ll.head=ll.zigZagLL(ll.head);
    ll.printList();
    return 0;
}