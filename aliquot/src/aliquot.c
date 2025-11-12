```c
#include <stdlib.h>
#include <stdio.h> 
#include <math.h>

// Function to calculate s(x) 
long long int aliquot(long long num) {
    long long sum = 0;
    
    for(long long int i=1; i*i<=num; i++) {
        if(num % i == 0)
            sum = sum + i + num/i;            
    }
    return sum;
}

// Driver code
int main() {


    long long num = 0;
    // Get number from stdin
    printf("Please give the number to start the aliquot sequence from:\n");
    if(scanf("%lld", &num) != 1){
        printf("Scanf failed!\n");
        return 1;
    }

    long long user_length = 0;
    // Get length from stdin
    printf("Provide the max aliquot length to look for (0 for unlimited):\n");
    if(scanf("%lld", &user_length) != 1) {
        printf("Scanf failed!\n");
        return 1;
    }
    
    char mode = 'W';
    // Get mode from stdin
    printf("Do you want to print the full sequence ('f') or just the length ('l')? ");
    
    if(scanf(" %c", &mode) != 1) {
        printf("Scanf failed!\n");
        return 1;
    }

    // Check for invalid user input
    if(mode != 'l' && mode != 'f') {
        printf("Invalid character choice!\n");
        return 1;
    }

    long long real_length = 0; 

   
    


    long long result = num; 

    int unlimited = 0;

    // Check for infinite sequence or not 
    if(user_length == 0){
        unlimited = 1;
        user_length = 1;
    }

    int i = 0;    
    // Call aliquot on itself user_length times
    if(mode == 'f')
        printf("%lld\n", result);
    
    while(i<user_length) {
        result = aliquot(result);
        //printf("Aliquot of %lld is %lld", temp, result);
        if(mode == 'f')
            printf("%lld\n", result);
        else
            real_length++;
        // Check for terminal condition
        if(result == 0)
            break;
        
        // Check for infinite sequence or not
        if(unlimited == 0)
            i++;
    }

    if(mode == 'l') 
        printf("Length of aliquot sequence: %lld\n", real_length);
       

    return 0;
}
```
