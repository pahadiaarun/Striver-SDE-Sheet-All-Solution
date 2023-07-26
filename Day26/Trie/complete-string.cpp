// https://www.codingninjas.com/studio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    bool flag = false;
    bool containskey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
        
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
class trie{
    private:
      Node* root;
    public:
      trie(){
          root = new Node();
      }
    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
            }
             node = node->get(word[i]);
        }
        node->setEnd(); 
     }
     bool search(string word){
         Node* node = root;
         for(int i=0; i<word.size(); i++){
             if(!node->containskey(word[i])){
                 return false;
             }
             node = node->get(word[i]);
         }
         return node->isEnd();
     }
};
 bool cmp(string s,string ans){
     int i=0 , j=0;
     while(i<s.size() && j<ans.size()){
         if(s[i]==ans[j])
             continue;
         else if(s[i]<ans[j])
               return true;
              else if(ans[j] < s[i])
                   break;
     }
     return false;
 }
string completeString(int n, vector<string> &a){
    // Write your code here.
    trie t;
    for(auto it : a){
        t.insert(it);
    }
    string ans = "";
    for(auto it : a){
        string s = it;
        string subs = "";
        bool flg = false;
        for(int i=0; i<s.size(); i++){
             subs += s[i];
            if(!t.search(subs)){
               flg = true;
                break;
            }
        }
        if(flg == false){
            if(s.size()>ans.size()){
                ans = s;
            }
            else if(s.size()==ans.size()){
                if(cmp(s,ans)){
                    ans = s;
                }
            }
        }
    }
    if(ans.size()==0) return "None";
    return ans;
}

