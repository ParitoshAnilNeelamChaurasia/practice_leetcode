// https://leetcode.com/problems/put-marbles-in-bags/description/

#define ll long long
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        ll n = weights.size() ;

        vector<ll> ans ;

        for(int i = 0 ; i < n-1 ; ++i)
        {
            ans.push_back(weights[i] + weights[i+1]);
        }

        sort(ans.begin() , ans.end()) ;

        ll mx = 0 ; 
        ll mn = 0 ;

        for(int i = 0 ; i < k-1 ; ++i)
        {
            mx += ans[ans.size()-i-1] ;
            mn += ans[i] ;
        }

        return mx - mn ;
    }
};
