
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

// Первая функция
double F1(double x)
{
    double y;

    if (x <= 3)
        y = x * x - 3 * x + 9;
    else
        y = 1.0 / (x * x * x + 3);

    return y;
}

// Вторая функция
double F2(double x)
{
    double y;

    y = x * exp(sin(x * x));

    return y;
}

int main()
{
    setlocale(LC_ALL, "RUS");

    double x, a, b;
    int choice;

    printf("Введите значение x: ");
    scanf("%lf", &x);

    a = F1(x);
    b = F2(x);

    printf("\nМеню:\n");
    printf("1. Вычислить F1(x)\n");
    printf("2. Вычислить F2(x)\n");
    printf("3. Вычислить произведение\n");
    printf("4. Вычислить разность квадратов\n");
    printf("5. Вычислить удвоенную сумму\n");

    printf("\nВыберите действие: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("F1(x) = %.6lf\n", a);
        break;

    case 2:
        printf("F2(x) = %.6lf\n", b);
        break;

    case 3:
        printf("Произведение = %.6lf\n", a * b);
        break;

    case 4:
        printf("Разность квадратов = %.6lf\n",
            a * a - b * b);
        break;

    case 5:
        printf("Удвоенная сумма = %.6lf\n",
            2 * (a + b));
        break;

    default:
        printf("Неверный пункт меню.\n");
    }

    return 0;
}
