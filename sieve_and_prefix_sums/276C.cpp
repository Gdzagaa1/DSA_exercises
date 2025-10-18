
/* Codeforces: 276C. Little Girl and Maximum Sum */
/* Link: https://codeforces.com/problemset/problem/276/C */


/** 
 * The little girl loves the problems on array queries very much.
 * One day she came across a rather well-known problem: you've got 
 * an array of 𝑛 elements (the elements of the array are indexed 
 * starting from 1); also, there are 𝑞 queries, each one is defined 
 * by a pair of integers 𝑙𝑖, 𝑟𝑖 (1≤𝑙𝑖≤𝑟𝑖≤𝑛). You need to find for each 
 * query the sum of elements of the array with indexes from 𝑙𝑖 to 𝑟𝑖, inclusive.
 * The little girl found the problem rather boring. She decided to 
 * reorder the array elements before replying to the queries in a 
 * way that makes the sum of query replies maximum possible. Your 
 * task is to find the value of this maximum sum.
 */




// The solution uses prefix sums.

#include <iostream>
#include <algorithm> 

int x[200000];
int prefix[200005];
using namespace std;

int main() {
    int n, q;
    cin>>n>>q;
    for (int i = 0; i < n; i++) {
        cin>>x[i];
    }
    int first, second;
    for (int i = 0; i < q; i++) {
        cin>>first;
        prefix[first] += 1;
        cin>>second;
        prefix[second + 1] -=1;
    }

    //prefix sums
    for (int i = 1; i <= n; i++) {
        prefix[i] += prefix[i - 1];
    }
    sort(prefix + 1, prefix + n + 1);
    sort(x, x + n);

    long long answ = 0;

    for (int i = 0; i < n; i++) {
        answ += (long long)x[i] * prefix[i + 1];
    }
    cout << answ;

    return 0;
}