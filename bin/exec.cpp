#include <bits/stdc++.h>
using namespace std;

int main(void) {
	system("./cvt ../sol1.cpp ../in.txt ../out1.txt");
	system("./cvt ../sol2.cpp ../in.txt ../out2.txt");
	system("./g__ ../generator.cpp ../cvt_sol1.cpp ../cvt_sol2.cpp ../detector.cpp");
	system("../generator");
	system("../cvt_sol1");
	system("../cvt_sol2");
	system("../detector");
	system("rm -rf ../cvt_*");
	system("rm -rf ../generator");
	system("rm -rf ../detector");
	system("rm -rf ../in.txt");
	system("rm -rf ../out1.txt");
	system("rm -rf ../out2.txt");
}
