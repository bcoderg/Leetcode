class LRUCache {
public:
    class node{
        public:
        int key,val;
        node* next;
        node* prev;

        node(int key,int val){
            this->key=key;
            this->val=val;
        }
    };

    //initialise head,tail
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int capacity;
    unordered_map<int , node*>m;

    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addnode(node* newnode){
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void removenode(node* delnode){
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            node* resnode=m[key];
            int result=resnode->val;
            m.erase(key);
            removenode(resnode);
            addnode(resnode);
            m[key]=head->next;
            return result;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node* existingnode=m[key];
            m.erase(key);
            removenode(existingnode);
        }
        if(m.size()==capacity){
            int lastKey=tail->prev->key;
            m.erase(lastKey);
            removenode(tail->prev);
        }
        addnode(new node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */