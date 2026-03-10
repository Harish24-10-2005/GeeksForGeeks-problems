class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.size();
        vector<int>digit(10,-1);
        for(int i = 0;i<n;i++)digit[s[i] - '0'] = i;
        
        for(int i=0;i<n;i++){
            int num = (s[i]-'0');
            for(int d = 9;d>num;d--){
                if(digit[d] > i){
                    swap(s[i],s[digit[d]]);
                    return s;
                }
            }
        }
        return s;
    }
};

// 5 4 3 1 2 1 
// 3 0 3 3
// i     j

