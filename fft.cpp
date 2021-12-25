#include "fft.h"
#include <list>
typedef complex<double> base;
const double PI = 3.14159265358979323846;

int reverse(int num, int lg_n) {
	int res = 0;
	for (int i = 0; i < lg_n; i++) {
		if (num & (1 << i))
			res |= 1 << (lg_n - 1 - i);
	}
	return res;
}

void fft(vector<base>& a, bool invert) {
	int n = (int)a.size();
	int lg_n = 0;
	while ((1 << lg_n) < n)  ++lg_n;

	for (int i = 0; i < n; ++i)
		if (i < reverse(i, lg_n))
			swap(a[i], a[reverse(i, lg_n)]);

	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * 3.14 / len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i = 0; i < n; i += len) {
			base w(1);
			for (int j = 0; j < len / 2; ++j) {
				base u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i = 0; i < n; ++i)
			a[i] /= n;
	
}

void multiply(const vector<int>& a, const vector<int>& b, vector<int>& res) {
	vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	size_t n = 1;
	while (n < max(a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize(n), fb.resize(n);

	fft(fa, false), fft(fb, false);
	for (size_t i = 0; i < n; ++i)
		fa[i] *= fb[i];
	fft(fa, true);

	n = a.size() + b.size() - 1 ;

	res.resize(n);
	for (size_t i = 0; i < n; ++i)
		res[i] = (long long)(fa[i].real() + 0.5);
}


vector<int> array_(unsigned long long n) {
	list<int> list;
	while (n > 0) {
		list.push_front(n % 2);
		n = n / 2;
	}
	vector<int> result(list.begin(), list.end());
	return result;
}

unsigned long long number_(vector<int> vec) {
	unsigned long long a = 0;
	int b = vec.size();
	for (int i = 0; i < b; i++) {
		a += vec[b-i-1] * pow(2,i);
	}
	return a;
}
