

class Solution {
public:
    int dp[301][1001] ;
    int f(int ind , int d , vector<int> &job , int n)
    {
        if(dp[ind][d] != -1)
        {
            return dp[ind][d] ;
        }
        // only one day left -> then u have to do all the remaining jobs
        if(d == 1)
        {
            int mx_diff = job[ind] ;

            for(int i = ind ; i < n ; ++i)
            {
                mx_diff = max(mx_diff , job[i]) ;
            }
            return mx_diff ;
        }

        int max_diff = job[ind] ;
        int final_res = INT_MAX ;

        for(int i = ind ; i <= n-d ; ++i)
        {
            max_diff = max(max_diff , job[i]) ;

            int res = max_diff + f(i+1 , d-1 , job , n) ;

            final_res = min(final_res , res) ;
        }
        return dp[ind][d] = final_res ;
    }
    int minDifficulty(vector<int>& job, int d) {
        int n = job.size() ;

        memset(dp,-1,sizeof(dp)) ;

        if(n < d)
        {
            return -1 ;
        }

        else if(n == d)
        {
            return accumulate(job.begin() , job.end() , 0) ;
        }

        else
        {
            // f(ind , days , job vector , size)
            return f(0 , d , job , n) ;
        }
    }
};
