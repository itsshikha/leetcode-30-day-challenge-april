/*
  Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

  push(x) -- Push element x onto stack.
  pop() -- Removes the element on top of the stack.
  top() -- Get the top element.
  getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    /** initialize your data structure here. */
    vector<vector<int>> st;
    MinStack() {
    }
    
    void push(int x) {
        if(st.size()==0)
            st.push_back({x,x});
        else{
            if(st[st.size()-1][1]>x)
                st.push_back({x,x});
            else
                st.push_back({x,st[st.size()-1][1]});
        }
        
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st[st.size()-1][0];
    }
    
    int getMin() {
        return st[st.size()-1][1];
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
