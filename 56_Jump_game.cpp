

class Solution {
public:
    int n ;

    int dp[100001] ;

    bool f(int ind , vector<int> &nums)
    {
        if(ind >= n)
        {
            return false ;
        }

        if(dp[ind] != -1)
        {
            return dp[ind]  ;
        }

        if(ind == n-1)
        {
            return true ;
        }

        for(int i = 1 ; i <= nums[ind] ; ++i)
        {
            if(f(ind+i , nums) == true)
            {
                return dp[ind] = true ;
            }
        }

        return dp[ind] = false ;
    }
    bool canJump(vector<int>& nums) {
        n = nums.size() ;

        memset(dp,-1,sizeof(dp)) ;
        return f(0 , nums) ;
    }
};
