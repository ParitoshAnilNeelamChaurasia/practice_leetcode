

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        int n = points.size() ;
        
        sort(points.begin() , points.end()) ;

        int count = 1 ;

        vector<int> prev = points[0] ;

        for(int i = 1 ; i < n ; ++i)
        {
            int curr_st = points[i][0] ;
            int curr_en = points[i][1] ;

            int prev_st = prev[0] ;
            int prev_en = prev[1] ;

            if(curr_st > prev_en)
            {
                count++ ;
                prev = points[i] ;
            }

// prev[0] = max(prev_st, curr_st); → Takes the latest start (ensuring we consider only the overlapping region).

// prev[1] = min(prev_en, curr_en); → Takes the earliest end (ensuring we don't include non-overlapping parts).
            else
            {
                prev[0] = max(prev_st , curr_st) ;
                prev[1] = min(prev_en , curr_en) ;
            }
        }
        return count ;
    }
};


// int n = points.size() ;

//         sort(points.begin() , points.end()) ;

//         int count = 1 ;

//         vector<int> prev = points[0] ;
//         for(int i = 1 ; i < n ; ++i)
//         {
//             int curr_st = points[i][0] ;
//             int curr_en = points[i][1] ;

//             int prev_st = prev[0] ;
//             int prev_en = prev[1] ;

//             if(curr_st > prev_en)
//             {
//                 count++ ;
//                 prev = points[i] ;
//             }
//             else
//             {
//                 prev[0] = max(prev_st , curr_st) ;
//                 prev[1] = min(prev_en , curr_en) ;
//             }
//         }
//         return count ;
