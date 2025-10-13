
/* Codeforces: 313B. Ilya and Queries*/
/* Link: https://codeforces.com/problemset/problem/313/B*/

/**
 * 
 * Ilya the Lion wants to help all his friends with passing exams.
 * They need to solve the following problem to pass the IT exam.
 * You've got string s = s1s2... sn (n is the length of the string), 
 * consisting only of characters "." and "#" and m queries. Each query is 
 * described by a pair of integers li, ri (1 ≤ li < ri ≤ n). The answer to the query li, 
 * ri is the number of such integers i (li ≤ i < ri), that si = si + 1.
 * Ilya the Lion wants to help his friends but is there anyone to help him? 
 * Help Ilya, solve the problem.
 */



#include <string>
#include <iostream>
using namespace std;

int arr[100000];

int main() {
    string s;
    cin >> s;
    
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == s[i]) {
            arr[i] = arr[i - 1] + 1;
        } else {
            arr[i] = arr[i - 1];
        }
    }

    int m, l, r;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        cout << arr[r - 1] - arr[l - 1] << endl;
     }


    return 0;
}

