class LRUCache {
public:
    class node
    {
        public:
            int value;
            node* prev;
            node* next;
            int key;
            node(int k,int val)
            {
                value=val;
                key=k;
            }
    };
    map<int,node*> mp;
    node* head= new node(-1,-1);
    node* tail= new node(-1,-1);
    
    int capacity_list=0;
    int sz=0;
    LRUCache(int capacity) 
    {
        capacity_list=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) 
    {
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        node* itr=mp[key];
        // delete the node
        (itr->prev)->next=itr->next;
        (itr->next)->prev=itr->prev;
        // insert the node
        itr->prev=tail->prev;
        itr->next=tail;
        (itr->prev)->next=itr;
        (itr->next)->prev=itr;
        return itr->value;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)!=mp.end())
        {
            node* itr=mp[key];
            // delete the node
            (itr->prev)->next=itr->next;
            (itr->next)->prev=itr->prev;
            // insert the node
            itr->prev=tail->prev;
            itr->next=tail;
            (itr->prev)->next=itr;
            (itr->next)->prev=itr;
            itr->value=value;
        }
        
        else
        {
            sz++;
            node* itr= new node(key,value);
             // insert the node
            itr->prev=tail->prev;
            itr->next=tail;
            (itr->prev)->next=itr;
            (itr->next)->prev=itr;
            mp[key]=itr;
            if(sz>capacity_list)
            {
                mp.erase((head->next)->key);
                head->next=(head->next)->next;
                (head->next)->prev=head;
            }
        }
    }
    
    
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */