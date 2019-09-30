#include "pch.h"
#include <conio.h>
#include<stdio.h>

int main() {
	int a[100], arr[100], n, i, d, swap;

	printf("Enter number of elements in the array:\n");
	scanf_s("%d", &n);

	printf("Enter %d integers\n", n);

	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);

	merge_sort(0, n - 1, a, arr);

	printf("Printing the sorted array:\n");

	for (i = 0; i < n; i++)
		printf("%d\n", a[i]);

	return 0;
}


// function to sort the subsection a[i .. j] of the array a[]
int merge_sort(int i, int j, int a[], int arr[]) {
	if (j <= i) {
		return;     // the subsection is empty or a single element
	}
	int mid = (i + j) / 2;

	// left sub-array is a[i .. mid]
	// right sub-array is a[mid + 1 .. j]

	merge_sort(i, mid, a, arr);     // sort the left sub-array recursively
	merge_sort(mid + 1, j, a, arr);     // sort the right sub-array recursively

	int pointer_left = i;       // pointer_left points to the beginning of the left sub-array
	int pointer_right = mid + 1;        // pointer_right points to the beginning of the right sub-array
	int k;      // k is the loop counter

	// we loop from i to j to fill each element of the final merged array
	for (k = i; k <= j; k++) {
		if (pointer_left == mid + 1) {      // left pointer has reached the limit
			arr[k] = a[pointer_right];
			pointer_right++;
		}
		else if (pointer_right == j + 1) {        // right pointer has reached the limit
			arr[k] = a[pointer_left];
			pointer_left++;
		}
		else if (a[pointer_left] < a[pointer_right]) {        // pointer left points to smaller element
			arr[k] = a[pointer_left];
			pointer_left++;
		}
		else {        // pointer right points to smaller element
			arr[k] = a[pointer_right];
			pointer_right++;
		}
	}

	for (k = i; k <= j; k++) {      // copy the elements from arr[] to a[]
		a[k] = arr[k];
	}
}

