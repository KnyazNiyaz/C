#include <stdio.h>
main () {
	float fahr, celcius;
	float upper, lower, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	while (fahr <= upper) {
		celcius = (5.0 / 9.0) * (fahr - 32);
		printf("%3.2f : %6.2f\n", fahr, celcius );
		fahr = fahr + step;
	}
}