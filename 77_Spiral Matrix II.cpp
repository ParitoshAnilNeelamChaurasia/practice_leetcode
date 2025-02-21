

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0)
        {
            return {} ;
        }

        int m = n ;

        int top = 0 ;
        int bottom = m-1 ;

        int left = 0 ;
        int right = m-1 ;


        vector<vector<int>>mat(m , vector<int>(n)) ;

        int id = 0 ;

        int counter = 1 ;
        while(top <= bottom && left <= right)
        {
            if(id == 0)
            {
            for(int i = left ; i <= right ; ++i)
            {
                mat[top][i] = counter++ ;
            }   
            // id++ ;
            top++ ;
            }

            else if(id == 1)
            {
                for(int i = top ; i <= bottom ; ++i)
                {
                    mat[i][right] = counter++  ;
                }
                // id++ ;
                right-- ;
            }

            else if(id == 2)
            {
                for(int i = right ; i >= left ; --i)
                {
                    mat[bottom][i] = counter++  ;
                }
                // id++ ;
                bottom-- ;
            }

            else if(id == 3)
            {
                for(int i = bottom ; i >= top ; --i)
                {
                    mat[i][left] = counter++  ;
                }
                // id++ ;
                left++ ;
            }
            id = (id+1) % 4 ;
        }
        return mat ;
    }
};
