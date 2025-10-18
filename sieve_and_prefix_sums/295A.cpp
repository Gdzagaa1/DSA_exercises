
/* Codeforces: 295A. Greg and Array */
/* Link: https://codeforces.com/problemset/problem/295/A */

/**
 * Greg has an array a = a1, a2, ..., an and m operations. 
 * Each operation looks as: li, ri, di, (1 ≤ li ≤ ri ≤ n). 
 * To apply operation i to the array means to increase all 
 * array elements with numbers li, li + 1, ..., ri by value di.
 * Greg wrote down k queries on a piece of paper. Each query 
 * has the following form: xi, yi, (1 ≤ xi ≤ yi ≤ m). That 
 * means that one should apply operations with numbers 
 * xi, xi + 1, ..., yi to the array. Now Greg is wondering,
 * what the array a will be after all the queries are executed. Help Greg.
 */


 // The solution uses prefix sums.

#include <iostream>

using namespace std;

long long n, m, k, a[100002], prefix[100002], secondPrefix[100002], x, y, l[100002], r[100002], d[100002];

int main () {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> d[i];
    }

    // Use prefix sum to calculate how many times each operation is executed
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        prefix[x] += 1;
        prefix[y + 1] -= 1;
    }

    for (int i = 1; i <= m; i++) {
        prefix[i] += prefix[i - 1];
    }

    for (int i = 0; i < m; i++) {
        d[i] *= prefix[i + 1];
    }


    // Doing the prefix sum for calculating final array
    for (int i = 0; i < m; i++) {
        secondPrefix[l[i]] += d[i];
        secondPrefix[r[i] + 1] -= d[i];
    }

    for (int i = 1; i <= n; i++) {
        secondPrefix[i] += secondPrefix[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        secondPrefix[i] += a[i - 1];
        cout << secondPrefix[i] << " ";
    }


}