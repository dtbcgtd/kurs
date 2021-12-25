#include <fstream>
#include "fft.h"
using namespace std;

int main()
{
    unsigned long long a, b, res;
    vector<int> a1, b1, res1;
    
    fstream f1("C:\\Users\\n\\Desktop\\fft.txt", ios::in |  ios::out | ios::app);
    if (!f1.is_open()) cout << "Fopen error!" << endl;
    f1 >> a >> b;
    cout << "A is: " << a << " B is: " << b << endl;
    
    a1 = array_(a);
    b1 = array_(b);
    
    multiply(a1, b1,res1);
    
    res = number_(res1);
    cout << res;
    f1.clear();
    f1 << " " << res;
    f1.close();
    return 0;
}