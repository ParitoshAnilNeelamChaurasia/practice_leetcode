class Solution {
public:
    // Check if a number has all bits set
    bool f(int x) {
        // Check if x is of the form 2^n - 1
        while (x > 0) {
            if ((x & 1) == 0) return false; // If any bit is unset
            x >>= 1;
        }
        return true;
    }

    int smallestNumber(int n) {
        vector<int> ans;

        // Generate numbers with all bits set (of the form 2^k - 1)
        for (int i = 1; i <= 1023; ++i) { // Maximum 10 bits (1023 = 1111111111 in binary)
            if (f(i)) { // Check if the number has all bits set
                ans.push_back(i);
            }
        }

        // Find the smallest number >= n
        for (int i = 0; i < ans.size(); ++i) {
            if (ans[i] >= n) {
                return ans[i];
            }
        }

        return -1; 
    }
};
