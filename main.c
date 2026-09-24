






#include <stdio.h>
#include <math.h>

// Підінтегральна функція
double f(double x) {
    return 1.0 / (4.0 + x * x);
}

// Метод лівих прямокутників
double left_rect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

// Метод правих прямокутників
double right_rect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

// Метод трапецій
double trapezoid(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

// Метод парабол (Сімпсона)
double simpson(double a, double b, int n) {
    if (n % 2 != 0) n++;
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 != 0) {
            sum += 4.0 * f(x);
        } else {
            sum += 2.0 * f(x);
        }
    }
    return sum * h / 3.0;
}

int main() {



    system("chcp 1251 > nul");
    //Оголошення та ініціалізування змінних та масива

    double a = 0.0;
    double b = 1.0;
    int test_n[] = {10, 100, 1000, 10000};

    // Обчислення для різних n
    printf("=== Обчислення за 4 методами ===\n");
    for (int i = 0; i < 4; i++) {
        int n = test_n[i];
        printf("n = %-5d | L = %.8f | R = %.8f | T = %.8f | S = %.8f\n",
               n, left_rect(a, b, n), right_rect(a, b, n), trapezoid(a, b, n), simpson(a, b, n));
    }

    // Пошук N для похибки eps = 0.0001
    double eps = 0.0001;
    printf("\n=== Пошук N за похибкою eps = %.4f ===\n", eps);

    int n_l = 2;
    while (fabs(left_rect(a, b, n_l) - left_rect(a, b, n_l + 2)) > eps) {
        n_l += 2;
    }
    printf("Ліві прямокутники : N = %d\n", n_l);

    int n_r = 2;
    while (fabs(right_rect(a, b, n_r) - right_rect(a, b, n_r + 2)) > eps) {
        n_r += 2;
    }
    printf("Праві прямокутники: N = %d\n", n_r);

    int n_t = 2;
    while (fabs(trapezoid(a, b, n_t) - trapezoid(a, b, n_t + 2)) > eps) {
        n_t += 2;
    }
    printf("Метод трапецій    : N = %d\n", n_t);

    int n_s = 2;
    while (fabs(simpson(a, b, n_s) - simpson(a, b, n_s + 2)) > eps) {
        n_s += 2;
    }
    printf("Метод Сімпсона    : N = %d\n", n_s);

    return 0;
}





