#include "algo.h"

using namespace std;

#pragma warning( push )
#pragma warning( disable : 4244 ) // possible loss of data

int compute_l(float a, float b, int prec)
{
    float number_of_points = (b - a) * pow(10, prec);
    int length = ceil(log(number_of_points) / log(2));
    return length;
}

double randsu()
{
    return rand() % 10000 / 10000.0;
}

double decode(float a, float b, int l, vector<char>::iterator  it_start, vector<char>::iterator it_end)
{

    int x_int = 0;
    double x_scaled;
    for (vector<char>::iterator it = it_start; it != it_end; it++)
    {
        x_int *= 2;
        x_int += *it;
    }

    x_scaled = x_int / (pow(2, l) - 1);


    return x_scaled * ((double)b - a) + a;


}
int l;

vector<double> decode_values(float a, float b, int n, int l, vector<char>& bits)
{
    vector<char>::iterator it_start, it_end;
    vector<double> values;

    for (int ii = 0; ii < n; ++ii)
    {
        int start = ii * l;
        int end = start + l;
        it_start = bits.begin() + start;
        it_end = bits.begin() + end;
        float x = decode(a, b, l, it_start, it_end);
        values.push_back(x);
    }
    return values;
}

vector<char> randomNeighborCandidat(vector<char> bits, int n)
{
    vector<char> r = bits;
    int rand_poz = rand() % n;
    r[rand_poz] = !r[rand_poz];
    return r;
}

double HillClimbingBest(float a, float b, int n, int prec, double (*f)(int, std::vector<double>), int t)
{
    vector<char> bits;
    vector<double> numbers;

    double value, best;

    int l = compute_l(a, b, prec);

    for (int i = 0; i <= n * l; i++)
        bits.push_back(rand() % 2);

    numbers = decode_values(a, b, n, l, bits);
    best = f(n, numbers);

    while (t)
    {
        int best_i = 0;
        for (int ii = 0; ii < bits.size(); ++ii)
        {
            bits[ii] = !bits[ii];
            numbers = decode_values(a, b, n, l, bits);
            value = f(n, numbers);
            if (value < best) {
                best = value;
                best_i = ii;
            }
            bits[ii] = !bits[ii];
        }

        bits[best_i] = !bits[best_i];

        t--;
    }
    return best;
}

double SimulatedAnnealing(float a, float b, int n, int prec, double (*f)(int, std::vector<double>), float T, float step)
{
    vector<char> vc;
    vector<double> numbers;
    int t = 0;

    double value, best;

    int l = compute_l(a, b, prec);

    for (int i = 0; i <= n * l; i++)
        vc.push_back(rand() % 2);

    numbers = decode_values(a, b, n, l, vc);
    best = f(n, numbers);

    do {
        t = 0;
        do {
            vector<char> vn = randomNeighborCandidat(vc, n * l);
            numbers = decode_values(a, b, n, l, vn);
            value = f(n, numbers);
            if (value < best)
            {
                vc = vn;
                best = value;
            }
            else if (randsu() < exp((best - value) / T))
            {
                vc = vn;
                best = value;
            }
            t++;
        } while (t < 1000);
        T *= step;
    } while (T > 0.00001);


    return best;
}

double HillClimbingFirst(float a, float b, int n, int prec, double (*f)(int, std::vector<double>), int t)
{
    vector<char> bits;
    vector<double> numbers;

    double value, best;

    int l = compute_l(a, b, prec);

    for (int i = 0; i <= n * l; i++)
        bits.push_back(rand() % 2);

    numbers = decode_values(a, b, n, l, bits);
    best = f(n, numbers);

    while (t)
    {
        for (int ii = 0; ii < bits.size(); ++ii)
        {
            bits[ii] = !bits[ii];
            numbers = decode_values(a, b, n, l, bits);
            value = f(n, numbers);
            if (value < best) {
                best = value;
                break;
            }
            bits[ii] = !bits[ii];
        }
        t--;
    }
    return best;
}

#pragma warning( push )