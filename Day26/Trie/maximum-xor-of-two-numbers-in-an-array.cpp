// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

struct Node{
    Node* arr[2];
    bool present(int i){
        return arr[i]!=NULL;
    }
    void put(int i,Node* p){
        arr[i]=p;
    }
    Node* get(int i){
        return arr[i];
    }
};

class Trie{
    public:
        Node *root;
        Trie(){
            root=new Node();
        }
        void insert(int A){
            Node* temp=root;
            for(int i=31;i>=0;i--){
                int x=(A>>i)&1;
                if(!temp->present(x)){
                    temp->put(x,new Node());
                }
                temp=temp->get(x);
            }
        }
        int getMax(int A){
            Node* temp=root;
            int mx=0;
            for(int i=31;i>=0;i--){
                int x=(A>>i)&1;
                if(temp->present(1-x)){
                    mx=mx|(1<<i);
                    temp=temp->get(1-x);
                }
                else{
                    temp=temp->get(x);
                }
                
            }
            return mx;
        }
};

int maximumXor(vector<int> A)
{
    // Write your code here.   
    Trie trie;
    for(auto it:A){
        trie.insert(it);
    }
    int mx=INT_MIN;
    for(auto it:A){
        mx=max(mx,trie.getMax(it));
    }
    return mx;
}

