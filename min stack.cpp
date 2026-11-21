#include <iostream>
#include <stack>
using namespace std;
class MinStack {
public:
    /**
     * Initialize the MinStack with two internal stacks:
     * - mainStack: stores all elements
     * - minStack: stores the minimum element at each level
     */
    MinStack() {
        // Initialize minStack with INT_MAX as a sentinel value
        // This handles the edge case when the stack is empty
        minStack.push(INT_MAX);
    }
  
    /**
     * Push element val onto the stack
     * Time Complexity: O(1)
     * @param val: the value to be pushed
     */
    void push(int val) {
        // Push the value onto the main stack
        mainStack.push(val);
      
        // Push the minimum between current value and previous minimum
        // This ensures minStack.top() always contains the current minimum
        minStack.push(min(val, minStack.top()));
    }
  
    /**
     * Remove the element on top of the stack
     * Time Complexity: O(1)
     */
    void pop() {
        // Remove top element from both stacks to maintain synchronization
        mainStack.pop();
        minStack.pop();
    }
  
    /**
     * Get the top element of the stack
     * Time Complexity: O(1)
     * @return: the top element
     */
    int top() {
        return mainStack.top();
    }
  
    /**
     * Retrieve the minimum element in the stack
     * Time Complexity: O(1)
     * @return: the minimum element
     */
    int getMin() {
        return minStack.top();
    }
  
private:
    stack<int> mainStack;  // Stack to store all elements
    stack<int> minStack;   // Stack to track minimum elements at each level
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
