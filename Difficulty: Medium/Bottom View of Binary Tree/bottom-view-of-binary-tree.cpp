/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    vector<int>res;
  public:
    vector<int> bottomView(Node *root) {
        // code here
        if(!root) return res;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        map<int,int>mpp;
        while(!q.empty())
        {
            int si = q.size();
            for(int i=0;i<si;i++)
            {
                auto a = q.front();
                q.pop();
                int v = a.second;
                Node* node = a.first;
                if(node->left)
                {
                    q.push({node->left,v-1});
                }
                if(node->right)
                {
                    q.push({node->right,v+1});
                }
                mpp[v] = node->data;
            }
        }
        for(auto a:mpp)
        {
            res.push_back(a.second);
        }
        return res;
    }
};