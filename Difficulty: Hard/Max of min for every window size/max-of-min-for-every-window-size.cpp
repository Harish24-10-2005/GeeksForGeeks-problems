
class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        // int minn = *min_element(arr.begin(),arr.end());
        vector<int>ans(n,-1);
        vector<int>p(n,-1);
        vector<int>s(n,n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(!st.empty()) p[i] = st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(!st.empty()) s[i] = st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++)
        {
            int t = s[i] - p[i] -1;
            ans[t-1] = max(arr[i],ans[t-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            ans[i] = max(ans[i], ans[i+1]);;
        }
        return ans;
        
    }
};