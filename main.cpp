#include <bits/stdc++.h>
#include <iostream>
#include <emmintrin.h>
#include <sys/time.h>
#include <chrono>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ostream> 
#include <sstream>


#define ORANGE "\033[1;33m"
#define GREEN "\033[1;32m"
#define PINK "\033[1;35m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

using namespace std;

// Search for value in an array using scalar search
int scalar_search(int value, int *array, int n) {
    for (int i = 0; i < n; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;  // Not found
}

// Search for value in an array using SIMD
int simd_search(int value, int *array, int n) {
    // The block size is 4 because we are using 32-bit integers
    const int block_size = 4;

    // assign 128 bit register with 32-bit in each element(4 elements)
    __m128i target = _mm_set1_epi32(value);
    int i = 0;

    for (; i < n - block_size; i += block_size) {
        // load 128 bit block from array
        __m128i block = _mm_loadu_si128((__m128i*)&array[i]);
        // compare 128 bit block with target
        __m128i cmp = _mm_cmpeq_epi32(block, target);
        // convert 128 bit register to 32 bit register
        int mask = _mm_movemask_ps((__m128)cmp);

        // If any of the elements in the block match, return the index
        if (mask != 0) {
            // Find the index of the first matching element (count trailing zeros)
            int j = i + __builtin_ctz(mask);
            return j;
        }
    }

    // Search the remaining elements using scalar search
    for (; i < n; i++) {
        // If the element matches, return the index
        if (array[i] == value) {
            return i;
        }
    }

    return -1;  // Not found
}

int main() {
    int n;
    cout << ORANGE;
    cout << "=========================================" << endl;
    cout << "Enter number of elements\t: ";
    cin >> n;
    cin.ignore();
    cout << RESET;

    // array of n elements
    int array[n];
    cout << GREEN;
    string line;
    getline(cin, line);

    stringstream ss(line);
    for(int i=0; i<n; i++){
        ss >> array[i];
    }
    // for(int i=0; i<n; i++){
    //     if(i < 9){
    //         cout << "Enter element " << i+1 << "\t\t\t: ";
    //     }else{
    //         cout << "Enter element " << i+1 << "\t\t: ";
    //     }
    //     cin >> array[i];
    // }
    cout << RESET;
    cout << ORANGE;
    cout << "=========================================" << endl;   
    cout << RESET;

    // value to search
    int value;
    cout << PINK;
    cout << "Enter value to search\t\t: ";
    cin >> value;
    cout << RESET;

    cout << ORANGE;
    cout << "=========================================" << endl;   
    cout << RESET;

    struct timespec start, end, start1, end1;
    // calculate time taken by scalar search
    clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false);
    int indexScalar = scalar_search(value, array, n);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken_Scalar = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken_Scalar = (time_taken_Scalar + (end.tv_nsec - start.tv_nsec)) * 1e-9;

    // calculate time taken by SIMD search
    clock_gettime(CLOCK_MONOTONIC, &start1);
    ios_base::sync_with_stdio(false);
    int indexSIMD = simd_search(value, array, n);
    clock_gettime(CLOCK_MONOTONIC, &end1);
    double time_taken_SIMD = (end1.tv_sec - start1.tv_sec) * 1e9;
    time_taken_SIMD = (time_taken_SIMD + (end1.tv_nsec - start1.tv_nsec)) * 1e-9;


    cout << CYAN;
    cout << "The result with SIMD is\t\t:" << endl;
    if (indexSIMD != -1) {
        cout << "Value " << value << " found at index " << indexSIMD << endl;
        cout << "Time taken by SIMD search\t: " << fixed << time_taken_SIMD << setprecision(9) << " seconds" << endl;
    } else {
        cout << "Value " << value << " not found" << endl;
        cout << "Time taken by SIMD search\t: " << fixed << time_taken_SIMD << setprecision(9) << " seconds" << endl;
    }
    cout << RESET;

    cout << "\n";
    cout << GREEN;
    cout << "The result with Scalar is\t:" << endl;
    if (indexScalar != -1) {
        cout << "Value " << value << " found at index " << indexScalar << endl;
        cout << "Time taken by Scalar search\t: " << fixed << time_taken_Scalar << setprecision(9) << " seconds" << endl;
    } else {
        cout << "Value " << value << " not found" << endl;
        cout << "Time taken by Scalar search\t: " << fixed << time_taken_Scalar << setprecision(9) << " seconds" << endl;
    }
    cout << RESET;

    return 0;
}