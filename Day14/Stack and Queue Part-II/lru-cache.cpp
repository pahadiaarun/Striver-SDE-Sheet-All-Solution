// https://leetcode.com/problems/lru-cache/

class LRUCache {
public:
    struct node{
        int k;
        int val;
        node* next;
        node* prev;
        node(int x,int y){
            k=x;
            val=y;
        }
    };
    int n;
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    unordered_map<int,node*>mp;
    
    LRUCache(int capacity) {
        n=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void add(node* t){
        node* t2=head->next;
        head->next=t;
        t->next=t2;
        t->prev=head;
        t2->prev=t;
    }
    
    void del(node* t){
        node* t1=t->prev;
        node* t2=t->next;
        t1->next=t2;
        t2->prev=t1;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node* t=mp[key];
            int res=t->val;
            mp.erase(key);
            del(t);
            add(t);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* t=mp[key];
            mp.erase(key);
            del(t);
        }
        if(mp.size()==n){
            mp.erase(tail->prev->k);
            del(tail->prev);
        }
        add(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

