#include<cmath>
#include<iostream>
#include "hamming.h"
#define lli long long int

// Default Constructor
Hamming::Hamming() {
    i = 0, j = 0, k = 0;
}

// Parameter Constructor
Hamming::Hamming(lli _i, lli _j, lli _k) {
    i = _i, j = _j, k = _k;
}

// Equals Comparator
bool Hamming::operator == (const Hamming &b) const {
    return ((i == b.i) && (j == b.j) && (k == b.k));
}

// Less than Comparator for sorting
bool Hamming::operator < (const Hamming &b) const {
    // Calculate GCD to subtract from i, j, k
    lli c2, c3, c5;
    c2 = std::min(i, b.i);
    c3 = std::min(j, b.j);
    c5 = std::min(k, b.k);

    // Calculate logarithms of the hamming numbers and compare
    // The logarithms are small enough to fit within double data type
    double loga, logb;
    loga = (std::log(2) * (i - c2)) + (std::log(3) * (j - c3)) + (std::log(5) * (k - c5));
    logb = (std::log(2) * (b.i - c2)) + (std::log(3) * (b.j - c3)) + (std::log(5) * (b.k - c5));

    if(loga < logb) return true;
    else return false;
}

// Multiplication for Hamming Numbers with integers
Hamming Hamming::operator * (int x) {
    if(x == 2) return Hamming(i + 1, j, k);
    if(x == 3) return Hamming(i, j + 1, k);
    if(x == 5) return Hamming(i, j, k + 1);
}

// Cout print function
std::ostream& operator << (std::ostream &os, const Hamming &a) {
    os << "(" << a.i << ", " << a.j << ", " << a.k << ")";
    return os;
}
