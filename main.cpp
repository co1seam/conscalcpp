#include <iostream>
#include <array>
#include <cmath>

using namespace std;

double Y(double, double, double, double);

double Radical(double, double, double, double, double, double);

int main()
{
    double a, b, c = 0;     // Коэффициенты квадратного уравнения
    double fa, fb, fc;      // Функции
    double x1, x2;          // Корни уравнения
    double eps = 0.000001;  // Точность вычесления корня

    std::array<double, 400> y;
    std::array<double, 400> x;
    double startX = -100;

    std::cout << "Пожалуйста, введите коэффициенты квадратного уравнения ax^2 + bx + c = 0:" << std::endl;
    std::cout << "Введите a:" << std::endl;
    std::cin >> a;
    std::cout << "Введите b:" << std::endl;
    std::cin >> b;
    std::cout << "Введите c:" << std::endl;
    std::cin >> c;

    for(int i = 0; i < 400; i++)
    {
        y[i] = Y(startX, a, b, c);
        x[i] = startX;
        startX += 0.5;
    }

    double D = b * b - 4 * a * c;

    if(D > 0)
    {
        std::cout << "Есть два корня!" << std::endl;
    }

    else if(D == 0)
    {
        std::cout << "Есть один корень" << std::endl;
    }

    else
    {
        std::cout << "Корней нет" << std::endl;
    }

    for(int i = 0; i < y.size() - 1; i++)
    {
        if (std::signbit(y[i]) != std::signbit(y[i + 1]))
        {
            std::cout << "Тут будет корень!!! Между х1:" << x[i] << " и х2:" << x[i + 1] << std::endl;
            std::cout << "Получен корень: " << Radical(x[i], x[i+1], eps, a, b, c) << std::endl;
        }
        if (y[i] == 0)
        {
            std::cout << "Попали прям в корень, в точке:" << i << std::endl;
        }
    }
}

double Radical(double _x1, double _x2, double _eps, double _a, double _b, double _c)
{
    double x = std::numeric_limits<double>::max();
    while (std::abs(_x2 - _x1) > _eps)
    {
        x = (_x1 + _x2) / 2;
        double f = _a * std::pow(x, 2) + _b * x + _c;
        if (f * (_a * std::pow(_x1, 2) + _b * _x1 + _c) < 0)
        {
            _x2 = x;
        }
        else
        {
            _x1 = x;
        }
    }
    return x;
}

double Y(double _x, double _a, double _b, double _c)
{
    return _a * _x * _x + _b * _x + _c;
}
