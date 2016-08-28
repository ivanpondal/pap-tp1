#ifndef PAP_TP1_EJ4_H
#define PAP_TP1_EJ4_H

#include "../main.h"
#include "../matriz.h"

/*
**  Exercise 4
*/

// Here go declarations of functions which are exported by the problem solver,
// global variables, etc.

bool subarray_exists(Matriz *arr_m, Matriz &m, Matriz *arr_prod_m,
		int n, int l, int i, int j, bool right_half);

#endif // PAP_TP1_EJ4_H
