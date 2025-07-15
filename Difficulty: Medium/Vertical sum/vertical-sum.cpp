/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
class Solution {
  public:
    vector<int> verticalSum(Node *root) {
        // add code here.
        queue<pair<Node *,pair<int,int>>>q;
        vector<int>res;
        map<int,int>mpp;
        
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                auto a = q.front();
                q.pop();
                Node* node = a.first;
                int x = a.second.first;
                int l = a.second.second;
                if(node->left)
                {
                    q.push({node->left,{x-1,l+1}});
                }
                if(node->right)
                {
                    q.push({node->right,{x+1,l+1}});
                }
                mpp[x] += node->data;
            }
        }
        // sort(mpp.begin(),mpp.end(),[](const pair<int,int> &a,const pair<int,int> &b){
        //     return a.first>b.first;
        // });
        for(auto a:mpp)
        {
            res.push_back(a.second);
        }
        return res;
        
    }
};