#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

double F(double x) {
    return exp(x)-2*(x-1)*(x-1);
}

double FindRoot(double (*f)(double), double a, double b, double accyracy) {
    double c;
    while ((b - a) / 2 > accyracy) {
        c = (a + b) / 2;
        if ((f(a) * f(c)) > 0) a = c;
        else b = c;
    }
    return c;
}

int main() {
    setlocale(LC_ALL, "RUS");
    double a, b, accyracy, x;
    cout << "Интервал: ";
    cin >> a;
    cin >> b;
    if (F(a) * F(b) > 0) {
        cout << "Неверный интервал!\n";
        return 0;
    }
    cout << "Погрешность: ";
    cin >> accyracy;
    x = FindRoot(F, a, b, accyracy);
    cout << "x = " << x << endl;
    return 0;
}