#include "./ej3.h"
#include "../mini_test.h"

/*
**  Exercise 3
**  Unit tests
*/

// given an array of arbitrary type and its size, creates the corresponding vector
template<typename T>
vector<T> arr2vec(int n, T arr[]) {
    return vector<T>(arr, arr + n);
}

void run_unit_tests() {
    // create test cases
    vector<test_case> cases =
        arr2vec(6, (test_case[]) {
            {.data = arr2vec(14, (int[]){1,2,3,4,5,-1,-2,-3,6,-5,1,2,3,4}), .expected = 20}, // el óptimo es todo el arreglo
            {.data = arr2vec(14, (int[]){1,2,3,4,5,-1,-2,-3,-4,-5,1,2,3,4}), .expected = 15}, // el óptimo es un prefijo
            {.data = arr2vec(0, (int[]){}), .expected = 0}, // arreglo vacío, el óptimo es el vacío
            {.data = arr2vec(4, (int[]){-1,-1,-1,-1}), .expected = 0}, // el óptimo es el vacío en arreglo no vacío
            {.data = arr2vec(10, (int[]){1,2,-7,1,2,3,4,5,-16,2}), .expected = 15}, // subarreglo óptimo que no es prefijo ni sufijo
        });

    // run test cases
    int obtained;
    bool success = true;
    for (test_case c : cases) {
        if ((obtained = max_subarray_sum(c.data)) != c.expected) {
            success = false;
            cout << "FAIL" << endl;
            cout << "Case " << c.data << endl;
            cout << "Expected " << c.expected << ", obtained " << obtained << endl << endl;
        }
    }

    // output final result
    if (success) {
        cout << "Tests pass! :)" << endl;
    } else {
        cout << "Tests fail." << endl;
    }
}
