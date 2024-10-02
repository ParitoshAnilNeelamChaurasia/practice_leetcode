// https://www.geeksforgeeks.org/problems/two-numbers-with-sum-closest-to-zero1737/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            // your code here 
            
            if(n < 2)
            return -1 ;
            
            sort(arr , arr+n) ;
            
            int i = 0 ; int j = n-1 ;
            
            int ans = INT_MAX ;
            
            int sum = 0 ;
            
            while(i < j)
            {
                sum = arr[i] + arr[j] ;
                
                if(abs(sum) < abs(ans))
                {
                    ans = sum ;
                }
                
                else if(abs(sum) == abs(ans) && sum > ans)
                {
                    ans = sum ;
                }
                
                if(sum < 0)
                {
                    i++ ;
                }
                else
                {
                    j-- ;
                }
            }
            return ans ;
        }
};

//{ Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}
// } Driver Code Ends
