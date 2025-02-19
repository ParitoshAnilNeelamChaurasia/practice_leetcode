// https://leetcode.com/problems/maximum-sum-circular-subarray/description/

class Solution {
public:
    int n ;

    int kadane_max(vector<int> &nums)
    {
        int curr_sum = nums[0] ;
        int max_sum = nums[0] ;

        for(int i = 1 ; i < n ; ++i)
        {
            curr_sum = max(curr_sum + nums[i] , nums[i]) ;
            max_sum = max(curr_sum , max_sum) ;
        }

        return max_sum ;
    }

    int kadane_min(vector<int> &nums)
    {
        int curr_sum = nums[0] ;
        int min_sum = nums[0] ;

        for(int i = 1 ; i < n ; ++i)
        {
            curr_sum = min(curr_sum + nums[i] , nums[i]);
            min_sum = min(curr_sum , min_sum) ;
        }

        return min_sum ;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        n = nums.size() ;

        int tot_sum = accumulate(nums.begin() , nums.end() , 0) ;

        int min_sum = kadane_min(nums) ;

        int max_sum = kadane_max(nums) ;

        int cir_sum = tot_sum - min_sum ;

        if(max_sum > 0)
        {
            return max(max_sum , cir_sum) ;
        }
        return max_sum ;
    }
};
