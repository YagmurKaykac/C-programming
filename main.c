# 


#include <stdio.h>
#include <string.h>

//  we made this function to extract the digits 
void extract_digits(const char *input, int digits[2][10], int *whole_count, int *frac_count) {
    char whole_part[11] = {0}, frac_part[11] = {0}; // here we seperate the whole and fractional parts 

    //ın here we will split input into 2 parts 1- whole 2- fractional parts
    sscanf(input, "%10[^.].%10s", whole_part, frac_part);

    // now we will extract the whole part digits
    *whole_count = strlen(whole_part);
    for (int i = 0; i < *whole_count; i++) {
        digits[0][i] = whole_part[i] - '0'; // Convert character to integer
    }

    // here we extract the fractional part digits
    *frac_count = strlen(frac_part);
    for (int i = 0; i < *frac_count; i++) {
        digits[1][i] = frac_part[i] - '0'; // Convert character to integer
    }

    // remove the zeros from end of fractional part 
    while (*frac_count > 0 && digits[1][*frac_count - 1] == 0) {
        (*frac_count)--;
    }
}

int main() {
    char input[22]; 
    int digits[2][10] = {0}; // this is the 2d array that will store the complete and fractional part 
    int whole_count = 0, frac_count = 0;

    printf("give a floating-point number: ");
    scanf("%21s", input);

    // Extract digits and counts
    extract_digits(input, digits, &whole_count, &frac_count);

    // Print the results
    printf("%s has a whole part of %d digits and a fractional part of %d digits.\n", input, whole_count, frac_count);

    printf("Whole part digits: ");
    for (int i = 0; i < whole_count; i++) {
        printf("%d ", *(digits[0] + i)); 
    }
    printf("\n");

    printf("Fractional part digits: ");
    for (int i = 0; i < frac_count; i++) {
        printf("%d ", *(digits[1] + i)); 
    }
    printf("\n");
    return 0;
}
