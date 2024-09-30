// https://leetcode.com/problems/sort-colors/description/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size() ;

        int zero = 0 , one = 0 , two = 0 ;

        for(int it : nums)
        {
            if(it == 0)zero++ ;
            if(it == 1)one++ ;
            if(it == 2)two++ ;
        }

        int i = 0 ;

        while(zero--)
        nums[i] = 0 ,i++ ;

        while(one--)
        nums[i] = 1 ,i++ ;

        while(two--)
        nums[i] = 2 ,i++ ;
    }
};
