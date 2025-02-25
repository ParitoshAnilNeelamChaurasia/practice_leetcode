

class Solution {
public:
    int n ;

    int dp[101] ;

    int f(int idx , vector<int> &nums , int last)
    {
        if(idx >= last)
        {
            return 0 ;
        }

        if(dp[idx] != -1)
        {
            return dp[idx] ;
        }

        int take =  nums[idx] + f(idx+2 , nums , last)  ;

        int not_take = f(idx+1 , nums , last) ;

        return dp[idx] = max(take , not_take) ;
    }
    int rob(vector<int>& nums) {
        n = nums.size() ;

        if(n == 1)
        {
            return nums[0] ;
        }

        else if(n == 2)
        {
            return max(nums[0] , nums[1]) ;
        }

        memset(dp,-1,sizeof(dp)) ;

        int m1 = f(0 , nums , n-1) ;

        memset(dp,-1,sizeof(dp)) ;

        int m2 = f(1 , nums , n) ;

        return max(m1 , m2) ;


    }
};
