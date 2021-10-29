#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>   

class record {
    double sum;
    std::vector<double> rezults;
    std::vector<std::chrono::duration<double>> times;
    std::chrono::time_point<std::chrono::system_clock> start_time;
    int records;

    double get_min()
    {
        double min = rezults[0];
        for (auto i : rezults)
            if (min > i)
                min = i;
        return min;
    }

    double get_max()
    {
        double max = rezults[0];
        for (auto i : rezults)
            if (max < i)
                max = i;
        return max;
    }
public:
    record() : records(0), sum(0)
    {
        start_time = std::chrono::system_clock::now();
    }
    void add(double r, std::chrono::duration<double> el)
    {
        rezults.push_back(r);
        times.push_back(el);
        sum += r;
        records++;
    }

    void save(std::string path)
    {
        std::ofstream f;
        f.open(path , std::ios_base::app);
        std::chrono::time_point<std::chrono::system_clock> time_now = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(time_now);
        std::chrono::duration<double> exec_time = time_now - start_time;

        f << "Date:\t" << std::ctime(&end_time) << std::endl;
        f << "Duration:\t" << exec_time.count() << "s\n";
        f << "Mean:\t" << sum / records << std::endl;

        double dev = 0;
        for (auto i : rezults)
            dev += abs(sum / records - i);

        dev /= records;

        std::chrono::duration<double> meantime = (std::chrono::duration < double>)0;
        for (auto i : times)
            meantime += i;

        meantime /= records;

        f << "Deviation\t" << dev << std::endl;
        f << "Count:\t" << records << std::endl;
        f << "Max:\t" << get_max() << std::endl;
        f << "Min:\t" << get_min() << std::endl;
        f << "Mean Time:\t" << meantime.count() << " s" << std::endl;
        f << "Rec:\t\n\tvalue\ttime (s)\n";
        for (int i = 0; i < records; i++)
        {
            f << "\t" << rezults[i] << "\t" << times[i].count() << std::endl;
        }
        f << "-----------------------------------" << std::endl;

        f.close();

    }
};
