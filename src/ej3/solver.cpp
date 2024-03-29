#include "./ej3.h"

/*
**  Exercise 3
**  Problem solver
*/

int max_subarray_sum(vector<int>& v) {
    int accum = 0, max_achieved = 0;
    for (int x : v) {
        accum = max(accum + x, 0); // accumulate greedily, reset if sum goes negative
        max_achieved = max(max_achieved, accum); // keep track of highest sum achieved
    }
    return max_achieved;
}

/////////////////

void run_solver() {
    int n, x;
    vector<int> v;

    cin >> n;
    while(n--) {
        cin >> x;
        v.push_back(x);
    }

    cout << max_subarray_sum(v) << endl;
}
