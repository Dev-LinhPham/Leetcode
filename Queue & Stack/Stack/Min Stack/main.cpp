#include <iostream>
#include <vector>

using namespace std;
class MinStack {
    stack<int> stk, stk_min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
       stk.push(val);
       if(stk_min.empty() || val <= stk_min.top()) stk_min.push(val);
    }
    
    void pop() {
        if(stk.top() == stk_min.top()) stk_min.pop();
        stk.pop();
    }
    
    int top() {
        return stk.empty() ? -1 : stk.top();
    }
    
    int getMin() {
        return stk_min.empty() ? -1 : stk_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */