/* Codeforces: 567C. Geometric Progression */
/* Link: https://codeforces.com/problemset/problem/567/C */



#include <iostream>
#include <map>

using namespace std;

long long n, k, a[200000];
map<long long, long long> leftM, rightM;

int main () {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        rightM[a[i]]++;
    }

    leftM[a[0]]++;
    rightM[a[0]]--;

    long long answ = 0;
    for (int i = 1; i < n - 1; i++) {
       rightM[a[i]]--;
       if (a[i] % k == 0) {
            answ += leftM[a[i] / k] * rightM[a[i] * k]; 
       } 
       leftM[a[i]]++;
    }
    cout << answ;
}
