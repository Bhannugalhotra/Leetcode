class MyStack {
    
    queue<int> q1;
    queue<int> q2;
    
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(!q1.empty()){
            q1.push(x);
        }
        
        else{
            q2.push(x);
        }
    }
    
    int pop() {
        
        if(!q1.empty()){
            
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            
            int val = q1.front();
            q1.pop();
            return val;
        }
        
        else if(!q2.empty()){
            
            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            
            int val = q2.front();
            q2.pop();
            return val;
        }
        
        return -1;
    }
    
    int top() {
        
        if(!q1.empty()){
            
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            
            int val = q1.front();
            q1.pop();
            q2.push(val);
            return val;
        }
        
        else if(!q2.empty()){
            
            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            
            int val = q2.front();
            q2.pop();
            q1.push(val);
            return val;
        }
        
        return -1;
    }
    
    bool empty() {
        
        return q1.empty() and q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */