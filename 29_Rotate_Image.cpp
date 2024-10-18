// https://leetcode.com/problems/rotate-image/description/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size() ;

        for(int i = 0 ; i < m ; ++i)
        {
            for(int j = i ; j < m ; ++j)
            {
                swap(matrix[i][j] , matrix[j][i]) ;
            }
        }

        for(int j = 0 ; j < m ; ++j)
        {
            reverse(matrix[j].begin() , matrix[j].end()) ;
        }
    }
};
