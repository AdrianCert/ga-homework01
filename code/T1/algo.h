#include "const.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#pragma once

double HillClimbingFirst(float a, float b, int n, int prec, double (*f)(int, std::vector<double>), int t = 10000);
double HillClimbingBest(float a, float b, int n, int prec, double (*f)(int, std::vector<double>), int t = 10000);
double SimulatedAnnealing(float a, float b, int n, int prec, double (*f)(int, std::vector<double>), float T = 200, float step = 0.95);