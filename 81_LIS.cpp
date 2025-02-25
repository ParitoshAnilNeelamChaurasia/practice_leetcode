

class Solution {
public:
    int n ;

    int dp[2501][2501] ;
    int f(int curr_idx , vector<int> &nums , int prev_idx)
    {
        if(curr_idx >= n)
        {
            return 0 ;
        }

        if(dp[curr_idx][prev_idx+1] != -1)   //  prev_idx -> prev_idx+1
        {
            return dp[curr_idx][prev_idx+1] ;
        }
        int not_take = f(curr_idx + 1 , nums , prev_idx) ;

        int take ;

        if(prev_idx == -1 || nums[curr_idx] > nums[prev_idx])
        {
            take = 1 + f(curr_idx + 1 , nums , curr_idx) ;
        }

        return dp[curr_idx][prev_idx+1] = max(take , not_take) ;
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size() ;   
        memset(dp,-1,sizeof(dp)) ;

        return f( 0 , nums , -1) ;  // (curr_idx , nums , prev_ele)
    }
};
