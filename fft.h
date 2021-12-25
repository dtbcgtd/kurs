#ifndef FFT
#define FFT
#include <complex>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

typedef complex<double> base;
vector<int> array_(unsigned long long a);
unsigned long long number_(vector<int> vec);
void fft(vector<base>& a, bool invert);
void multiply(const vector<int>& a, const vector<int>& b, vector<int>& res);
#endif