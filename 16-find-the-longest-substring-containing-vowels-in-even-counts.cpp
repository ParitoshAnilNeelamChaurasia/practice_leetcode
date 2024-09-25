// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/?envType=daily-question&envId=2024-09-15

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size() ;

        unordered_map<string,int> mp ;

        vector<int> state(5,0) ;

        string curr_state = "00000" ;

        mp[curr_state] = -1 ;

        int res = 0 ;

        for(int i = 0 ; i < n ; ++i)
        {
            if(s[i] == 'a')
            {
                state[0] = (state[0] + 1) % 2 ;
            }
            else if(s[i] == 'e')
            {
                state[1] = (state[1] + 1) % 2 ;
            }
            else if(s[i] == 'i')
            {
                state[2] = (state[2] + 1) % 2 ;
            }
            else if(s[i] == 'o')
            {
                state[3] = (state[3] + 1) % 2 ;
            }
            else if(s[i] == 'u')
            {
                state[4] = (state[4] + 1) % 2 ;
            }

            curr_state = "" ;
            for(int j = 0 ; j < 5 ; ++j)
            {
                curr_state += to_string(state[j]) ;
            }

            if(mp.find(curr_state) != mp.end())
            {
                res = max(res , i - mp[curr_state]) ;
            }
            else
            {
                mp[curr_state] = i ;
            }
        }
        return res ;
    }
};
