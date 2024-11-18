

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ;

        int mx = INT_MIN ;

        int i = 0 ;
        int j = n-1 ;

        while(i < j)
        {
            int wid = j - i ;
            int ar = wid*( min(height[j] , height[i])) ;

            mx = max(mx , ar) ;

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
