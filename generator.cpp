#include <bits/stdc++.h>
#include "inc/fprinter.hpp"
using namespace std;

template <class T>          T           _rand(const T& = T(1), const T& = T(100));
template <class T = string> T           scan();
template <class T = string> vector<T>   scan_vector(const int&);
template <class T = string> void        print(const T& = T(), const string& = "\n");
template <class T>          void        print_vector(const vector<T>&, const string& = " ");

template <class T> T _rand(const T& mn, const T& mx) {
	static mt19937 gnt((random_device())());
	return (uniform_int_distribution<T>(mn, mx))(gnt);
}
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

int main(void) {
	auto minmax = vector<int>({ 0, 0, 0, 0, 0, 0 });
	auto tc = 0;
	auto n = 0;
	auto a = 0;

	cout.setTarget("..\\in.txt");
	cout.open();
	tc = _rand(minmax[0], minmax[1]);
	print(tc);
	for (int i = 0; i < tc; ++i) {
		n = _rand(minmax[2], minmax[3]);
		print(n);
		for (int j = 0; j < n; ++j) {
			a = _rand(minmax[4], minmax[5]);
			print(a, " ");
		}
		print();
	}
	cout.close();
}
