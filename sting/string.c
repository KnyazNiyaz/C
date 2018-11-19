
int main() {
	// нельзя переопределить массив, он типа константа
	char movie1[] = "Lets play";
	// а вот указатель пожно 
	char * movie2 = "Lets play again";

	movie2 = 'Something new'

	printf("%p\n", movie2);
}