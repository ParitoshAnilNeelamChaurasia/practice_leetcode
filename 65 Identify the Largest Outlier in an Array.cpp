// https://leetcode.com/problems/identify-the-largest-outlier-in-an-array/description/

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size() ;

        int tot_sum = 0 ;

        unordered_map<int,int> mp ;
        for(auto it : nums)
        {
            tot_sum += it ;
            mp[it]++ ;
        }

        // tot_sum = 2*x + y 

        int ans = INT_MIN ;   // take the value less than -1000 => otherwise gaves an incorrect output
        for(auto it : nums)
        {
            int curr_outlier = it ;
            mp[curr_outlier]-- ;

            int temp = tot_sum - curr_outlier ;

            if(temp % 2 == 0)
            {
                temp = temp / 2 ;

                // Check if the half_sum exists and has a nonzero count
                if(mp.find(temp) != mp.end() && mp[temp] > 0)
                {
                    ans = max(ans , curr_outlier) ;
                }
            } 
            mp[curr_outlier]++ ;
        }
        return ans ;
    }
};
