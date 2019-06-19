#include <stdbool.h>
#include <stdio.h>

int n;
int k;
int A[100000];

bool ok(int x) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += A[i] / x;
	}
	return sum >= k;
}

int main() {
	int i, lb, ub;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	lb = 1, ub = 1e9 + 1;
	while (ub - lb > 1) {
		int mid = (ub + lb) / 2;
		if (ok(mid)) {
			lb = mid;
		} else {
			ub = mid;
		}
	}
	if (!ok(lb)) {
		lb = 0;
	}
	printf("%d\n", lb);
	return 0;
}
