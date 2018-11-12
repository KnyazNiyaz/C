#include<stdio.h>
#include<string.h>
 
int main() {

	char *p_char_arr;
	char str_arr[] = "Niiaz";
	p_char_arr = str_arr;
	for (int i = 0 ; i < strlen(str_arr) ; ++i) {
		fprintf(stdout, "Char: %c, point: %p\n", *p_char_arr, p_char_arr);
		*p_char_arr++;
	}
}
