#include <stdio.h>
#include <string.h>

// Function prototypes
void numberToWords(int n);
void convertToWords(int n);
void printSegment(int n);

// Arrays to store words for digits and numbers
const char *units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char *teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char *powers[] = {"", "thousand", "million", "billion"};

// Main driver function
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    numberToWords(number);
    return 0;
}

// Function to print a number in words
void numberToWords(int n) {
    if (n == 0) {
        printf("zero\n");
    } else if (n < 0) {
        printf("negative ");
        convertToWords(-n);
    } else {
        convertToWords(n);
    }
}

// Function to convert a number into words
void convertToWords(int n) {
    int segment, powerIndex = 0;

    while (n > 0) {
        segment = n % 1000;
        if (segment > 0) {
            printSegment(segment);
            if (powerIndex > 0) {
                printf(" %s ", powers[powerIndex]);
            }
        }
        n /= 1000;
        powerIndex++;
    }
    printf("\n");
}

// Function to print a segment (less than 1000) in words
void printSegment(int n) {
    if (n >= 100) {
        printf("%s hundred", units[n / 100]);
        n %= 100;
        if (n > 0) {
            printf(" and ");
        }
    }

    if (n >= 20) {
        printf("%s", tens[n / 10]);
        n %= 10;
        if (n > 0) {
            printf("-%s", units[n]);
        }
    } else if (n >= 11 && n <= 19) {
        printf("%s", teens[n - 10]);
    } else if (n > 0) {
        printf("%s", units[n]);
    }
}

