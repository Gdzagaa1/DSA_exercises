/* Codeforces: 253B. Physics Practical */
/* Link: https://codeforces.com/problemset/problem/253/B */


/*
algorithm:
1. Sort the array of measurements in ascending order. O(n log n)
2. For each element as potential minimum: Use binary
   search to find rightmost element <= 2 * minimum
   and count elements in valid range [min, 2*min]
3. Track maximum count of measurements we can keep
4. Answer = total measurements - maximum we can keep

Time Complexity: O(n log n)

For sorting i used c++ sort. Quicksort implementation is commented, 
it exceeded time limit.
*/


#include <iostream>
#include <fstream> 
#include <algorithm>  
using namespace std;



int n, c[100000];

// int partition(int start, int end) {
//     int randomIndex = start + rand() % (end - start + 1);
//     int temp = c[randomIndex];
//     c[randomIndex] = c[end];
//     c[end] = temp;

//     int pivot = c[end];
//     int i = start - 1;

//     for (int j = start; j <= end - 1; j++) {
//         if (c[j] < pivot) {
//             i++;
//             int temp = c[i];
//             c[i] = c[j];
//             c[j] = temp; 
//         }
//     }
//     i++;
//     temp = c[i];
//     c[i] = c[end];
//     c[end ] = temp; 


//     return i;
// }

// void quick(int start, int end) {
//     if (end <= start) return;

//     int pivot = partition(start, end);
//     quick(start, pivot - 1);
//     quick(pivot + 1, end);
// }


int binarySearch(int left, int right, int target) {
    int result = left - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (c[mid] <= target) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}




int main() {
    // srand(time(0));

    ifstream fin("input.txt");

    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> c[i];
    }
    fin.close();

    // quick(0, n - 1);
    sort(c, c + n);

    cout << endl;

    int max = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int right = binarySearch(i, n - 1, c[i] * 2);
        int count = right - i + 1;

        if (count > max) { 
            max = count;
        }
    }

    ofstream fout("output.txt");
    
    fout << n - max << endl;
    fout.close(); 
    
    return 0;
}