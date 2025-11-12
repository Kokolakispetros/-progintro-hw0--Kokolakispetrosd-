#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long long int aliquot(long long num) {
    if (num <= 1) return 0;

    long long sum = 1;
    long long sq = sqrt(num);

    for (long long int i = 2; i <= sq; i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i)
                sum += num / i;
        }
    }
    return sum;
}

int main() {
    long long num = 0;
    printf("Please give the number to start the aliquot sequence from:\n");
    if (scanf("%lld", &num) != 1) {
        printf("Scanf failed!\n");
        return 1;
    }

    long long user_length = 0;
    printf("Provide the max aliquot length to look for (0 for unlimited):\n");
    if (scanf("%lld", &user_length) != 1) {
        printf("Scanf failed!\n");
        return 1;
    }

    char mode = 'W';
    printf("Do you want to print the full sequence ('f') or just the length ('l')? ");
    if (scanf(" %c", &mode) != 1) {
        printf("Scanf failed!\n");
        return 1;
    }

    if (mode != 'l' && mode != 'f') {
        printf("Invalid character choice!\n");
        return 1;
    }

    long long real_length = 0;
    long long result = num;
    int unlimited = (user_length == 0);

    if (mode == 'f')
        printf("%lld\n", result);

    int i = 0;
    while (unlimited || i < user_length) {
        long long temp = result;
        result = aliquot(result);

        if (mode == 'f')
            printf("%lld\n", result);
        else
            real_length++;

        if (result == 0 || result == temp)
            break;

        i++;
    }

    if (mode == 'l')
        printf("Length of aliquot sequence: %lld\n", real_length);

    return 0;
}
