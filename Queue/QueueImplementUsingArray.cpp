/*

CLASS Queue
    DECLARE arr, capacity, currSize, frontIndex, rear

    FUNCTION Queue(capacity)
        SET this.capacity = capacity
        CREATE array arr of size capacity
        SET currSize = 0
        SET frontIndex = 0
        SET rear = -1
    END FUNCTION

    FUNCTION push(value)
        IF currSize == capacity THEN
            PRINT "Queue is Full"
            RETURN
        END IF
        rear = (rear + 1) MOD capacity
        arr[rear] = value
        currSize = currSize + 1
    END FUNCTION

    FUNCTION pop()
        IF empty() THEN
            PRINT "Queue is empty"
            RETURN
        END IF
        frontIndex = (frontIndex + 1) MOD capacity
        currSize = currSize - 1
    END FUNCTION

    FUNCTION front()
        RETURN arr[frontIndex]
    END FUNCTION

    FUNCTION empty()
        RETURN (currSize == 0)
    END FUNCTION
END CLASS


int main() {
    Queue q(3);

    // ----------------- INITIAL STATE -----------------
    // arr = [_, _, _]
    // frontIndex = 0, rear = -1, currSize = 0

    q.push(10);
    // rear = (−1 + 1) % 3 = 0
    // arr = [10, _, _]
    // frontIndex = 0, currSize = 1

    q.push(20);
    // rear = (0 + 1) % 3 = 1
    // arr = [10, 20, _]
    // frontIndex = 0, currSize = 2

    q.push(30);
    // rear = (1 + 1) % 3 = 2
    // arr = [10, 20, 30]
    // frontIndex = 0, currSize = 3

    q.push(40);
    // Queue is Full (since currSize == capacity)
    // arr = [10, 20, 30]

    cout << q.front() << endl;
    // Output → 10
    // frontIndex = 0 (front element = 10)

    q.pop();
    // frontIndex = (0 + 1) % 3 = 1
    // currSize = 2
    // arr = [10, 20, 30]
    // Logical queue → [20, 30]

    cout << q.front() << endl;
    // Output → 20
    // frontIndex = 1 (front element = 20)

    q.pop();
    // frontIndex = (1 + 1) % 3 = 2
    // currSize = 1
    // Logical queue → [30]

    q.pop();
    // frontIndex = (2 + 1) % 3 = 0
    // currSize = 0
    // Queue becomes empty

    q.pop();
    // Queue is empty
    // Output → "Queue is empty"

    return 0;
}

/*
--------------------- OUTPUT ---------------------
Queue is Full
10
20
Queue is empty
--------------------------------------------------

Dry Run Summary:

Step | Operation     | frontIndex | rear | currSize | Queue (logical)
----------------------------------------------------------------------
1    | push(10)      | 0          | 0    | 1         | [10]
2    | push(20)      | 0          | 1    | 2         | [10, 20]
3    | push(30)      | 0          | 2    | 3         | [10, 20, 30]
4    | push(40)      | -          | -    | 3 (Full)  | [10, 20, 30]
5    | front() → 10  | 0          | 2    | 3         | [10, 20, 30]
6    | pop()         | 1          | 2    | 2         | [20, 30]
7    | front() → 20  | 1          | 2    | 2         | [20, 30]
8    | pop()         | 2          | 2    | 1         | [30]
9    | pop()         | 0          | 2    | 0         | []
10   | pop()         | 0          | 2    | 0 (empty) | []


*/
#include<bits/stdc++.h>
using namespace std;
class Queue{
   int *arr;
   int capacity;
   int currSize;
   int frontIndex,rear;
   public:
      Queue(int capacity){
        this->capacity=capacity;
        arr=new int[capacity];
        currSize=0;
        frontIndex=0;
        rear=-1;
      }
      void push(int val){
        if(currSize==capacity){
            cout<<"Queue is Full\n";
            return;
        }
        rear=(rear+1)%capacity;
        arr[rear]=val;
        currSize++;
      }
      void pop(){
          if(empty()){
            cout<<"Queue is empty\n";
          }
          frontIndex=(frontIndex+1)%capacity;
         currSize--;
      }
      int front(){
            return arr[frontIndex];
      }
      bool empty(){
        return currSize==0;
      }
};
int main()
{   
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}