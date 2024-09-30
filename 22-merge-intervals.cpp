https://leetcode.com/problems/merge-intervals/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) 
        {
            return intervals;
        }
        
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int i = 0, j = 1;

        while (j < n) 
        {
            if (intervals[i][1] < intervals[j][0]) 
            {
                ans.push_back(intervals[i]);
                i = j;  
                j++;   
            } 
            else if (intervals[i][1] >= intervals[j][0]) 
            {
                intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                j++;
            }
        }

        // Add the last interval (which might be merged) to the result
        ans.push_back(intervals[i]);

        return ans;
    }
};
