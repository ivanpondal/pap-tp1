#include "./ej3.h"

/*
**  Exercise 3
**  Problem solver
*/

int max_subarray_sum(vector<int>& v) {
    int accum = 0, max_achieved = 0;
    for (int x : v) {
        accum = max(accum + x, 0);
        max_achieved = max(max_achieved, accum);
    }
    return max_achieved;
}

/////////////////

void run_solver() {
    int n, x;
    cin >> n;

    vector<int> v;

    while(n--) {
        cin >>x;
        v.push_back(x);
    }
    
    cout << max_subarray_sum(v) << endl;
}
