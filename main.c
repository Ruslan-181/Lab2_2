






#include <stdio.h>
#include <math.h>
#include <windows.h>

// Підінтегральна функція
double f(double x) {
    return 1.0 / (4.0 + x * x);
}

double left_rect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) sum += f(a + i * h);
    return sum * h;
}

double right_rect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 1; i <= n; i++) sum += f(a + i * h);
    return sum * h;
}

double trapezoid(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    for (int i = 1; i < n; i++) sum += f(a + i * h);
    return sum * h;
}

double simpson(double a, double b, int n) {
    if (n % 2 != 0) n++;
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += (i % 2 != 0) ? 4.0 * f(x) : 2.0 * f(x);
    }
    return sum * h / 3.0;
}

int main() {

   // Встановлюємо CP1251 для консолі
    system("chcp 1251 > nul");

    //оголошення та ініціалізування зміних та масива
    double a = 0.0;
    double b = 1.0;
    int test_n[] = {10, 100, 1000, 10000};

    printf("=================================================================\n");
    printf("                  РЕЗУЛЬТАТИ ОБЧИСЛЕНЬ                           \n");
    printf("=================================================================\n\n");

    printf("%-8s | %-12s | %-12s | %-12s | %-12s\n", "n", "Ліві", "Праві", "Трапеції", "Сімпсон");
    printf("-----------------------------------------------------------------\n");

    for (int i = 0; i < 4; i++) {
        int n = test_n[i];
        printf("%-8d | %-12.8f | %-12.8f | %-12.8f | %-12.8f\n",
               n, left_rect(a, b, n), right_rect(a, b, n), trapezoid(a, b, n), simpson(a, b, n));
    }

    double eps = 0.0001;
    printf("\n-----------------------------------------------------------------\n");
    printf("  Кількість проміжків N за умовою |I(N) - I(N+2)| <= %.4f\n", eps);
    printf("-----------------------------------------------------------------\n");

    int n_l = 2;
    while (fabs(left_rect(a, b, n_l) - left_rect(a, b, n_l + 2)) > eps) n_l += 2;
    printf("Ліві прямокутники : N = %d | I(N) = %.8f\n", n_l, left_rect(a, b, n_l));

    int n_r = 2;
    while (fabs(right_rect(a, b, n_r) - right_rect(a, b, n_r + 2)) > eps) n_r += 2;
    printf("Праві прямокутники: N = %d | I(N) = %.8f\n", n_r, right_rect(a, b, n_r));

    int n_t = 2;
    while (fabs(trapezoid(a, b, n_t) - trapezoid(a, b, n_t + 2)) > eps) n_t += 2;
    printf("Метод трапецій    : N = %d | I(N) = %.8f\n", n_t, trapezoid(a, b, n_t));

    int n_s = 2;
    while (fabs(simpson(a, b, n_s) - simpson(a, b, n_s + 2)) > eps) n_s += 2;
    printf("Метод Сімпсона    : N = %d | I(N) = %.8f\n", n_s, simpson(a, b, n_s));

    return 0;
}



