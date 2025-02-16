// https://leetcode.com/problems/eat-pizzas/description/

class Solution {
public:
    long long maxWeight(vector<int>& p) {
        sort(p.begin(), p.end()); // 🔢 Sort the pizzas in ascending order 
        int n = p.size();
        int m = n / 4; // 📆 Total number of days (each day we eat 4 pizzas)
        int odd = (m + 1) / 2; // 🔵 Number of odd days
        int even = m - odd; // 🟢 Number of even days
        
        long long sum = 0;
        int l = n - 1; // 🔙 l points to the last element
        
        // 🔵 On odd days, we gain the weight of the heaviest pizza in the set of 4
        for (int i = 0; i < odd; i++) {
            sum += p[l]; // 🍕 Pick the largest pizza
            l--; // ⬅ Move left
        }
        
        // 🟢 On even days, we gain the weight of the second heaviest pizza in the set of 4
        for (int i = 0; i < even; i++) {
            l--; // ⏩ Skip third largest pizza
            sum += p[l]; // 🍕 Gain the weight of the second largest pizza
            l--; // ⬅ Move left again
        }
        
        return sum; // 🔢 Return maximum weight gained 🎯
    }
};
