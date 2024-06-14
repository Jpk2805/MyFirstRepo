/*
* FILE : f6.cpp
* PROJECT : PROG1000 -Focused Assignment #6
* PROGRAMMER : Jaykumar kamleshbhai patel
* FIRST VERSION : 2024-03-15
* DESCRIPTION :
* This program will get user input of floats and double them using pointers
*/
#include <stdio.h>
// Function prototypes
int getDouble(double* pNumber);
void doubleTheData(double* d1, double* d2, double* d3, double* d4);
void calculateArrayStats(double values[], int numArray, double* pSum, double* pAverage);
void fillArray(double values[], int numArray, double fillValue);
int main() {
    // Declare variables
    double vars[4];
    double average, sum;
    double array[7];

    // Prompt the user and get four floating-point numbers
    printf("Enter four floating-point numbers, one per line:\n");
    for (int i = 0; i < 4; ++i) {
        printf("Enter the Number:");
        if (!getDouble(&vars[i])) {
            printf("Invalid input. Exiting.\n");
            return 1;
        }
    }

    // Double the data
    doubleTheData(&vars[0], &vars[1], &vars[2], &vars[3]);

    // Display new values after doubling
    printf("After doubling the numbers the new values are: %lf, %lf, %lf, %lf\n", vars[0], vars[1], vars[2], vars[3]);

    // Prompt the user and fill in the array values
    printf("Enter seven floating-point numbers for the array, one per line:\n");
    
    for (int i = 0; i < 7; ++i) {
        printf("Enter the Number:");
        if (!getDouble(&array[i])) {
            printf("Invalid input. Exiting.\n");
            return 1;
        }
    }

    // Calculate array statistics
    calculateArrayStats(array, 7, &sum, &average);

    // Display average and sum
    printf("The average and sum of the array elements: %lf, %lf\n", average, sum);

    // Fill array with value 40
    fillArray(array, 7, 40);

    // Display array elements
    printf("Array elements after filling with 40: ");
    for (int i = 0; i < 6; ++i) {
        printf("%lf, ", array[i]);
    }
    printf("%lf\n", array[6]);

    return 0;
}


// Function to get a double from the user
int getDouble(double* pNumber) {
    if (scanf_s("%lf", pNumber) == 1) {
        return 1;
    }
    else {
        return 0;
    }
}


// Function to double the data
void doubleTheData(double* d1, double* d2, double* d3, double* d4) {
    *d1 *= 2;
    *d2 *= 2;
    *d3 *= 2;
    *d4 *= 2;
}

// Function to calculate array statistics
void calculateArrayStats(double values[], int numArray, double* pSum, double* pAverage) {
    *pSum = 0;
    for (int i = 0; i < numArray; ++i) {
        *pSum += values[i];
    }
    *pAverage = *pSum / numArray;
}

// Function to fill array with a specific value
void fillArray(double values[], int numArray, double fillValue) {
    for (int i = 0; i < numArray; ++i) {
        values[i] = fillValue;
    }
}
