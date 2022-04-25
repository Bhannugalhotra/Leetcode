
class Node{
    
    public:
    
    int data;
    Node *next;
    Node *down;
    
    Node(int d = 0) : data(d), next(NULL), down(NULL) {};
};
class LinkedList{
    
    public:
    
    const int MAX_LEVEL = 6;
    
    Node *head;
    Node *tail;
    
    LinkedList(){
        
        head = new Node(INT_MIN);
        tail = new Node(INT_MAX);
        
        Node *itr1 = head;
        Node *itr2 = tail;
        
        head -> next = tail;
        
        for(int i = 1; i < MAX_LEVEL;i++){
            itr1 -> down = new Node(INT_MIN);
            itr2 -> down = new Node(INT_MAX);
            
            itr1 = itr1 -> down;
            itr2 = itr2 -> down;
            
            itr1 -> next = itr2;
        }
    }
    
    
    void insertInList(Node *itr, vector<Node*> &onPath, int val){
          
        while(itr -> next -> data < val){
            itr = itr -> next;
        }
        
        Node *temp = new Node(val);
        
        temp -> next = itr -> next;
        itr -> next = temp;
        
        int level = 1;
        
        while(level < MAX_LEVEL){
            
            int randomNo = rand();
            
            if(randomNo % 2 == 0)
                break;
            
            Node *curr = new Node(val);
            
            curr -> down = temp;
            
            temp = curr;
            
            Node *prev = onPath.back();  onPath.pop_back();
            
            curr -> next = prev -> next;
            prev -> next = curr;
            
            level++;
            
        }
     
    }
    void insert(int val){
        
        vector<Node*> onPath;
        
        Node *itr = head;
        
        while(true){
            
            if(itr -> next -> data < val){
                itr = itr -> next;
            }
            
            else if(itr -> down == nullptr){
                insertInList(itr, onPath,val);
                return;
            }
            
            else{
                onPath.push_back(itr);
                itr = itr -> down;
            }
            
        }
    }
    
    
    bool Search(int val){
    
        Node *itr = head;
     
        while(itr){
            
            if(itr -> next -> data < val)
                itr = itr -> next;
            
            else if(itr -> next -> data == val)
                return true;
            
            else
                itr = itr -> down;
        }
        
      
        return false;
    }
    
   
    void PrintList(){
        
        cout << "List : "<<endl;
        Node *itr = head;
        
        for(int i = 1 ; i <= MAX_LEVEL; i++){
            
            cout << "level no " << i << endl;
            Node *temp = itr;
            
            while(temp){
                cout << temp -> data <<" ";
                temp = temp -> next;
            }
            
            itr = itr -> down;
            cout<<endl;
        }
    }
    
    bool Erase(int val){
        
        Node *itr = head;
        
        while(itr){
            
            if(itr -> next -> data == val){
                Node *temp = itr -> next;
                itr -> next = temp -> next;
                
                delete(temp);
                
                itr = itr -> down;
            }
            
            else if(itr -> next -> data < val)
                itr = itr -> next;
            
            else
                itr = itr -> down;
        }
        
        return true;
    }
};

class Skiplist 
{
    LinkedList List;
public:
    Skiplist() {
        
    }
    
    bool search(int target) {
        
        return List.Search(target);
    }
    
    void add(int num) {
        
        List.insert(num);
    }
    
    bool erase(int num) {
        
        bool res = List.Search(num);
        
        if(res == false)
            return false;
        
        return List.Erase(num);
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */