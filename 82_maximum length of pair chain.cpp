// https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
public:
    int n ;
    
    int dp[1001][1001] ;
    int f(int curr_idx , vector<vector<int>> &pairs , int prev_idx)
    {
        if(curr_idx >= n)
        {
            return 0 ;
        }

        if(dp[curr_idx][prev_idx+1] != -1)
        {
            return dp[curr_idx][prev_idx+1] ;
        }

        int not_take = f(curr_idx + 1 , pairs , prev_idx) ;

        int take ;

        if(prev_idx == -1 || pairs[curr_idx][0] > pairs[prev_idx][1])
        {
            take = 1 + f(curr_idx + 1 , pairs , curr_idx) ;
        } 

        return dp[curr_idx][prev_idx+1] = max(take , not_take) ;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size() ;

        memset(dp,-1,sizeof(dp)) ;

        sort(pairs.begin() , pairs.end()) ;
        return f(0 , pairs , -1) ;
    }
};
