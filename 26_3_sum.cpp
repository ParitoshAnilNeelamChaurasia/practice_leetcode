// https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ;

        sort(nums.begin() , nums.end()) ;

        if(n < 3)
        return {} ;

        vector<vector<int>> ans ;

        for(int i = 0 ; i < n ; ++i)
        {
            if(i > 0 && nums[i] == nums[i-1])
            continue ;

            int tar = -nums[i] ;

            int j = i+1 ;
            int k = n-1 ;

            while(j < k)
            {
                int sum = nums[j] + nums[k] ;

                if(sum == tar)
                {
                    ans.push_back({nums[i] , nums[j] , nums[k]}) ;

                    while(j < k && nums[j] == nums[j+1])
                    {
                        j++ ;
                    }

                    while(j < k && nums[k] == nums[k-1])
                    {
                        k-- ;
                    }
                    j++ ;
                    k-- ;
                }
                else if(sum > tar)
                {
                    k-- ;
                }
                else
                {
                    j++ ;
                }
            }
        }   
        return ans ;
    }
};
