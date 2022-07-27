#include <bits/stdc++.h>
#include "inc/fscanner.hpp"
using namespace std;

template <class T = string> T           scan();
template <class T = string> vector<T>   scan_vector(const int&);
template <class T = string> void        print(const T& = T(), const string& = "\n");
template <class T>          void        print_vector(const vector<T>&, const string& = " ");

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

int	main(void) {
	auto tmp = string();
	auto out1 = vector<string>();
	auto out2 = vector<string>();

	cin.setTarget("..\\out1.txt");
	cin.open();
	while (cin.getLine(tmp)) { out1.push_back(tmp); }
	cin.close();

	cin.setTarget("..\\out2.txt");
	cin.open();
	while (cin.getLine(tmp)) { out2.push_back(tmp); }
	cin.close();

	cin.setTarget("..\\in.txt");
	cin.open();
	auto iscor = true;
	auto tc = (0 ? 1 : scan<int>());
	for (int i = 0; i < tc; ++i) {
		auto n = scan<int>();
		auto a = scan_vector<int>(n);
		if (out1[i] != out2[i]) {
			if (iscor) {
				print("Unaccepted!", "\n\n");
				iscor = false;
			}
			print(to_string(i + 1) + " / " + to_string(tc));
			print("[Input]");
			print(n);
			print_vector(a);
			print("[Output]");
			print("sol1's", " : ");
			print(out1[i]);
			print("sol2's", " : ");
			print(out2[i], "\n\n");
		}
	}
	if (iscor) { print("Accepted!"); }
	cin.close();
}
