#ifndef PAP_TP1_EJ1_H
#define PAP_TP1_EJ1_H

#include "../main.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
**  Exercise 1
*/

// Here go declarations of functions which are exported by the problem solver,
// global variables, etc.
void recursive_sums_with_next(vector<int> &sums, vector<int> set, unsigned int index, int sum);
void recursive_sums_without_next(vector<int> &sums, vector<int> set, unsigned int index, int sum);

#endif // PAP_TP1_EJ1_H
