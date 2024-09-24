// https://leetcode.com/problems/maximum-product-subarray/description/

#define ll long long
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        ll leftProduct = 1;
        ll rightProduct = 1;
        ll ans = nums[0];

        for (int i = 0; i < n; ++i) {
            // If leftProduct or rightProduct becomes 0, reset to 1
            if (leftProduct == 0) 
            {
                leftProduct = 1;
            }

            if (rightProduct == 0) 
            {
                rightProduct = 1;
            }

            // Prefix product
            leftProduct *= nums[i];

            // Suffix product
            rightProduct *= nums[n - 1 - i];

            // Update the maximum result
            ans = max(ans, max(leftProduct, rightProduct));
        }

        return (int)ans;
    }
};
