// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto p=q.front();
                q.pop();
                if(!p) break;
                p->next=q.front();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            q.push(NULL);
            if(q.front()==NULL) break;
        }
        return root;
    }
};

