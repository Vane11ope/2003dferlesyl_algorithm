#include <stdio.h>

void quicksort(int a[], int l, int r)
{
	if (l >= r) return;
	int pivot = a[l];
	int ll = l + 1, rr = r;
	for(;;) {
		while (a[ll] < pivot && ll < rr) {
			++ll;
		}
		while (a[rr] > pivot) {
			--rr;
		}
		if (ll >= rr) break;
		int tl = a[ll];
		a[ll] = a[rr];
		a[rr] = tl;
	}
	if (ll >= rr) {
		int tr = a[rr];
		a[rr] = a[l];
		a[l] = tr;
	}
	quicksort(a, l, rr - 1);
	quicksort(a, rr + 1, r);
}

int main()
{
	int a[] = {4, 53, 55, 24, 432, 7, 2, 3};
	char s = (sizeof(a)/sizeof(a[0]));
	quicksort(a, 0, s - 1);
	for (int i = 0; i < s; ++i) {
		printf("%d\n", a[i]);
	}
	return 0;
}
