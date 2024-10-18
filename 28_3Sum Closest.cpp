// https://leetcode.com/problems/3sum-closest/description/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size() ;

        int close_sum = 100000 ;

        sort(nums.begin() , nums.end()) ;

        for(int i = 0 ; i <= n-3 ; ++i)
        {
            int j = i+1 ;
            int k = n-1 ;

            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k] ;

                if(abs(target-sum) < abs(target - close_sum))
                {
                    close_sum = sum ;
                }
                else if(sum > target)
                {
                    k-- ;
                }
                else
                {
                    j++ ;
                }
            }
        }
        return close_sum ;
    }
};
