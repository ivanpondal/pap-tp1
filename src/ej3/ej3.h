#ifndef PAP_TP1_EJ3_H
#define PAP_TP1_EJ3_H

#include "../main.h"
#include <vector>
#include <iostream>

using namespace std;

/*
**  Exercise 3
*/

struct test_case {
    vector<int> input;
    int expected;
};

int max_subarray_sum(vector<int>&);

int max_int(int a, int b);

#endif // PAP_TP1_EJ3_H
