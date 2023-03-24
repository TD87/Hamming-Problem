# Hamming Problem
Generate the Nth Hamming Number. A hamming number is a number of the form 2^i*3^j*5^k where i, j and k are non-negative integers.

## Files

 - `ver1.cpp:` Contains C++ code for version 1 of Hamming problem (N = O(10^4))
 - `ver2.cpp:` Contains C++ code for version 2 of Hamming problem (N = O(10^8)). Essentially the same as `ver1.cpp` but it utilizes the Triplet representation for Hamming numbers from `hamming.cpp`
 - `ver3.cpp:` Contains C++ code for version 3 of Hamming problem (N = O(10^12)).
 - `hamming.cpp:` Contains the C++ code for the Triplet representation used in the second and third subproblems
 - `hamming.h:` Header file for `hamming.cpp`
 - `Report.pdf:` Contains the explanations on the process, proof and performance of the code

## Instructions

 - `g++ ver1.cpp -o ver1` compiles the code for version 1
 - `g++ ver2.cpp hamming.cpp -o ver2` compiles the code for version 2
 - `g++ ver3.cpp hamming.cpp -o ver3` compiles the code for version 3
 - The number N is given as input through the command line
 - `./ver1 1500` runs version 1 with N as 1500
 - `./ver2 100000` runs version 2 with N as 100000
 - `./ver3 4000000000` runs version 3 with N as 4000000000
