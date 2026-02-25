class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        vector<char>vec(27,-1);
        unordered_set<char>st;
        for(int i=0;i<s1.size();i++){
            char ch = s1[i];
            if(vec[ch- 'a'] == -1){
                if(st.count(s2[i])) return false;
                vec[ch - 'a'] = s2[i];
                st.insert(s2[i]);
            }
            else if(vec[ch- 'a'] != s2[i]) return false;
            // cout<<vec[ch-'a']<<" "<<s2[i]<<endl;
        }
        return true;
    }
};