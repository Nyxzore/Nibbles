//Here I was trying to see if I could perform 2*x and 4*x quicker. Where x is a double
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cmath>

using namespace std;

union doublebits {
    double d;
    long long IEE;
};

double sneaky_bit(double& x, int s){
    doublebits b;
    b.d = x;
    b.IEE += static_cast<long long>(s) << 52;
    return b.d;
}
int main() {
    int length = 10000000;
    vector<double> data(length); vector<double> data1(length); vector<double> data2(length);
    mt19937_64 gen(42);
    uniform_real_distribution<double> dis(1.0, 1000.0);

    for (int i = 0; i < length; ++i) data[i] = dis(gen);
    for (int i = 0; i < length; ++i) data1[i] = dis(gen);
    for (int i = 0; i < length; ++i) data2[i] = dis(gen);

    int s = 2;
    double z = 4.0;
    
    // --- TEST 1: Standard Multiplication ---
    double sum1 = 0;
    auto start1 = chrono::steady_clock::now();
    for (int i = 0; i < length; ++i) {
        sum1 += data[i] * z;
    }
    auto end1 = chrono::steady_clock::now();

    // --- TEST 2: Sneaky Bit Shift (Union) ---
    double sum2 = 0;
    auto start2 = chrono::steady_clock::now();
    for (int i = 0; i < length; ++i) {
        sum2 += sneaky_bit(data1[i], s);
    }
    auto end2 = chrono::steady_clock::now();

    cout << "Standard Time:     " << chrono::duration<double>(end1 - start1).count() << "s" << endl;
    cout << "Sneaky Shift Time: " << chrono::duration<double>(end2 - start2).count() << "s" << endl;
    cout << "Ratio:    " << chrono::duration<double>(end1 - start1).count()/chrono::duration<double>(end2 - start2).count() *100 << endl;
    
    cout << "\nResults Check:" << endl;
    cout << "Sum 1: " << sum1 << endl;
    cout << "Sum 2: " << sum2 << endl;

    return 0;
}