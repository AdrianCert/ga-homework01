#include <iostream>
#include <fstream>
#include <vector>
#include <chrono> 
#include <ctime> 
#include "functions.h"
#include "algo.h"
#include "rec.h"
using namespace std;

int main(int argc, char** argv)
{
    srand((unsigned)time(0));

    float a, b;
    int n, prec, fid, opf;
    char rez_path[250];
    
    int esantion = 30;
    record rec;
    int_arg(n, "Enter dimension: ", 1);
    int_arg(prec, "Enter precizion: ", 2);
    int_arg(fid, "Enter function id: ", 3);
    int_arg(opf, "Enter search methods: ", 4);
    str_arg(rez_path, "Enter path to store rezult:", 5);

    double (*function)(int, std::vector<double>);
    switch (fid)
    {
        case 1:
            function = jong1;
            a = (float)-5.12;
            b = (float)5.12;
            break;
        case 2:
            function = schwefel;
            a = (float)-500;
            b = (float)500;
            break;
        case 3:
            function = rastrigin;
            a = (float)-5.12;
            b = (float)5.12;
            break;
        case 4:
        default:
            function = michalewicz;
            a = (float)0;
            b = (float)pi;
            break;
    }

    switch (opf)
    {
        case 1:
            for (int i = 0; i < esantion; i++) {
                auto tik = chrono::system_clock::now();
                double val = HillClimbingFirst(a, b, n, prec, function);
                auto tak = chrono::system_clock::now();
                rec.add(val, tak - tik);
                cout << "HC[" << i + 1 << "] = " << val << endl;
            }
            break;
        case 2:
            for (int i = 0; i < esantion; i++) {
                auto tik = chrono::system_clock::now();
                double val = HillClimbingBest(a, b, n, prec, function);
                auto tak = chrono::system_clock::now();
                rec.add(val, tak - tik);
                cout << "HCB[" << i + 1 << "] = " << val << endl;
            }
            break;
        default:
            for (int i = 0; i < esantion; i++) {
                auto tik = chrono::system_clock::now();
                double val = SimulatedAnnealing(a, b, n, prec, function);
                auto tak = chrono::system_clock::now();
                rec.add(val, tak - tik);
                cout << "SA[" << i + 1 << "] = " << val << endl;
            }
            break;
    }

    std::ofstream f;
    f.open(rez_path, std::ios_base::app);

    f << "-----------------------------------" << std::endl;
    f << "Config:" << endl;
    f << "\tRun:"<< argv[0] << endl;
    f << "\tDimension:\t"<< n << endl;
    f << "\tPrecizion:\t"<< prec << endl;
    f << "\tFunction:\t"<< fid << endl;
    f << "\tMethod:\t"<< opf << endl;

    f.close();

    rec.save(rez_path);
    
	return 0;
}
