
/*

CLASS Queue
    DECLARE stack s1, s2

    FUNCTION push(data)
        // Step 1: Move all elements from s1 to s2
        WHILE s1 is not empty DO
            s2.push(s1.top)
            s1.pop()
        END WHILE

        // Step 2: Push new data into s1
        s1.push(data)

        // Step 3: Move all elements back from s2 to s1
        WHILE s2 is not empty DO
            s1.push(s2.top)
            s2.pop()
        END WHILE
    END FUNCTION


    FUNCTION pop()
        s1.pop()
    END FUNCTION


    FUNCTION front() RETURNS INTEGER
        RETURN s1.top
    END FUNCTION


    FUNCTION empty() RETURNS BOOLEAN
        RETURN (s1 is empty)
    END FUNCTION
END CLASS


MAIN
    CREATE object q of Queue

    q.push(1)
    q.push(2)
    q.push(3)
    q.push(4)

    WHILE q is not empty DO
        PRINT q.front()
        q.pop()
    END WHILE
END MAIN



*/ 


#include<bits/stdc++.h>
using namespace std;
class Queue{
  stack<int>s1;
  stack<int>s2;
  public:
    void push(int data){// O(N)
        // step-01 s1 element ->s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        // step-02 data input into s1
        s1.push(data);
        // step-03: s2 element ->s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop(){
        s1.pop();
    }
    int front(){
        return s1.top();
    }
    bool empty(){
        return s1.empty();
    }
};
int main()
{   
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}