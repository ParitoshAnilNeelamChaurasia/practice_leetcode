// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        string ans;

        for (char c : s) 
        {
            if (isalnum(c)) 
            { 
                if (isupper(c))
                {
                    c = tolower(c); 
                }
                ans += c;
            }
        }

        int i = 0;
        int j = ans.size() - 1;

        while (i < j) 
        {
            if (ans[i] != ans[j]) 
            {
                return false; 
            }
            i++;
            j--;
        }

        return true; 
    }
};
