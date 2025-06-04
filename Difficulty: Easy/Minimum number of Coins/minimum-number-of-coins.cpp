// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        vector<int>res;
        vector<int>c{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        int i = c.size()-1;
        while(N!=0)
        {
            if(c[i] <= N)
            {
                int can = N/c[i];
                res.insert(res.end(), can, c[i]);
                N -= (can*c[i]);
            }
            i--;
        }
        return res;
    }
};