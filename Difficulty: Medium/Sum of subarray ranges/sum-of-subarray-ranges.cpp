class Solution {
  public:
    int subarrayRanges(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>pre(n,-1),suf(n,n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()) pre[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()) suf[i] = st.top();
            st.push(i);
        }
        // for(auto a:pre){
        //     cout<<a<<" ";
        // }
        // cout<<endl;
        // for(auto a:suf){
        //     cout<<a<<" ";
        // }
        // cout<<endl;
        
        int small = 0;
        for(int i=0;i<n;i++){
            int ryt = i - pre[i];
            int lft = suf[i] - i;
            small += (arr[i] * (ryt * lft));
            pre[i] = -1;
            suf[i] = n;
        }
        // cout<<small<<endl;
        
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            if(!st.empty()) pre[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            if(!st.empty()) suf[i] = st.top();
            st.push(i);
        }
        // for(auto a:pre){
        //     cout<<a<<" ";
        // }
        // cout<<endl;
        // for(auto a:suf){
        //     cout<<a<<" ";
        // }
        // cout<<endl;
        int large = 0;
        for(int i=0;i<n;i++){
            int ryt = i - pre[i];
            int lft = suf[i] - i;
            large += (arr[i] * (ryt * lft));
        }
        // cout<<large<<endl;
        return large - small;
        
    }
};