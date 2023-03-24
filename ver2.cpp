#include<vector>
#include<iostream>
#include "hamming.h"
#define lli long long int

// Calculate minimum Hamming Number
Hamming min(Hamming a, Hamming b) {
    if(a < b) return a;
    else return b;
}

int main(int argc, char *argv[]) {
    lli N = std::atoll(argv[1]); // Command Line Input
    lli p2 = 0, p3 = 0, p5 = 0; // Pointer to element to multiply with 2, 3, 5
    std::vector<Hamming> arr; // Array to store Hamming Numbers
    arr.push_back(Hamming(0, 0, 0)); // First element

    // Generate each new Hamming number by multiplying a previous element with 2, 3 or 5
    for(lli i = 1; i < N; i++) {
        Hamming c2 = arr[p2] * 2, c3 = arr[p3] * 3, c5 = arr[p5] * 5; // Generate candidates
        arr.push_back(std::min(std::min(c2, c3), c5)); // Choose the minimum possible candidate

        // Update pointer if candidate chosen
        // Beware of duplicates: multiple paths to the same number (Ex: 2 * 5 = 10, 5 * 2 = 10)
        if(c2 == arr[i]) p2++;
        if(c3 == arr[i]) p3++;
        if(c5 == arr[i]) p5++;
    }

    // Print Nth Hamming Number
    std::cout << N << "th Hamming Number: " << arr[N-1] << std::endl;
}
