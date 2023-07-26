// https://leetcode.com/problems/implement-trie-prefix-tree/

struct Node{
    Node* arr[26];
    bool flag=false;
    bool fun(char c){
        return (arr[c-'a']!=NULL);
    }
    void put(char c,Node* p){
        arr[c-'a']=p;
    }
    Node* get(char c){
        return arr[c-'a'];
    }
    void set(){
        flag=true;
    }
    bool end(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(auto i:word){
            if(!temp->fun(i)){
                temp->put(i,new Node());
            }
            temp = temp->get(i);
        }
        temp->set();
    }
    
    bool search(string word) {
        Node* temp=root;
        for(auto i:word){
            if(!temp->fun(i)){
                return false;
            }
            temp = temp->get(i);
        }
        return temp->end();
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(auto i:prefix){
            if(!temp->fun(i)){
                return false;
            }
            temp = temp->get(i);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

