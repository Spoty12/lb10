
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

// Коэффициенты ряда
double a[] = {
    1.0 / 3,
    1.0 / 45,
    2.0 / 945,
    1.0 / 4725,
    2.0 / 93555,
    1382.0 / 638512875,
    4.0 / 18243225,
    3617.0 / 325641566250.0
};

// 1. Вычисление стандартной функцией
double cot_lib(double x)
{
    return 1.0 / tan(x);
}

// 2. Вычисление с заданным количеством членов
double cot_n(double x, int N)
{
    double s = 1.0 / x;
    double p = x;

    for (int i = 0; i < N && i < 8; i++)
    {
        s -= a[i] * p;
        p *= x * x;
    }

    return s;
}

// 3. Вычисление с заданной точностью
double cot_eps(double x, double eps)
{
    double s = 1.0 / x;
    double p = x;

    for (int i = 0; i < 8; i++)
    {
        double term = a[i] * p;

        s -= term;

        if (term < eps)
            break;

        p *= x * x;
    }

    return s;
}

int main()
{
    setlocale(LC_ALL, "RUS");

    double x, eps;
    int N;

    printf("Введите x (в радианах): ");
    scanf("%lf", &x);

    if (x == 0 || fabs(x) >= 3.141592653589793)
    {
        printf("Некорректное значение x!\n");
        return 0;
    }

    printf("Введите количество членов ряда N (1-8): ");
    scanf("%d", &N);

    printf("Введите точность eps: ");
    scanf("%lf", &eps);

    if (N < 1 || N > 8 || eps <= 0)
    {
        printf("Некорректные параметры!\n");
        return 0;
    }

    printf("\nРезультаты вычислений:\n");

    printf("1. Стандартная функция: %.10lf\n", cot_lib(x));

    printf("2. Сумма ряда (N): %.10lf\n", cot_n(x, N));

    printf("3. Сумма ряда (eps): %.10lf\n", cot_eps(x, eps));

    return 0;
}
