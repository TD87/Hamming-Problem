#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include "hamming.h"
#define lli long long int

int main(int argc, char *argv[]) {
    lli N = std::atoll(argv[1]); // Command Line Input
    std::vector<Hamming> arr; // Array to store Slice of Hamming Numbers

    // Estimate log value of Nth Hamming number and hi, low bounds using correction factor
    double log2 = std::log(2), log3 = std::log(3), log5 = std::log(5);
    double log_est = std::cbrt(6 * log2 * log3 * log5 * N) - std::log(std::sqrt(30));
    double hi = log_est + (1 / log_est);
    double low = log_est - (1 / log_est);

    // Enumerate the slice of all possible triples between hi and low and add to array
    lli count = 0; // Keeps track of count of Hamming Numbers below the slice
    lli k_hi = std::floor(hi / log5); // Upper bound on k
    for(lli k = 0; k <= k_hi; k++) {
        lli j_hi = std::floor((hi - (k * log5)) / log3); // Upper bound on j for this k

        for(lli j = 0; j <= j_hi; j++) {
            lli i_hi = std::floor((hi - (k * log5) - (j * log3)) / log2); // Upper bound on i for this j, k
            lli i_low = std::ceil((low - (k * log5) - (j * log3)) / log2);  // Lower bound on i for this j, k
            count += i_low; // Triplets smaller than lower bound are below the slice

            for(lli i = i_low; i <= i_hi; i++)
                arr.push_back(Hamming(i, j, k));
        }
    }

    // Sort the triples in the slice and print the Nth value
    lli i = N - count - 1;
    std::sort(arr.begin(), arr.end());
    std::cout << N << "th Hamming Number: " << arr[i] << std::endl;
}
