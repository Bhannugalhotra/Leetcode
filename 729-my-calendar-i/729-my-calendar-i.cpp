class MyCalendar 
{
    map<int,int> calander;
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        auto prev = calander.upper_bound(start);
        
        auto next = calander.lower_bound(start);
        
        if(prev != calander.begin()){
            
            prev--;
            
            if(prev -> second > start)
                return false;
        }

        if(next != calander.end() and next -> first < end)
            return false;
        
        calander[start] = end;
        
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */