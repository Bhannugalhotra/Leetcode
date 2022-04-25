
class Node{
    
    public:
    
    int data;
    Node *next;
    Node *down;
    Node *up;
    
    Node(int d = 0) : data(d), next(NULL), down(NULL), up(NULL) {};
};
class LinkedList{
    
    public:
    
    const int MAX_LEVEL = 4;
    
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
            
            itr1 -> down -> up = itr1;
            itr2 -> down -> up = itr2;
            
            itr1 = itr1 -> down;
            itr2 = itr2 -> down;
            
            itr1 -> next = itr2;
        }
    }
    
    
    void insertInList(Node *itr, stack<Node*> &onPath, int val){
        
        // if(val == 9){
        //     cout << "in insert IN lIst" << endl;
        //     cout << endl;
        // }
        
        
        
        while(itr -> next -> data < val){
            itr = itr -> next;
        }
        
        // if(val == 9){
        //     cout << val << endl;
        // }
        
        // if(itr -> next -> data == val)
        //     return;
        
        
        Node *temp = new Node(val);
        
        // if(val == 9){
        //     cout << temp ->data << endl;
        // }
        temp -> next = itr -> next;
        itr -> next = temp;
        
        int level = 1;
        
        while(level < MAX_LEVEL){
            
            int randomNo = rand();
            
            if(randomNo % 2 == 0)
                break;
            
            Node *curr = new Node(val);
            
            curr -> down = temp;
            temp -> up = curr;
            
            temp = curr;
            
            Node *prev = onPath.top();  onPath.pop();
            
            curr -> next = prev -> next;
            prev -> next = curr;
            
            level++;
            
           // cout << "level UP  " << level <<endl;
        }
        
        // if(val == 9)
        // cout << "end" << endl;
    }
    void insert(int val){
        
        stack<Node*> onPath;
        
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
                onPath.push(itr);
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
                
                if(temp -> down)
                temp -> down -> up = nullptr;
                
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
        
        if(target == 9){
            
            //List.PrintList();
            cout << " IN search " << endl;
        }
       // List.PrintList();
        return List.Search(target);
    }
    
    void add(int num) {
        
        if(num == 0)
            cout << "add " << endl;
        List.insert(num);
    }
    
    bool erase(int num) {
        
        if(num == 9)
            cout << "erase" << endl;
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