
class Solution {
  public:
    bool isBalanced(string& k) {
        // code here
        stack<int>st;
        for(auto a:k)
        {
            if(!st.empty() && a == ')' && st.top() == '(')
            {
                st.pop();
            }
            else if(!st.empty() && a == '}' && st.top() == '{')
            {
                st.pop();
            }
            else if(!st.empty() && a == ']' && st.top() == '[')
            {
                st.pop();
            }
            else st.push(a);
        }
        if(st.empty()) return true;
        else return false;
    }
};