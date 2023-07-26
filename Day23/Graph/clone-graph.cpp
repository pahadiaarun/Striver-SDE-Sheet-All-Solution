// https://leetcode.com/problems/clone-graph/

class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        if(mp.find(node)==mp.end()){
            mp[node] = new Node(node -> val, {});
            for(auto i:node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(i));
            }
        }
        return mp[node];
    }
};
