#include "./ej1.h"
#include <math.h>

/*
**  Exercise 1
**  Problem solver
*/

vector<int> all_sums(vector<int> set) {
	vector<int> sums;
	sums.reserve(pow(2, set.size()));

	if(set.size() > 0) {
		recursive_sums_with_next(sums, set, 0, 0);
		recursive_sums_without_next(sums, set, 0, 0);
	}

	return sums;
}


void recursive_sums_with_next(vector<int> &sums, vector<int> set, unsigned int index, int sum) {
	if(index == set.size() - 1) {
		sums.push_back(sum + set[index]);
	}
	else {
		recursive_sums_with_next(sums, set, index + 1, sum + set[index]);
		recursive_sums_without_next(sums, set, index + 1, sum + set[index]);
	}
}

void recursive_sums_without_next(vector<int> &sums, vector<int> set, unsigned int index, int sum) {
	if(index == set.size() - 1) {
		sums.push_back(sum);
	}
	else {
		recursive_sums_with_next(sums, set, index + 1, sum);
		recursive_sums_without_next(sums, set, index + 1, sum);
	}
}

// Returns the nearest to element int in vec, but only it it's less or equal.
// Returns zero if every int in vec is greater than element.
// vec must be increasingly sorted
int binary_search(vector<int> vec, int element) {
	int left = 0;
	int right = vec.size() - 1;
	int middle = right / 2;

	while(right - left > 1){
		if(vec[middle] == element) return element;
		if(vec[middle] > element) right = middle;
		if(vec[middle] < element) left = middle;

		middle = (right - left) / 2 + left;
	}

	if(vec[right] <= element) return vec[right];
	if(vec[left] > element) return 0;
	return vec[left];
}

void run_solver() {
	int budget, n;
	cin >> budget >> n;

	int half = n / 2;

	vector<int> first, second;
	first.reserve(half);
	second.reserve(n - half);			// second could be larger than first by one

	for(int i = 0; i < half; i++) {
		int donuts;
		cin >> donuts;
		first.push_back(donuts);
	}

	for(int i = 0; i < n - half; i++) {
		int donuts;
		cin >> donuts;
		second.push_back(donuts);
	}

	vector<int> firstSums = all_sums(first);
	vector<int> secondSums = all_sums(second);

	sort(secondSums.begin(), secondSums.end());

	int maxDonuts = 0;
	for(unsigned int i = 0; i < firstSums.size(); i++) {
		if (firstSums[i] == budget) {
			maxDonuts = budget;
			break;
		}
		if(firstSums[i] < budget) {
			int sum = firstSums[i] + binary_search(secondSums, budget - firstSums[i]);
			if(sum > maxDonuts)
				maxDonuts = sum;
		}
	}

	if(maxDonuts == 0)
		maxDonuts = binary_search(secondSums, budget);
	cout << maxDonuts << endl;

}