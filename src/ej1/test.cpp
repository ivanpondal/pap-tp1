#include "./ej1.h"
#include "../mini_test.h"

/*
**  Exercise 1
**  Unit tests
*/

void test_1() {
	int budget = 1;
	vector<int> elems = {0};
	ASSERT_EQ(solution(budget, elems), 0);
}

void test_2() {
	int budget = 1;
	vector<int> elems = {1};
	ASSERT_EQ(solution(budget, elems), 1);
}

void test_3() {
	int budget = 1;
	vector<int> elems = {0, 1};
	ASSERT_EQ(solution(budget, elems), 1);
}

void test_4() {
	int budget = 1;
	vector<int> elems = {3, 1};
	ASSERT_EQ(solution(budget, elems), 1);
}

void test_5() {
	int budget = 2;
	vector<int> elems = {3, 1};
	ASSERT_EQ(solution(budget, elems), 1);
}

void test_6() {
	int budget = 3;
	vector<int> elems = {3, 1};
	ASSERT_EQ(solution(budget, elems), 3);
}

void test_7() {
	int budget = 4;
	vector<int> elems = {3, 1};
	ASSERT_EQ(solution(budget, elems), 4);
}

void test_8() {
	int budget = 5;
	vector<int> elems = {3, 1};
	ASSERT_EQ(solution(budget, elems), 4);
}

void test_9() {
	int budget = 20;
	vector<int> elems = {2, 6, 7, 7, 5};
	ASSERT_EQ(solution(budget, elems), 20);
}

void test_10() {
	int budget = 18;
	vector<int> elems = {3, 6, 7, 7, 8};
	ASSERT_EQ(solution(budget, elems), 18);
}

void test_11() {
	int budget = 123;
	vector<int> elems = {1, 64, 7, 57, 5, 8};
	ASSERT_EQ(solution(budget, elems), 122);
}

void test_12() {
	int budget = 123;
	vector<int> elems = {2, 64, 7, 57, 5, 8};
	ASSERT_EQ(solution(budget, elems), 123);
}

void test_13() {
	int budget = 123;
	vector<int> elems = {3, 64, 7, 57, 5, 8};
	ASSERT_EQ(solution(budget, elems), 121);
}

void test_example_1() {
	int budget = 10;
	vector<int> elems = {3, 3, 3, 3};
	ASSERT_EQ(solution(budget, elems), 9);
}

void test_example_2() {
	int budget = 12;
	vector<int> elems = {1, 2, 3, 4, 5};
	ASSERT_EQ(solution(budget, elems), 12);
}

void run_unit_tests() {
    RUN_TEST(test_1);
    RUN_TEST(test_2);
    RUN_TEST(test_3);
    RUN_TEST(test_4);
    RUN_TEST(test_5);
    RUN_TEST(test_6);
    RUN_TEST(test_7);
    RUN_TEST(test_8);
    RUN_TEST(test_9);
    RUN_TEST(test_10);
    RUN_TEST(test_11);
    RUN_TEST(test_12);
    RUN_TEST(test_13);
    RUN_TEST(test_example_1);
    RUN_TEST(test_example_2);
}
