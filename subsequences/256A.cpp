/* Codeforces: 256A */
/* Link: https://codeforces.com/problemset/problem/256/A */

/*
 * Input:
 * The first line contains integer n (1 ≤ n ≤ 4000). 
 * The next line contains n integers b1, b2, ..., bn (1 ≤ bi ≤ 106).
 * Output:
 * Print a single integer — the length of the required longest subsequence.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
using namespace std;




int n, b[4001];
vector<int> uniquee;
unordered_set<int> st;

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[b[i]]++;
    }

    vector<pair<int, int>> valFreq;
    for (auto& p : freq) {
        valFreq.push_back({p.second, p.first});
    }
    sort(valFreq.rbegin(), valFreq.rend());

    vector<int> uniquee;
    int limit = min((int)valFreq.size(), 200);
    for (int i = 0; i < limit; i++) {
        uniquee.push_back(valFreq[i].second);
    }

    int res = 1;

      for (int j = 0; j < limit; j++) {
         int first = uniquee[j]; 
        for (int k = 0; k < limit; k++) {
             int second = uniquee[k];  
            int count = 0;
            int next = first;

            for (int i = 0; i < n; i++) {
                if (b[i] == next) {
                    count++;
                    if (next == first) {
                        next = second;
                    } else {
                        next = first;
                    }
                }
            }

            res = max(res, count);
        }
    }
    
    cout << res << endl;

    return 0;
}