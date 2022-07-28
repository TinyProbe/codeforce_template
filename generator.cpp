#include <bits/stdc++.h>
#include "inc/fprinter.hpp"
using namespace std;

template <class T = string> T           scan();
template <class T = string> vector<T>   scan_vector(const int&);
template <class T = string> void        print(const T& = T(), const string& = "\n");
template <class T>          void        print_vector(const vector<T>&, const string& = " ");
template <class T>          T           _rand(const T& = T(1), const T& = T(100));

template <class T> T scan() {
    static T tmp;
    cin >> tmp;
    return tmp;
}
template <class T> vector<T> scan_vector(const int& n) {
    vector<T> v(n);
    for (int i = 0; i < n; ++i) { v[i] = scan<T>(); }
    return v;
}
template <class T> void print(const T& obj, const string& end) {
    cout << obj << end;
}
template <class T> void print_vector(const vector<T>& v, const string& end) {
    for (int i = 0; i < v.size(); ++i) { print(v[i], end); }
    if (end != "\n") { print(); }
}
template <class T> T _rand(const T& mn, const T& mx) {
    static mt19937 gnt((random_device())());
    return (uniform_int_distribution<T>(mn, mx))(gnt);
}

int main(void) {
    auto rng = vector<int>({ 10000, 10000, 10, 20, 'a', 'c' });

    cout.setTarget("../in.txt");
    cout.open();
    auto tc = _rand(rng[0], rng[1]);
    print(tc);
    for (int i = 0; i < tc; ++i) {
        auto n = _rand(rng[2], rng[3]);
        print(n);
        auto s1 = ""s;
        auto s2 = ""s;
        for (int j = 0; j < n; ++j) {
            s1 += _rand(rng[4], rng[5]);
            s2 += _rand(rng[4], rng[5]);
        }
        print(s1);
        print(s2);
    }
    cout.close();
}
