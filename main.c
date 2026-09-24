#include <stdio.h>
#include <math.h>

// Підінтегральна функція за варіантом 1
double f(double x) {
    return 1.0 / (4.0 + x * x);
}

// Метод лівих прямокутників
double left_rect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return sum * h;
}

// Метод правих прямокутників
double right_rect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 1; i <= n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return sum * h;
}

int main() {
    system("chcp 1251 > nul");
    double a = 0.0;
    double b = 1.0;
    int test_n[] = {10, 100, 1000, 10000};

    printf("=== Тест методів прямокутників ===\n");
    printf("n         L-rect          R-rect\n");
    printf("----------------------------------\n");

    for (int i = 0; i < 4; i++) {
        int n = test_n[i];
        double res_l = left_rect(a, b, n);
        double res_r = right_rect(a, b, n);
        printf("%-8d  %-14.8f  %-14.8f\n", n, res_l, res_r);
    }

    return 0;
}
