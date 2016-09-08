#include "./ej3.h"
#include "../mini_test.h"

/*
**  Exercise 3
**  Unit tests
*/

// fills out a given vector with random positive numbers and returns their sum
int randomNonNegativeVectorFillAndSum(vector<int>& v) {
    // calculate an upper bound for vector elements so they are uniformly distributed and their sum does not overflow int capacity
	int upperBound = (int)((1<<31)-1) / v.size();
	int sum = 0;
	int currentRand;
	for (auto it = v.begin(); it != v.end(); ++it) {
		currentRand = rand() % upperBound;
		sum += currentRand;
		*it = currentRand;
	}
    return sum;
}

void run_unit_tests() {
    // create test cases
    vector<int> loadTestData(INPUT_SIZE_UPPER_BOUND); // create zero- vector
    int loadTestExpected = randomNonNegativeVectorFillAndSum(loadTestData);

    vector<test_case> cases = {
            {{}, 0}, // arreglo vacío, el óptimo es el vacío
            {{-1,-1,-1,-1}, 0}, // el óptimo es el vacío en arreglo no vacío
            {{1,2,3,4,5,-1,-2,-3,6,-5,1,2,3,4}, 20}, // el óptimo es todo el arreglo
            {{1,2,3,4,5,-1,-2,-3,-4,-5,1,2,3,4}, 15}, // el óptimo es un prefijo
            {{1,2,-7,1,2,3,4,5,-16,2}, 15}, // subarreglo óptimo que no es prefijo ni sufijo
            {loadTestData, loadTestExpected},
    };

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
