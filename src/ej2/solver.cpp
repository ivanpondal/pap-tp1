#include "./ej2.h"

/*
**  Exercise 2
**  Problem solver
*/

using namespace std;

int calculate(int N, vector< vector<int> > &diversion, vector<int> &dp, int mask) {
	if (dp[mask] != -1)
		return dp[mask];
	int res = 0;
	//Solution including everyone in this set
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if ((mask & ((1<<i) | (1<<j))) == ((1<<i) | (1<<j)))
				res += diversion[i][j];
		}
	}
	//Solution including no-one
	res = max(res, 0);
	//Solutions for proper subsets of this set
	for (int s1 = mask&(mask-1); s1 != 0; s1 = mask&(s1-1)) {
		int s2 = mask & (~s1); // (s1 | s2) == mask
		int c1 = calculate(N, diversion, dp, s1);
		int c2 = calculate(N, diversion, dp, s2);
		res = max(res, c1+c2);
	}
	//Save solution for this set and return
	dp[mask] = res;
	return res;
}

void run_solver() {
	//Data Input
	int N;
	cin >> N;
	vector< vector<int> > diversion = vector< vector<int> >(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> diversion [i][j];
		}
	}
	//Dynamic programming solutions
	vector<int> dp = vector<int>((1<<N), -1);
	dp[0] = 0;
	//Main solver
	calculate(N, diversion, dp, (1<<N)-1);
	//Output
	cout << dp[(1<<N)-1] << endl;
}
