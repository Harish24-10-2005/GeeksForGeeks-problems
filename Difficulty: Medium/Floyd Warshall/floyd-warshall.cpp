//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        for(int i=0;i<dist.size();i++)
        {
            for(int j=0;j<dist.size();j++)
            {
                if(dist[i][j] == 1e8) dist[i][j] = INT_MAX;
                if(i == j) dist[i][j] = 0;
            }
            
        }
        for(int via=0;via<dist.size();via++)
        {
            for(int i=0;i<dist.size();i++)
            {
                for(int j=0;j<dist.size();j++)
                {
                    if (dist[i][via] != INT_MAX && dist[via][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);

                }
                
            }
        }
        for(int i=0;i<dist.size();i++)
        {
            for(int j=0;j<dist.size();j++)
            {
                if(dist[i][j] == INT_MAX) dist[i][j] = 1e8;
            }
            
        }
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.floydWarshall(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends