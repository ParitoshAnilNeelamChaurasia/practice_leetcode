// https://leetcode.com/problems/minimum-average-difference/description/

#define ll long long

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size() ;

        vector<ll> pref(n) , suff(n) ;

        pref[0] = nums[0] ;

        for(int i = 1 ; i < n ; ++i)
        {
            pref[i] = pref[i-1] + nums[i] ;
        }

        suff[n-1] = nums[n-1] ;
        for(int i = n-2 ; i >= 0 ; --i)
        {
            suff[i] = suff[i+1] + nums[i] ;
        }   

        int mn = INT_MAX ;
        int ind = -1 ;

        for(int i = 0 ; i < n ; ++i)
        {
            int left_avg = pref[i] / (i+1) ;

            int right_avg ;
            
            if(i == n-1)
            {
                right_avg = 0 ;
            }
            else
            {
                right_avg = suff[i+1] / (n-i-1) ;
            }

            int avg_diff = abs(right_avg - left_avg) ;

            if(avg_diff < mn)
            {
                mn = avg_diff ;
                ind = i ;
            }
        }
        return ind ;
    }
};
