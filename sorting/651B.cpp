/* Codeforces: 651B. Beautiful Paintings */
/* Link: https://codeforces.com/problemset/problem/651/B */


#include <iostream>
using namespace std;

int n, a[1000];


void sSort() {
    int minInd;
    int tmp;
    for (int i = 0; i < n - 1; i++) {
        minInd = i + 1;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minInd]) {
                minInd = j;
            }
        }

        if (a[minInd] < a[i]) {
            tmp = a[i];
            a[i] = a[minInd];
            a[minInd] = tmp;
        }
    }
}


int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sSort();

    int maxx = 1;
    int curr = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            curr++;
            maxx = max(maxx, curr);
        } else {
            curr = 1;
        }
    }

    cout << n - maxx << endl;
}