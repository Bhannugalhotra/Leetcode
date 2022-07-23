class node
{
    public:
    int data;
    int left_subtree_size;
    node *left,*right;
   
    node(int key) : data(key),left_subtree_size(0),left(NULL),right(NULL) {};
};

class Solution
{
    int n;
    vector<int> ans;
    vector<int> aux;
    vector<int> idx;
public:
    vector<int> countSmaller(vector<int>& a) 
    {
        n = a.size();
        ans = vector<int>(n);
        
//         node *root = NULL;
        
//         for(int i = n-1; i >= 0; i--)
//             root = insert(root,a[i],i,0);
        
        // solution 2 using merge_sort
        aux = vector<int>(n);
        idx = vector<int>(n);
        iota(begin(idx),end(idx),0);
        
        merge_sort(a,0,n-1);
        
        return ans;
    }
    
    node* insert(node *root,int data,int idx,int count)
    {
        if(!root)
        {
            root = new node(data);
            ans[idx] = count;
        }
        
        else if(root -> data >= data)
        {
            root -> left_subtree_size++;
            root -> left = insert(root -> left,data,idx,count);
        }
        
        else // (root -> data < data)
        {
            root -> right = insert(root -> right,data,idx,count+root -> left_subtree_size+1);
        }
        
        return root;
        
    }
    void merge(vector<int> &a,int l,int mid,int r)
    {
        int i = l;
        int j = mid+1;
        int jump = 0;
        
        for(int k = l; k <= r; k++)
        {
            if(i > mid)
                aux[k] = idx[j++];
            
            else if(j > r)
                ans[idx[i]] += jump,aux[k] = idx[i++];
            
            else if(a[idx[j]] < a[idx[i]])
                jump++, aux[k] = idx[j++];
            
            else
                ans[idx[i]] += jump, aux[k] = idx[i++];
        }
        
        for(int k = l; k <= r; k++)
            idx[k] = aux[k];
    }
    void merge_sort(vector<int> &a,int l,int r)
    {
        if(l >= r)
            return;
        
        int mid = l + ((r-l) >> 1);
        
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,r);
        
        merge(a,l,mid,r);
    }
};