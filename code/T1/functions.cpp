#include "functions.h"

using namespace std;

double jong1(int n, std::vector<double> x)
{
    double s = 0.0;

    for (auto i : x)
        s += i * i;

    return s;
}

double schwefel(int n, std::vector<double> x)
{
    double s = 0.0;

    for (auto i : x)
        s += -i * sin( sqrt( abs(i)));

    return s;
}

double rastrigin(int n, std::vector<double> x)
{
    double s = 10.0 * n;

    for (auto i : x)
        s += i * i - 10 * cos( 2 * pi * i );

    return s;
}

double michalewicz(int n, std::vector<double> x)
{
    int m = 10;
    double s = 0.0;
    int step = 1;

    for (auto i : x)
        s -= sin(i) * pow(sin(i * i * step++ / pi), (double)m * 2);

    return s;
}