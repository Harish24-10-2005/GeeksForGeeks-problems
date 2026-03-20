/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    unordered_map<Node*,Node*>par;
    Node* tar = nullptr;
    void find(Node* root,int t){
        if(!root) return;
        if(root->data == t) tar = root;
        
        if(root->left)par[root->left] = root;
        if(root->right) par[root->right] = root;
        find(root->left,t);
        find(root->right,t);
    }
  public:
    int minTime(Node* root, int target) {
        // code here
        queue<Node*>q;
        find(root,target);
        unordered_set<Node*>vis;
        int ans = 0;
        q.push(tar);
        vis.insert(tar);
        while(!q.empty()){
            int si = q.size();
            bool f = false;
            for(int i=0;i<si;i++){
                Node* node = q.front();
                q.pop();
                if(par.count(node) && vis.find(par[node]) == vis.end()){
                    vis.insert(par[node]);
                    f = true;
                    q.push(par[node]);
                }
                if(node->left && vis.find(node->left) == vis.end()){
                    vis.insert(node->left);
                    f = true;
                    q.push(node->left);   
                }
                if(node->right && vis.find(node->right) == vis.end()){
                    vis.insert(node->right);
                    f = true;
                    q.push(node->right);  
                } 
            }
            if(f) ans++;
        }
        return ans;
        
    }
};