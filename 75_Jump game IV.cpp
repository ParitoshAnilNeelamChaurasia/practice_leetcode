// https://leetcode.com/problems/jump-game-iv/description/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size() ;

        unordered_map<int,vector<int>> mp ;

        for(int i = 0 ; i < n ; ++i)
        {
            mp[arr[i]].push_back(i) ;
        }

        vector<bool> visited(n,false) ;

        queue<int> q ;
        q.push(0) ;
        visited[0] = true ;

        int steps = 0 ;

        while(!q.empty())
        {
            int sz = q.size() ;
            while(sz--)
            {
                int curr =q.front() ;
                q.pop() ;

                if(curr == n-1)
                {
                    return steps ;
                }

                int left = curr-1 ;
                int right = curr+ 1 ;

                if(left >= 0 && visited[left] == false)
                {
                    q.push(left) ;
                    visited[left] = true ;
                }

                if(right <= n-1 && visited[right] == false)
                {
                    q.push(right) ;
                    visited[right] = true ;
                }

                for(int &idx : mp[arr[curr]])
                {
                    if(!visited[idx])
                    {
                        q.push(idx) ;
                        visited[idx] = true ;
                    }
                }
                mp.erase(arr[curr]) ; // removing the current number from map as its already visited
            }
            steps++;
        }
        return -1 ;
    }
};
