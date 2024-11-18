// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

class Solution {
public:
    int n ;

    int dp[5001][2] ;
    int f(int ind , vector<int> &prices , bool flag)
    {
        if(ind >= n)
        {
            return 0 ;
        }

        if(dp[ind][flag] != -1)
        {
            return dp[ind][flag] ;
        }

        int profit = 0 ;

        if(flag == true)
        {
            int take = f(ind+1 , prices , false) - prices[ind] ;

            int not_take = f(ind+1 , prices , true) ;

            profit = max({profit , take , not_take}) ;
        }

        else
        {
            int sell = f(ind+2 , prices , true) + prices[ind] ;

            int not_sell = f(ind+1 , prices , false) ;

            profit = max({profit , sell , not_sell});
        }
        return dp[ind][flag] = profit ;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size() ;
        bool flag = true ;
        memset(dp,-1,sizeof(dp)) ;
        return f(0 , prices , flag);
    }
};
