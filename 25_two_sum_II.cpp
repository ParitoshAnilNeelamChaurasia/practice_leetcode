// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n = num.size() ;

        int i = 0 ;
        int j = n-1 ;

        while(i < j)
        {
            if(num[i] + num[j] == target)
            {
                return {i+1,j+1} ; 
            }
            else if(num[i] + num[j] > target)
            {
                j-- ;
            }
            else
            {
                i++ ;
            }
        }
        return {} ;
    }
};