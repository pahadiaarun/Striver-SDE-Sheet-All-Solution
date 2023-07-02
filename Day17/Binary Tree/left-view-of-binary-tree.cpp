// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

vector<int> leftView(Node *root)
{
   // Your code here
   if(!root) return {};
   vector<int>res;
   queue<Node*>q;
   q.push(root);
   q.push(NULL);
   res.push_back(q.front()->data);
   while(!q.empty()){
       Node* p=q.front();
       q.pop();
       if(p==NULL){
           if(q.size() && q.front()!=NULL){
               res.push_back(q.front()->data);
           }
           else break;
           q.push(NULL);
           continue;
       }
       if(p->left) q.push(p->left);
       if(p->right) q.push(p->right);
   }
   return res;
}

