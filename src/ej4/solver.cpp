#include "./ej4.h"
#include "../matriz.h"

using namespace std;

/*
**  Exercise 4
**  Problem solver
*/

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
			bool sol_right_half = subarray_exists(arr_m, m, arr_prod_m, n - middle, l, i + middle, j, true, sol_i, sol_j);
			bool sol_left_half = subarray_exists(arr_m, m, arr_prod_m, middle, l, i, i + middle, false, sol_i, sol_j);

			if (sol_right_half || sol_left_half) {
				return true;
			}
			else {
				if (l <= middle) {
					for (int k = i + middle; k < i + middle + l - 1; k++) {
						if (arr_prod_m[k - l + 1] * arr_prod_m[k] == m) {
							*sol_i = k - l + 1;
							*sol_j = k + 1;
							return true;
						}
					}
				}
				else {
					for (int k = i + l - 1; k < j; k++) {
						if (arr_prod_m[k - l + 1] * arr_prod_m[k] == m) {
							*sol_i = k - l + 1;
							*sol_j = k + 1;
							return true;
						}
					}
				}
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
		}
		else {
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

	if (solution) {
		Matriz m_check = arr_m[sol_i];
		cout << sol_i << " " << sol_j << endl;
		for (int i = sol_i + 1; i < sol_j; i++) {
			m_check *= arr_m[i];
		}
		cout << (m_check == m ? "OK" : "FAIL") << endl;
	}

	cout << (solution ? "yes" : "no") << endl;
}
