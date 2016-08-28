#include "./ej4.h"
#include "../matriz.h"

using namespace std;

/*
**  Exercise 4
**  Problem solver
*/

int max(int a, int b) {
	return (a > b) ? a : b;
}

int min(int a, int b) {
	return (a < b) ? a : b;
}

void calculate_matrix_products(Matriz *arr_m, Matriz *arr_prod_m, int i, int j, bool right_half) {
	if (right_half) {
		arr_prod_m[i] = arr_m[i];
		for (int k = i + 1; k < j; k++) {
			arr_prod_m[k] = arr_prod_m[k - 1] * arr_m[k];
		}
	}
	else {
		arr_prod_m[j - 1] = arr_m[j - 1];
		for (int k = j - 2; k >= i; k--) {
			arr_prod_m[k] = arr_m[k] * arr_prod_m[k + 1];
		}
	}
}

bool subarray_exists(Matriz *arr_m, Matriz &m, Matriz *arr_prod_m,
		int n, int l, int i, int j, bool right_half, int *sol_i, int *sol_j) {

	if (n == 1) {
		if (l == 1 && arr_m[i] == m) {
			*sol_i = i;
			*sol_j = j;
			return true;
		}
		else {
			arr_prod_m[i] = arr_m[i];
		}
	}
	else {
		if (l <= n) {
			int middle = n / 2;

			bool sol_right_half = subarray_exists(
					arr_m, m, arr_prod_m, n - middle, l, i + middle, j, true, sol_i, sol_j);

			bool sol_left_half = subarray_exists(
					arr_m, m, arr_prod_m, middle, l, i, i + middle, false, sol_i, sol_j);

			if (sol_right_half || sol_left_half) {
				return true;
			}
			else {
				int start = max(i + middle, i + l - 1);
				int end = min(i + middle + l - 1, j);

				for (int k = start; k < end; k++) {
					if (arr_prod_m[k - l + 1] * arr_prod_m[k] == m) {
						*sol_i = k - l + 1;
						*sol_j = k + 1;
						return true;
					}
				}
				calculate_matrix_products(arr_m, arr_prod_m, i, j, right_half);
			}
		}
		else {
			calculate_matrix_products(arr_m, arr_prod_m, i, j, right_half);
		}
	}
	return false;
}

void run_solver() {
	int n, l;
	Matriz m;

	cin >> n >> l;
	cin >> m;

	Matriz arr_m[n];
	Matriz arr_prod_m[n];

	for (int i = 0; i < n; i++) {
		cin >> arr_m[i];
	}

	int sol_i, sol_j;

	bool solution = subarray_exists(arr_m, m, arr_prod_m, n, l, 0, n, true, &sol_i, &sol_j);

	cout << (solution ? "SI" : "NO") << endl;
}
