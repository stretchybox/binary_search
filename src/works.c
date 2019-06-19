#include <stdbool.h>
#include <stdio.h>

int n;
int k;
int A[100000];

bool ok(int x) {
	int cnt = 1;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] > x) {
			return false;
		}
		if (sum + A[i] > x) {
			sum = A[i];
			cnt++;
		} else {
			sum += A[i];
		}
	}
	return cnt <= k;
}

int main() {
	int i, lb, ub;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	lb = 0;
	ub = 1e9;
	while (ub - lb > 1) {
		int mid = (ub + lb) / 2;
		if (ok(mid)) {
			ub = mid;
		} else {
			lb = mid;
		}
	}
	printf("%d\n", ub);
	return 0;
}
