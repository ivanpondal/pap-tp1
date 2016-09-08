#ifndef PAP_TP1_EJ3_H
#define PAP_TP1_EJ3_H

#include "../main.h"
#include <vector>
#include <iostream>

#define INPUT_SIZE_UPPER_BOUND 100000

using namespace std;

/*
**  Exercise 3
*/

/* tester */

struct test_case {
    vector<int> data;
    int expected;
};

/* solver */

int max_subarray_sum(vector<int>&);

#endif // PAP_TP1_EJ3_H
