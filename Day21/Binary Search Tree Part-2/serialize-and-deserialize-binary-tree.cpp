// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string res="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto p=q.front();
                q.pop();
                if(!p){
                    res+="#,";
                    continue;
                }
                res+=(to_string(p->val)+',');
                if(p->left) q.push(p->left);
                else q.push(NULL);
                if(p->right) q.push(p->right);
                else q.push(NULL);
            }
        }
        cout<<res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        string x="";
        vector<TreeNode*>v;
        for(auto i:data){
            if(i==','){
                TreeNode* p;
                if(x=="#") p=NULL;
                else p=new TreeNode(stoi(x));
                v.push_back(p);
                x="";
            }
            else{
                x+=i;
            }
        }
        TreeNode* root=v[0];
        queue<TreeNode*>q;
        q.push(root);
        int i=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto p=q.front();
                q.pop();
                p->left=v[i++];
                if(p->left) q.push(p->left);
                p->right=v[i++];
                if(p->right) q.push(p->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

