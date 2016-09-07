#include "./ej2.h"
#include "../mini_test.h"

/*
**  Exercise 2
**  Unit tests
*/

int solve_with_input(string file_name) {
	ifstream input_file;
	input_file.open(file_name);
	int N;
	input_file >> N;
	vector< vector<int> > diversion = vector< vector<int> >(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			input_file >> diversion [i][j];
		}
	}
	input_file.close();
	return calculate_max_diversion(N, diversion);
}

void test_example_1() {
	int res = solve_with_input("ej2/example_1");
	ASSERT(res==1);
}

void test_example_2() {
	int res = solve_with_input("ej2/example_2");
	ASSERT(res==4);
}

void test_example_3() {
	int res = solve_with_input("ej2/example_3");
	ASSERT(res==7);
}

void test_example_4() {
	int res = solve_with_input("ej2/example_4");
	ASSERT(res==153);
}

void run_unit_tests() {
	RUN_TEST(test_example_1);
	RUN_TEST(test_example_2);
	RUN_TEST(test_example_3);
	RUN_TEST(test_example_4);
}
