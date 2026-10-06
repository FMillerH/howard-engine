#ifndef H03_01_PRIMES_H
#define H03_01_PRIMES_H
#include <vector>

extern std::vector<int> primes;

inline double getVectorLength(int p, int q, double f) { //q == p+1
    int diff = q - p;

    double length = sqrt(diff*diff + f*f);

    return length;
}

#endif //H03_01_PRIMES_H
