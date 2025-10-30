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
    void push_back(int value)
    { // O(1)
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_front()
    { // O(1)
        if (head == NULL)
        {
            cout << "Empty List" << endl;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }
    void pop_back()
    { // O(N);
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    void insert(int value, int position)
    {
        Node *newNode = new Node(value);
        Node *temp = head;
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Position Invalid" << endl;
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
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
    void reverse()
    {
        tail = head;
        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    int size()
    {
        Node *temp = head;
        int sz = 0;
        while (temp != NULL)
        {
            sz++;
            temp = temp->next;
        }
        return sz;
    }
    int searchItr(int key)
    {
        Node *temp = head;
        int index = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return index;
            }
            index++;
            temp = temp->next;
        }
        return -1;
    }
    int helper(Node *temp, int key)
    {
        if (temp == NULL)
        {
            return -1;
        }
        if (temp->data == key)
        {
            return 0;
        }
        int ind = helper(temp->next, key);
        if (ind == -1)
        {
            return -1;
        }
        else
        {
            return ind + 1;
        }
    }
    int searchRec(int key)
    {
        return helper(head, key);
    }
    void removeCycle(Node *head)
    {

        Node *slow = head;
        Node *fast = head;
        bool isCycle = false;
        // detect cycle
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                cout << "Cycle Detect" << endl;
                isCycle = true;
                break;
            }
        }
        if (!isCycle)
        {
            cout << "Cycle doesn't exists" << endl;
            return;
        }
        slow = head; // update slow value
        if (slow == fast)
        { // handle corner case where tail->head complete cycle
            while (fast->next != slow)
            {
                fast = fast->next;
            }
            fast->next = NULL; // remove cycle
        }
        else
        {
            Node *prev = fast;
            while (fast != slow)
            {
                slow = slow->next;
                prev = fast;
                fast = fast->next;
            }
            prev->next = NULL; // remove cycle
        }
    }
    Node *merge(Node *left, Node *right)
    {
        List ans;
        Node *i = left;
        Node *j = right;
        while (i != NULL && j != NULL)
        {
            if (i->data < j->data)
            {
                ans.push_back(i->data);
                i = i->next;
            }
            else
            {
                ans.push_back(j->data);
                j = j->next;
            }
        }
        while (i != NULL)
        {
            ans.push_back(i->data);
            i = i->next;
        }
        while (j != NULL)
        {
            ans.push_back(j->data);
            j = j->next;
        }
        return ans.head;
    }
    Node *spliteAtRight(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        Node *prev = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev != NULL)
        {
            prev->next = NULL;
        }
        return slow;
    }
    Node* mergeSort(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node* rightHead = spliteAtRight(head);
        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);
        return merge(left, right);
    }
};
int main()
{
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.printList();
    ll.head = ll.mergeSort(ll.head);
    ll.printList();
    return 0;
}