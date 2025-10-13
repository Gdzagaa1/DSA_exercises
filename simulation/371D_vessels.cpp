
/* Codeforces: 371D. Vessels */
/* Link: https://codeforces.com/problemset/problem/371/D */


/**
 * 
 * There is a system of n vessels arranged one above 
 * the other as shown in the figure below. Assume that 
 * the vessels are numbered from 1 to n, in the order from 
 * the highest to the lowest, the volume of the i-th vessel is ai liters.
 * Initially, all the vessels are empty. In some vessels water is poured. 
 * All the water that overflows from the i-th vessel goes to the (i + 1)-th one.
 * The liquid that overflows from the n-th vessel spills on the floor.
 * Your task is to simulate pouring water into the vessels. 
 * To do this, you will need to handle two types of queries:
 * 1. Add xi liters of water to the pi-th vessel;
 * 2. Print the number of liters of water in the ki-th vessel.
 */



#include <set>
#include <iostream>

using namespace std;

long long n; // The number of vessels
long long m; // The number of queries
long long type; // type of query(1 or 2)
long long vesselIndex; // Vessel index
long long water;
long long capacity[200001]; // capacity array
long long vessels[200001]; // The amount of water in vessel 
set<long long> notFull; // Set of the not full vessels
set<long long>::iterator it;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> capacity[i];
        notFull.insert(i);
    }
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> type;
        cin >> vesselIndex;
        if (type == 1) {
            cin >> water;
            it = notFull.lower_bound(vesselIndex);
            while (water > 0) {
                if (it == notFull.end()) break;
                long long currAmount = capacity[*it] - vessels[*it];
                if (water < currAmount) {
                    vessels[*it] += water;
                    water = 0;
                } else {
                    water -= currAmount;
                    vessels[*it] = capacity[*it];
                    it = notFull.erase(it++);
                }
            }

        } else {
            cout << vessels[vesselIndex] << endl;
        }
    }

    return 0;
}