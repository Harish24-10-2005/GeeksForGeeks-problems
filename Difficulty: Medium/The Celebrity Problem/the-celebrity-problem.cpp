class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++)
        {
            bool f = true;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 1 && (i==j)) continue;
                if(mat[i][j] == 1)
                {
                    f = false;
                    break;
                }
            }
            if(f)
            {
                for(int k=0;k<n;k++)
                {
                    if(mat[k][i] != 1)
                    {
                        f= false;
                        break;
                    }
                }
                if(f) return i;
            }
        }
        return -1;
    }
};