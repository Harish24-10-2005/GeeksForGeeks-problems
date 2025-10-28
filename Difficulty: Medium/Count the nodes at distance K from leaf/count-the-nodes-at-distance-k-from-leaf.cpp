/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    set<Node*>vis;
    int ans = 0;
  private:
    bool isleaf(Node* root)
    {
        return !root->left && !root->right;
    }
    void rec(Node* root,int k,int p,unordered_map<int,Node*>&path)
    {
        if(!root) return;
        
        path[p] = root;
        p++;
        
        if(isleaf(root) && (p - k - 1) >=0 && vis.find(path[p-k-1]) == vis.end())
        {
            vis.insert(path[p-k-1]);
            ans++;
            return;
        }
        
        rec(root->left,k,p,path);
        rec(root->right,k,p,path);
    }
  public:
    int kthFromLeaf(Node* root, int k) {
        // code here.
        unordered_map<int,Node*>path;
        rec(root,k,0,path);
        return ans;
        
    }
};