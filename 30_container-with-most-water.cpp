// https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ;

        int mx = INT_MIN ;

        int i = 0 ; 
        int j = n-1 ;

        while(i < j)
        {
            int width = j-i ;

            int ht = min(height[i] , height[j]) ;

            mx = max(mx , width*ht) ;

            if(height[i] > height[j])
            {
                j-- ;
            }
            else
            {
                i++ ;
            }
        }
        return mx ;
    }
};
