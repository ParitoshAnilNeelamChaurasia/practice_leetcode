// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size() ;

        vector<int> ans(256,-1) ;

        int mx = 0 ;
        int st = -1 ;

        for(int i = 0 ; i < n ; ++i)
        {
            if(ans[s[i]] > st)
            {
                st = ans[s[i]] ;
            }
            ans[s[i]] = i ;
            mx = max(mx , i - st) ;
        }
        return mx ;
    }
};
