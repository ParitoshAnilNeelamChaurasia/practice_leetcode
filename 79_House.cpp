

class Solution {
public:
    int n ;

    int dp[101] ;

    int f(int idx , vector<int> &nums)
    {
        if(idx >= n)
        {
            return 0 ;
        }

        if(dp[idx] != -1)
        {
            return dp[idx] ;
        }
       
        int take = nums[idx] + f(idx+2 , nums) ;

        int not_take = f(idx+1 , nums) ;

        return dp[idx] = max(take , not_take) ;
    }
    int rob(vector<int>& nums) {
        n = nums.size() ;

        memset(dp,-1 , sizeof(dp)) ;

        return f(0 , nums) ;
    }
};
