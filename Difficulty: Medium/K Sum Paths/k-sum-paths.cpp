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
    int ans = 0;
    void dfs(Node* root,int summ,int k,unordered_map<int,int>&mpp){
        if(!root) return;
        summ+=root->data;
        
        if(summ == k) ans++;
        
        if(mpp.find(summ - k) != mpp.end()){
            ans+=mpp[summ - k];
        }
        
        mpp[summ]++;
        dfs(root->left,summ,k,mpp);
        dfs(root->right,summ,k,mpp);
        mpp[summ]--;
    }
  public:
    int countAllPaths(Node *root, int k) {
        // code here
        unordered_map<int,int>mpp;
        dfs(root,0,k,mpp);
        return ans;
    }
};