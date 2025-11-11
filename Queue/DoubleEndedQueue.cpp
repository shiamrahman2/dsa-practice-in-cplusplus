

/*
std::deque Functions - Complete Reference

CONSTRUCTORS & DESTRUCTOR:
deque() - Default constructor, creates empty deque
deque(size_type count) - Creates deque with count default-initialized elements
deque(size_type count, const T& value) - Creates deque with count copies of value
deque(InputIt first, InputIt last) - Creates deque from range [first, last)
deque(const deque& other) - Copy constructor
deque(deque&& other) - Move constructor (C++11)
deque(initializer_list<T> init) - Creates deque from initializer list (C++11)
~deque() - Destructor, clears all elements

ELEMENT ACCESS FUNCTIONS:
at(size_type pos) - Access element with bounds checking, throws std::out_of_range - O(1)
operator[](size_type pos) - Access element without bounds checking - O(1)
front() - Returns reference to first element - O(1)
back() - Returns reference to last element - O(1)

CAPACITY FUNCTIONS:
empty() - Returns true if deque is empty - O(1)
size() - Returns number of elements - O(1)
max_size() - Returns maximum possible number of elements - O(1)
shrink_to_fit() - Reduces memory usage (non-binding) - Usually O(n)
resize(size_type count) - Changes number of elements - O(n)
resize(size_type count, const T& value) - Resizes with specified value for new elements - O(n)

MODIFIER FUNCTIONS:
clear() - Removes all elements - O(n)
insert(const_iterator pos, const T& value) - Inserts element before position - O(n)
insert(const_iterator pos, size_type count, const T& value) - Inserts count copies - O(n)
insert(const_iterator pos, InputIt first, InputIt last) - Inserts range of elements - O(n)
insert(const_iterator pos, initializer_list<T> ilist) - Inserts from initializer list - O(n)
emplace(const_iterator pos, Args&&... args) - Constructs element in-place (C++11) - O(n)
erase(const_iterator pos) - Removes element at position - O(n)
erase(const_iterator first, const_iterator last) - Removes range of elements - O(n)
push_back(const T& value) - Adds element to the end - O(1)
push_back(T&& value) - Adds element to the end (move) - O(1)
push_front(const T& value) - Adds element to the beginning - O(1)
push_front(T&& value) - Adds element to the beginning (move) - O(1)
emplace_back(Args&&... args) - Constructs element at end in-place (C++11) - O(1)
emplace_front(Args&&... args) - Constructs element at front in-place (C++11) - O(1)
pop_back() - Removes last element - O(1)
pop_front() - Removes first element - O(1)
swap(deque& other) - Exchanges contents with another deque - O(1)

ITERATOR FUNCTIONS:
begin(), cbegin() - Iterator to first element
end(), cend() - Iterator to one past last element
rbegin(), crbegin() - Reverse iterator to last element
rend(), crend() - Reverse iterator to one before first

OPERATIONS FUNCTIONS:
swap(deque& other) - Member swap function - O(1)
get_allocator() - Returns associated allocator - O(1)

NON-MEMBER FUNCTIONS:
operator==, operator!= - Equality comparison
operator<, operator<=, operator>, operator>= - Lexicographical comparison
std::swap(deque&, deque&) - Specialized std::swap algorithm

PERFORMANCE CHARACTERISTICS:
- Front/Back Operations: push_front(), push_back(), pop_front(), pop_back() - O(1)
- Random Access: at(), operator[] - O(1)
- Middle Insertion/Deletion: insert(), erase() - O(n)
- Iterators: Random access iterators
- Memory: Multiple chunks, doesn't require contiguous memory like vector

ITERATOR INVALIDATION RULES:
- Insertion at front/back: Invalidates all iterators, but references to elements remain valid
- Insertion in middle: Invalidates all iterators and references
- Deletion at front/back: Invalidates iterators to deleted elements only
- Deletion in middle: Invalidates all iterators and references
- swap(): Invalidates all iterators (but swaps the invalidation with the other deque)

KEY FEATURES:
- Double-ended queue (insert/remove from both ends efficiently)
- Dynamic size allocation
- Non-contiguous memory storage
- Random access capability
- Typically implemented as array of arrays
*/




#include<bits/stdc++.h>
using namespace std;
int main()
{   
    deque<int>dq;
    dq.push_front(2);
    dq.push_front(1);
    dq.push_back(3);
    dq.push_back(4);
    cout<<"Front Value:"<<dq.front()<<endl;
    cout<<"Back Value:"<<dq.back()<<endl;
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    return 0;
}