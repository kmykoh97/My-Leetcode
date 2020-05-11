#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.
 

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
 

// Constraints:

// Methods pop, top and getMin operations will always be called on non-empty stacks.

// solution: use array

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    vector<int> minStack;

    MinStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);

        if (minStack.empty() || x <= minStack.back()) {
            minStack.push_back(x);
        }
    }
    
    void pop() {
        if (minStack.back() == stack.back()) {
            minStack.pop_back();
        }

        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */