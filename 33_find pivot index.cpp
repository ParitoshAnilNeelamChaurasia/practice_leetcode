// https://leetcode.com/problems/find-pivot-index/description/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size() ;

        vector<int> pref(n) ;

        pref[0] = nums[0] ;

        for(int i = 1 ; i < n ; ++i)
        {
            pref[i] = pref[i-1] + nums[i] ;
        }

        vector<int> suf(n) ;
        suf[n-1] = nums[n-1] ;

        for(int i = n-2 ; i >= 0 ; --i)
        {
            suf[i] = suf[i+1] + nums[i] ;
        }


        for(int i = 0 ; i < n ; ++i)
        {
            if(suf[i] == pref[i])
            {
                return i ;
            }
        }
        return -1 ;
    }
};
