// https://leetcode.com/problems/minimum-time-difference/

class Solution {
public:
    int findMinDifference(vector<string>& a) {
        int n = a.size();

        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            int hr = stoi(a[i].substr(0, 2)) * 60; //  hours to minutes
            int min = stoi(a[i].substr(3, 2));      // minutes
            ans[i] = hr + min;                      // Total time 
        }

        sort(ans.begin(), ans.end());

        int mn = INT_MAX;

        // minimum difference between adjacent times
        for (int i = 0; i < n - 1; ++i) 
        {
            mn = min(mn, abs(ans[i+1] - ans[i]));
        }

        // Also check the difference between the first and last time points across midnight
        int across_midnight_diff = 1440 - ans[n-1] + ans[0];
        mn = min(mn, across_midnight_diff);

        return mn;
    }
};
