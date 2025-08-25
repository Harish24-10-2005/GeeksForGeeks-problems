class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int t = 0;
        int d = n-1;
        while(t < d)
        {
            if(mat[t][d] == 1)
            {
                t++;
            }
            else if(mat[d][t] == 1)
            {
                d--;
            }
            else
            {
                t++;
                d--;
            }
        }
        if(t == d)
        {
            // cout<<"Hi"<<endl;
            bool f = true;
            for(int i=0;i<n;i++)
            {
                if(i == t) continue;
                if(mat[t][i]== 1|| mat[i][t] == 0)
                {
                    f = false;
                    break;
                }
            }
            if(f) return t;
        }
        return -1;
    }
};