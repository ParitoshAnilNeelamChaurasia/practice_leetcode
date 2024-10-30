// https://leetcode.com/problems/can-place-flowers/description/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size() ;

        if(n == 0)
        {
            return true ;
        }

        for(int i = 0 ; i < m ; ++i)
        {
            bool left_empty = false , right_empty = false ;

            if(i == 0 || flowerbed[i-1] == 0)
            {
                left_empty = true ;
            }

            if(i == m-1 || flowerbed[i+1] == 0)
            {
                right_empty = true ;
            }

            if(flowerbed[i] == 0 && left_empty == true && right_empty == true)
            {
                flowerbed[i] = 1 ;
                n-- ;
                if(n == 0)
                {
                    return true ;
                }
            }
        }
        return n == 0 ;
    }
};
