#include <stdio.h>

// Function declaration
void swap(int* x, int* y);
void value_swap(int x , int y);

int main(void) {
    int x = 5;
    int y = 4;

    printf("Before swap: x = %d, y = %d\n", x, y);
    
    
    // swap by reference 
    printf("swap by reference \n ");
    swap(&x, &y);
     printf("again show: x = %d, y = %d\n", x, y);


    // swap by value 
    printf("swap by value \n ");
    value_swap(x, y);
    printf("again show: x = %d, y = %d\n", x, y);


    return 0;
}

// Functions definition

void swap(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

    printf("afrer swap: x = %d, y = %d\n", *x, *y);
}

void value_swap(int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;

    printf("afrer swap: x = %d, y = %d\n", x, y);
}

