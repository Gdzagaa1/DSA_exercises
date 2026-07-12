
/* Codeforces: 385C. Bear and Prime Numbers */
/* Link: https://codeforces.com/problemset/problem/385/C */



#include <iostream>

using namespace std;

int n, m, k, l, r, x[10000001], y[10000001];


/*
 * Algorithm: 
 * Let's make sieve of Eratosthenes to find prime numbers for each elemnt of arrays.
 * Then with prefix-sums we can easily calculate output.
*/

int main() {
    cin >> n;
    int elem;
    for (int i = 0; i < n; i++) {
        cin >> elem;
        x[elem]++;
    }

    // sieve
    for (int i = 2; i <= 10000000; i++) {
        if (y[i] == 0) {
            for (int j = i; j <= 10000000; j += i) {
                y[i] += x[j];
                if (i != j) {
                    y[j] = -1;
                }
            }
        }
    }

    // prefix sums
    for (int i = 1; i <= 10000000; i++){
        if (y[i + 1] == -1) {
            y[i + 1] = 0;	
        }
        y[i] += y[i-1];
    }


    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> l >> r;
        if (l > 10000000) {
             l = 10000000;
        }
        if (r > 10000000) {
            r = 10000000;
        }

        cout << y[r] - y[l - 1] << endl;
    }


}