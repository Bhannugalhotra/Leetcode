
class node
{
	public:
		int key;
		int value;
		
		node(int a, int b) : key(a), value(b) {};
};


class MyHashMap 
{
    
    int TABLE_SIZE;
    vector<node*> a;
    int SIZE;
    int PRIME;
public:
    
    MyHashMap() {
        
        TABLE_SIZE = 41111;
        SIZE = 0;
        PRIME = 1997;
        a = vector<node*>(TABLE_SIZE,NULL);
    }
    
    int hash1(int key){
        
        return (key + TABLE_SIZE) % TABLE_SIZE;
    }

    int hash2(int key){
        
        return PRIME - (key + PRIME) % PRIME;
    }

    
    int get_index_for_key(int key){
        
       // return key;
        
        int idx1 = hash1(key);
        int idx2 = hash2(key);
        
        for(int i = 0; i < TABLE_SIZE; i++){
            
            int idx = (idx1 + idx2 * i) % TABLE_SIZE;
            
            if(a[idx] != nullptr and a[idx] -> key == key)
                return idx;
            
            else if(a[idx] == nullptr)
                return idx;
        }
        
        return -1;
    }
    void put(int key, int value) {
        
        int idx = get_index_for_key(key);
        
        if(a[idx] != nullptr){
            
            a[idx] -> value = value;
            
            return;
        }
        
        if(SIZE == TABLE_SIZE)
            return;
        
        node *new_node = new node(key, value);
        
        a[idx] = new_node;
        
        SIZE++;
    }
    
   
    int get(int key) {
        
        int idx = get_index_for_key(key);
        
        if(a[idx] == nullptr)
            return -1;
        
        return a[idx] -> value;
    }
    
   
    void remove(int key) {
        
        int idx = get_index_for_key(key);
        
        if(a[idx] == nullptr)
            return;
        
        delete a[idx];
        a[idx] = NULL;
        
        SIZE--;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */