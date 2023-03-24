#ifndef HAM_H
#define HAM_H
#define lli long long int

// Triplet Representation for Hamming Numbers
class Hamming {
    // Exponents of 2, 3, 5
    lli i, j, k;

    public:
        // Default Constructor
        Hamming();

        // Parameter Constructor
        Hamming(lli _i, lli _j, lli _k);

        // Equals Comparator
        bool operator == (const Hamming &b) const;

        // Less than Comparator for sorting
        bool operator < (const Hamming &b) const;

        // Multiplication for Hamming Numbers with integers
        Hamming operator * (int x);

        // Cout print function
        friend std::ostream& operator << (std::ostream &os, const Hamming &a);
};

#endif
