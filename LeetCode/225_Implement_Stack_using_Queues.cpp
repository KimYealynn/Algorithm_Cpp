class MyStack {
private:
    queue<int> que;
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> q;
        while(!que.empty()){
            int a = que.front();
            que.pop();
            q.push(a);
        }
        
        que.push(x);
        
        while(!q.empty()){
            int a = q.front();
            q.pop();
            que.push(a);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int a = que.front();
        que.pop();
        return a;
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */