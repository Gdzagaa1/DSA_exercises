#include <iostream>

/* Codeforces: 26A */
/* Link: https://codeforces.com/problemset/problem/26/A */

/*
 * A number is called almost prime if it has exactly two distinct prime divisors. 
 * For example, numbers 6, 18, 24 are almost prime, while 4, 8, 9, 42 are not. 
 * Find the amount of almost prime numbers which are between 1 and n, inclusive. 
*/


/*
 * Solution uses sieve of erathostenes
 */

using namespace std;


int arr[3000];

int main() {

    int n;
    cin >> n;
    
    for (int i = 2; i <= n; i++) {
        if (arr[i] > 0) continue;

        for (int j = i * 2; j <= n; j += i) {
            arr[j] = arr[j] + 1;
        }
    }

    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (arr[i] == 2) count++;
    }

    cout << count;

    return 0;
}





