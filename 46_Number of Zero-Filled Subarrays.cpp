

#define ll long long

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll n = nums.size() ;

        ll count = 0 , res = 0 ;

        for(ll i = 0 ; i < n ; ++i)
        {
            if(nums[i] == 0)
            {
                res++ ;
            }
            else
            {
                res = 0 ;
            }
            count += res ;
        }
        return count ;
    }
};
