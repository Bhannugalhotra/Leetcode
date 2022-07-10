class RandomizedSet 
{
    // map is used for storing indices of elements in a
    
    unordered_map<int,int> map;
    vector<int> a;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        
        if(map.count(val))
            return false;
        
        a.push_back(val);
        
        map[val] = a.size()-1;
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        
        if(!map.count(val))
            return false;
        
        // to delete the curr elem just swap it with last one and then 
        // delete last element instead
        
        int curr_idx = map[val];
        int last_elem = a.back();
        
        swap(a[curr_idx], a[a.size()-1]);
        
        a.pop_back();
        
        // take care when the element to be deleted is last one itself
        
        map[last_elem] = curr_idx;
        
        map.erase(map.find(val));
        
        
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        int idx = rand() % a.size();
        
        return a[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */