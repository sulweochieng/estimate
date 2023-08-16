#include <stdio.h>

void find_ratios_with_sum_n(int n) {
    for (int a = 1; a <= n - 2; a++) {
        for (int b = 1; b <= n - a - 1; b++) {
            int c = n - a - b;
            if (c > 0) {
                printf("Ratio: %d:%d:%d\n", a, b, c);
            }
        }
    }
}

int main() {
    int n;
    
    printf("Please enter a number\n");
    scanf("%d", &n);
    printf("Ratios with sum %d:\n", n);
    find_ratios_with_sum_n(n);
    return 0;
}

