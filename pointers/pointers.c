#include <stdio.h>

int main() {
	int i;

	int numbers[5] = {55,66,77,88,99};

	printf("Element \t Address \t Value \n");

	for (int i = 0; i < 5; ++i)
	{
		printf("numbers[%d] \t %p \t %d \n", i, &numbers[i], numbers[i]);
	}

	//array names are just pointers to the first element
	printf("\nnumbers \t\t %p \n", numbers);

	//dereference it
	printf("\n*numbers \t\t %d \n", *numbers);
	printf("\n(*numbers + 2) \t\t %d \n", *(numbers + 2));
}