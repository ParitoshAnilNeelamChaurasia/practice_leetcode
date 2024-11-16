// https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

class Solution {
public:
    int n;

    int dp[50001] ;

    int find_next_ind(vector<vector<int>> &ans, int st, int endTime) {
        int low = st, high = n - 1, res = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (ans[mid][0] >= endTime) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }

    int f(int ind, vector<vector<int>> &ans) {
        // Base case
        if (ind >= n) {
            return 0;
        }

        if(dp[ind] != -1)
        {
            return dp[ind] ;
        }

        // Find the next job index whose start time is >= the current job's end time
        int next_ind = find_next_ind(ans, ind + 1, ans[ind][1]);

        // Option 1: Take the current job
        int take = ans[ind][2] + f(next_ind, ans);

        // Option 2: Skip the current job
        int not_take = f(ind + 1, ans);

        return dp[ind] = max(take, not_take);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        vector<vector<int>> ans(n, vector<int>(3));

        memset(dp,-1,sizeof(dp)) ;

        // Populate the `ans` vector
        for (int i = 0; i < n; ++i) {
            ans[i] = {startTime[i], endTime[i], profit[i]};
        }

        // Sort by start time
        sort(ans.begin(), ans.end());

        // Start the recursion
        return f(0, ans);
    }
};
