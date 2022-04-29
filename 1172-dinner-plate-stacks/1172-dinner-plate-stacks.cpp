class DinnerPlates 
{
    
    vector<stack<int>> data;
    set<int> empty;
    set<int> filled;
    
    int idx = 0;
    int capacity;
public:
    
    
    DinnerPlates(int capacity) {
        this -> capacity = capacity;
        data = vector<stack<int>>(1);
        data.reserve(1e4);
    }
    
    void push(int val) {
        
        if(!empty.empty()){
            
            int currIdx = *empty.begin();
            data[currIdx].push(val);
            
            if(data[currIdx].size() == capacity){
                empty.erase(empty.begin());
            }
            
            if(data[currIdx].size() == 1){
                filled.insert(currIdx);
            }
        }
        
        else{
            data[idx].push(val);
            
            if(data[idx].size() == 1)
                filled.insert(idx);
            
            if(data[idx].size() == capacity){
                stack<int> s;
                data.push_back(s);
                idx++;
            }
        }
    }
    
    int pop() {
        
        if(filled.empty())
            return -1;
        
      
        int currIdx = *filled.rbegin();

        return popAtStack(currIdx);
    }
    
    
    int popAtStack(int index) {
        
        if(data[index].empty())
            return -1;
        
        int val = data[index].top();
        
        if(data[index].size() == capacity)
            empty.insert(index);
        
        data[index].pop();
        
        if(data[index].size() == 0)
            filled.erase(filled.find(index));
        
        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */

     
