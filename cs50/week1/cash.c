#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main() {
    float input;
    int res = 0;
    int coins = 0;
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;

    do {
        input = get_float("Change owed: ");
    }
    while(input <= 0);

    int cents = round(input * 100);

    while(cents > quarters) {
        cents -= quarters;
        coins++;
    }

    while(cents > dimes) {
        cents -= dimes;
        coins++;
    }

    while(cents > nickels) {
        cents -= nickels;
        coins++;
    }

    while(cents >= pennies) {
        cents -= pennies;
        coins++;
    }

    printf("%d", coins);
    return 0;
}