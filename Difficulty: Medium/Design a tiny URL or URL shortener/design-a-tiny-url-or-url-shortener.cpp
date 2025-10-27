// User function template for C++
class Solution {
  public:

    // Function to generate a short url from integer ID
    string idToShortURL(long long int n) {
        // code here

        string ans = "";
        string has = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        
        while(n>0)
        {
            ans =has[n%62] + ans;
            n/=62;
        }
        return ans;
    }
};