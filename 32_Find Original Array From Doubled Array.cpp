// https://leetcode.com/problems/find-original-array-from-doubled-array/description/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> ans;

 
        if (n % 2 != 0) {
            return {};
        }

        sort(changed.begin(), changed.end());

        map<int, int> mp;
        for (auto it : changed) {
            mp[it]++;
        }
        for (auto it : changed) {
            if (mp[it] == 0) 
            {
                continue;
            }

            int twice = 2 * it;

            if (mp.find(twice) == mp.end() || mp[twice] == 0) {
                return {};
            }
            ans.push_back(it);

            // Decrease the count of the current element and its doubled counterpart
            mp[it]--;
            mp[twice]--;
        }

        return ans;
    }
};
