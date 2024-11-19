//https://www.geeksforgeeks.org/problems/geeks-training/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int dp[100001] ;
    int f(int ind, int last, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if (ind >= arr.size()) 
        {
            return 0; 
        }

        if (dp[ind][last] != -1) 
        {
            return dp[ind][last]; 
        }

        int maxPoints = 0;
        // Iterate over all tasks (0, 1, 2)
        for (int task = 0; task < 3; ++task) 
        {
            if (task != last) 
            { // for no consecutive tasks
                maxPoints = max(maxPoints, arr[ind][task] + f(ind + 1, task, arr, dp));
            }
        }

        return dp[ind][last] = maxPoints; 
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        
        vector<vector<int>> dp(n, vector<int>(4, -1)); 
        return f(0, 3, arr, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
