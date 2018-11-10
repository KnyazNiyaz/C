#include <stdio.h>
main () {
	int arr[4];

	arr[0] = 12;
	arr[1] = 12;
	arr[2] = 12;
	arr[3] = 12;

	int i, sum;
	sum = 0;

	for (int i = 0; i < 4; ++i)
	{
		sum = sum + arr[i];
	}

	printf("%d\n", sum);
}