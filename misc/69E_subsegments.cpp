
/* Codeforces: 69E. Subsegments */
/* Link: https://codeforces.com/problemset/problem/69/E */

/*
 * Input:
 * The first line contains two positive integers 
 * n and k (1 ≤ n ≤ 105, 1 ≤ k ≤ n) — the number 
 * of array elements and the length of the segment.
 * Then follow n lines: the i-th one contains a 
 * single number ai ( - 109 ≤ ai ≤ 109).
 * 
 * Output:
 * Print n–k + 1 numbers, one per line: on the 
 * i-th line print of the maximum number of those 
 * numbers from the subarray ai ai + 1 … ai + k - 1 
 * that occur in this subarray exactly 1 time. If there are 
 * no such numbers in this subarray, print "Nothing".
*/



#include <map>
#include <set>
#include <iostream>
using namespace std;

int n, k, a[100000];
map<int, int> m;
set<int> s;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
        if (m[a[i]] > 1) {
            s.erase(a[i]);
        } 

        if (m[a[i]] == 1) {
            s.insert(a[i]);
        }
        if (i < k - 1) continue;

        if (s.empty()) {
            cout << "Nothing" << endl;
        } else {
            cout << *(--s.end()) << endl;
        }

        int start = a[i - k + 1];
        m[start]--;
        if (m[start] == 1) {
            s.insert(start);
        } else {
            s.erase(start);
        }
    }
}







