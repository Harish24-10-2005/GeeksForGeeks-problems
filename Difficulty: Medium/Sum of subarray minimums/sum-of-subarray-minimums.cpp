class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>pre(n,-1),suf(n,n);\
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()) pre[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()) suf[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+= arr[i]*(i - pre[i])*(suf[i] - i);
        }
        return ans;
    }
};