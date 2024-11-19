

class Solution {
public:
    int n;

    int dp[100001][2] ;

    int f(int curr, int prev, string &s) {
        if (curr >= n) {
            return 0; // Base case: no flips needed beyond the string
        }

        if(dp[curr][prev] != -1)
        {
            return dp[curr][prev] ;
        }

        int flip = INT_MAX; // Case when we flip the current character
        int not_flip = INT_MAX; // Case when we do not flip the current character

        if (s[curr] == '0') {
            if (prev == 1) {
                // Must flip '0' to '1' since it must remain monotonic
                flip = 1 + f(curr + 1, 1, s);
            } else {
                // Can either keep '0' or flip it to '1'
                not_flip = f(curr + 1, 0, s);
                flip = 1 + f(curr + 1, 1, s);
            }
        } else if (s[curr] == '1') {
            if (prev == 0) {
                // Can either keep '1' or flip it to '0'
                flip = 1 + f(curr + 1, 0, s);
                not_flip = f(curr + 1, 1, s);
            } else {
                // Keep '1' as it is already monotonic
                not_flip = f(curr + 1, 1, s);
            }
        }

        return dp[curr][prev] =  min(flip, not_flip); // Return the minimum of the two cases
    }

    int minFlipsMonoIncr(string s) {
        n = s.size();

        memset(dp,-1,sizeof(dp)) ;
        return f(0, 0, s); // Start with the first character, assuming previous is '0'
    }
};
