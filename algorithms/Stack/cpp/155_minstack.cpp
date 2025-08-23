#include <iostream>
#include <stack>
#include <limits.h>

using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push(val);
        if(minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }

    }
    
    void pop() {
        if(mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl; // Returns -3
    obj->pop();
    cout << obj->top() << endl;    // Returns 0
    cout << obj->getMin() << endl; // Returns -2
    delete obj;
    return 0;
}