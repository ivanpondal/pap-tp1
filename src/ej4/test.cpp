#include "./ej4.h"
#include "../mini_test.h"

using namespace std;

/*
**  Exercise 4
**  Unit tests
*/

void test_sample_input_1() {
	ifstream input_file;
	input_file.open("ej4/test_cases/input_1");

	int n, l;
	Matriz m;

	input_file >> n >> l;
	input_file >> m;

	vector<Matriz> arr_m(n);
	vector<Matriz> arr_prod_m(n);

	for (int i = 0; i < n; i++) {
		input_file >> arr_m[i];
	}
	input_file.close();

	bool solution = subarray_exists(arr_m, m, arr_prod_m, n, l, 0, n, true);

	ASSERT(!solution);
}

void test_sample_input_2() {
	ifstream input_file;
	input_file.open("ej4/test_cases/input_2");

	int n, l;
	Matriz m;

	input_file >> n >> l;
	input_file >> m;

	vector<Matriz> arr_m(n);
	vector<Matriz> arr_prod_m(n);

	for (int i = 0; i < n; i++) {
		input_file >> arr_m[i];
	}
	input_file.close();

	bool solution = subarray_exists(arr_m, m, arr_prod_m, n, l, 0, n, true);

	ASSERT(solution);
}

void test_sample_input_3() {
	ifstream input_file;
	input_file.open("ej4/test_cases/input_3");

	int n, l;
	Matriz m;

	input_file >> n >> l;
	input_file >> m;

	vector<Matriz> arr_m(n);
	vector<Matriz> arr_prod_m(n);

	for (int i = 0; i < n; i++) {
		input_file >> arr_m[i];
	}
	input_file.close();

	bool solution = subarray_exists(arr_m, m, arr_prod_m, n, l, 0, n, true);

	ASSERT(solution);
}

void test_sample_input_4() {
	ifstream input_file;
	input_file.open("ej4/test_cases/input_4");

	int n, l;
	Matriz m;

	input_file >> n >> l;
	input_file >> m;

	vector<Matriz> arr_m(n);
	vector<Matriz> arr_prod_m(n);

	for (int i = 0; i < n; i++) {
		input_file >> arr_m[i];
	}
	input_file.close();

	bool solution = subarray_exists(arr_m, m, arr_prod_m, n, l, 0, n, true);

	ASSERT(!solution);
}

void test_base_case() {
	int n = 1;
	int l = 1;

	vector<Matriz> arr_m(1);
	vector<Matriz> arr_prod_m(1);

	Matriz m({1, 2, 3, 4, 5, 6, 7, 8, 9});
	arr_m[0] = m;

	bool solution = subarray_exists(arr_m, m, arr_prod_m, n, l, 0, n, true);
	ASSERT(solution);

	m = Matriz({0, 2, 3, 4, 5, 6, 7, 8, 9});
	solution = subarray_exists(arr_m, m, arr_prod_m, n, l, 0, n, true);

	ASSERT(!solution);
}

void test_big_instance() {
	int n = 10000;

	srand(42);

	vector<Matriz> arr_m(n);
	vector<Matriz> arr_prod_m(n);
	vector<int> vec(9);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			vec[j] = rand();
		}
		arr_m[i] = Matriz(vec);
	}

	for (int k = 0; k < 10; k++) {
		int l = rand() % n + 1;

		int start = rand() % (n - l + 1);
		int end = start + l;
		Matriz m = arr_m[start];
		for (int i = start + 1; i < end; i++) {
			m *= arr_m[i];
		}

		bool solution = subarray_exists(arr_m, m, arr_prod_m, n, l, 0, n, true);

		ASSERT(solution);
	}
}

void test_big_instance_no_solution() {
	int n = 10000;

	srand(42);

	vector<Matriz> arr_m(n);
	vector<Matriz> arr_prod_m(n);
	vector<int> vec(9);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			vec[j] = rand();
		}
		arr_m[i] = Matriz(vec);
	}

	Matriz m({-1, -1, -1, -1, -1, -1, -1, -1, -1});
	for (int k = 0; k < 10; k++) {
		int l = rand() % n + 1;

		bool solution = subarray_exists(arr_m, m, arr_prod_m, n, l, 0, n, true);

		ASSERT(!solution);
	}
}

void run_unit_tests() {
	RUN_TEST(test_sample_input_1);
	RUN_TEST(test_sample_input_2);
	RUN_TEST(test_sample_input_3);
	RUN_TEST(test_sample_input_4);
	RUN_TEST(test_base_case);
	RUN_TEST(test_big_instance);
	RUN_TEST(test_big_instance_no_solution);
}
