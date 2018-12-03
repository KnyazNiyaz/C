#include <stdio.h>
#include <cs50.h>

int main() {
    int height;

    do {
        printf("Height:");
        height = get_int();
    }
    while(height > 23 || height < 0);

    for (int line = 0; line < height; line++) {
        for (int spaces = height - line; spaces > 1; spaces--) {
            printf(" ");
        }

        for (int hashes = 0; hashes < line + 2; hashes++) {
            printf("#");
        }
        printf("\n");
    }

    return 0;

}