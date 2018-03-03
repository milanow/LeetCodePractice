/* 716. Max Stack
 * Two stack, one is regular stack, the other one is max stack, saving those numbers
 * who is larger than current max stack's top.
 * The key difference with regular stack:
 * 1. When pushing a number, we add it to regular stack and also try to add it to max stack
 * 2. When poping a max number, we need to re-push numbers that are above the max number into
 *    max stack
 */

class MaxStack {
    stack<int> stk, mxstk;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        addMax(x);
        stk.push(x);
    }
    
    int pop() {
        if(stk.empty()) return -1;
        int val = stk.top();
        if(mxstk.top() == val){
            mxstk.pop();
        }
        stk.pop();
        return val;
    }
    
    int top() {
        if(stk.empty()) return -1;
        return stk.top();
    }
    
    int peekMax() {
        if(stk.empty()) return -1;
        return mxstk.top();
    }
    
    int popMax() {
        if(stk.empty()) return -1;
        
        stack<int> tmp;
        int val = mxstk.top();
        while(stk.top() != val){
            tmp.push(stk.top());
            stk.pop();
        }
        stk.pop();
        mxstk.pop();
        
        while(!tmp.empty()){
            stk.push(tmp.top());
            addMax(tmp.top());
            tmp.pop();
        }
        return val;
        
    }
    
private:
    void addMax(int x){
        if(mxstk.empty() || x >= mxstk.top()){
            mxstk.push(x);
        }
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */