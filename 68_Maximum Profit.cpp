// https://unstop.com/practice/company-preparation/goldman-sachs/goldman-coding-assessment-29695/question-29718

#include <iostream>
#include <vector>
using namespace std;

// Placeholder function where the user will write the logic
int user_logic(const vector<int>& nums) {
    int n = nums.size() ;

    int max_sum = nums[0] ;
    int curr_sum = nums[0] ;

    for(int i = 1 ; i < n ; ++i)
    {
        curr_sum = max(nums[i] , curr_sum + nums[i]) ;
        max_sum = max(max_sum , curr_sum ) ;
    }
    return max_sum ;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    // Call user logic function and print the output
    int result = user_logic(nums);
    cout << result << endl;
    return 0;
}
