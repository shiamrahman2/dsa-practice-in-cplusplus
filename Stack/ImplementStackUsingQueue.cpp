
/*

CLASS Stack:
    // Two queues used to implement stack behavior
    DECLARE queue q1
    DECLARE queue q2


    FUNCTION push(data):
        // Step 1: Move all elements from q1 to q2
        WHILE q1 is not empty:
            q2.enqueue(q1.front)      // move front element of q1 to q2
            q1.dequeue()              // remove element from q1

        // Step 2: Push new element into q1
        q1.enqueue(data)

        // Step 3: Move all elements back from q2 to q1
        WHILE q2 is not empty:
            q1.enqueue(q2.front)      // move front element of q2 to q1
            q2.dequeue()              // remove element from q2
    END FUNCTION



    FUNCTION pop():
        // Remove top element (front of q1)
        IF q1 is not empty:
            q1.dequeue()
        ELSE:
            PRINT "Stack is empty"
    END FUNCTION



    FUNCTION top() RETURNS int:
        // Return top element of stack (front of q1)
        IF q1 is not empty:
            RETURN q1.front
        ELSE:
            PRINT "Stack is empty"
            RETURN -1
    END FUNCTION



    FUNCTION empty() RETURNS bool:
        // Check if q1 is empty
        RETURN (q1 is empty)
    END FUNCTION
END CLASS




// ------------------ MAIN FUNCTION ------------------

MAIN:
    // Create a stack object
    CREATE object s of Stack

    // Push elements onto the stack
    s.push(4)        // Stack: [4]
    s.push(3)        // Stack: [3, 4]
    s.push(2)        // Stack: [2, 3, 4]
    s.push(1)        // Stack: [1, 2, 3, 4]

    // Pop and print elements (LIFO order)
    WHILE s is not empty:
        PRINT s.top()    // Print top element
        s.pop()          // Remove top element
    END WHILE
END MAIN


*/ 

#include<bits/stdc++.h>
using namespace std;
class Stack{
   queue<int>q1;
   queue<int>q2;
   public:
      void push(int data){
          while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
          }
          q1.push(data);
          while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
          }
      }
      void pop(){
          q1.pop();
      } 
      int top(){
           return q1.front();
      }
      bool empty(){
        return q1.empty();
      }
};
int main()
{   
    Stack s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}