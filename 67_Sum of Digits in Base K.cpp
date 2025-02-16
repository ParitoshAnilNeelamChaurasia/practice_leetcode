// https://unstop.com/practice/company-preparation/goldman-sachs/goldman-coding-assessment-29695/question-29717

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int f(int n , int k)
{
    int sum = 0 ;

    while(n > 0)
    {
        sum = sum + n %k ;
        n = n / k ;
    }
    return sum ;
}
int main() {
    int n , k ;
    cin >> n ;
    cin >> k ;

    int x = f(n,k) ;  

    cout<< x<<endl ;
    return 0;
}
