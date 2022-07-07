#include <bits/stdc++.h>
#include "../inc/fscanner.hpp"
#include "../inc/fprinter.hpp"
using namespace std;

int main(int argc, char** argv)
{
	if (argc < 3 || argc > 4)
		return -1;
	auto	srcfile = string();
	auto	infile = string();
	auto	outfile = string();
	srcfile = argv[1];
	infile = argv[2];
	if (argc == 4)
		outfile = argv[3];

	cin.setTarget(srcfile);
	cin.open();
	auto	bf_h = true;
	auto	bf_m = true;
	auto	tmp = string();
	auto	inside = vector<string>();
	while (cin.getLine(tmp))
	{
		if (tmp.find("cin.") != tmp.npos)
			tmp = "//" + tmp;
		else if (tmp.find("cout.") != tmp.npos)
			tmp = "//" + tmp;
		else if (tmp.find("fixed") != tmp.npos)
			tmp = "//" + tmp;
		else if (tmp.find("precision") != tmp.npos)
			tmp = "//" + tmp;
		else if (tmp.find("sync_with") != tmp.npos)
			tmp = "//" + tmp;
		else if (tmp.find("fastio") != tmp.npos)
			tmp = "//" + tmp;
		else if (tmp.find("setpre") != tmp.npos)
			tmp = "//" + tmp;
		else if (tmp.find("space std;") != tmp.npos)
			tmp = "//" + tmp;
		else
		{
			auto	pos = tmp.find("std::");
			while (pos != tmp.npos)
			{
				tmp.erase(pos, 5);
				pos = tmp.find("std::");
			}
		}
		inside.push_back(tmp);
		if (bf_h)
		{
			if (tmp.find("stdc++.h") != tmp.npos)
			{
				bf_h = false;
				inside.push_back("#include \"inc/fscanner.hpp\"");
				if (argc == 4)
					inside.push_back("#include \"inc/fprinter.hpp\"");
				inside.push_back("using namespace std;");
			}
		}
		else if (bf_m)
		{
			if (tmp.find(" main(") != tmp.npos)
			{
				if (tmp.find("{") == tmp.npos)
				{
					inside.back() += " {";
					cin.getLine(tmp);
				}
				bf_m = false;
				inside.push_back("    cin.setTarget(\"" + infile + "\");");
				inside.push_back("    cin.open();");
				if (argc == 4)
				{
					inside.push_back("    cout.setTarget(\"" + outfile + "\");");
					inside.push_back("    cout.open();");
				}
			}
		}
	}
	cin.close();

	while (srcfile.back() == '/' || srcfile.back() == '\\')
		srcfile.pop_back();
	auto	sep1 = srcfile.find_last_of('/');
	auto	sep2 = srcfile.find_last_of('\\');
	auto	sep3 = size_t();
	if (sep1 != srcfile.npos)
		sep3 = max(sep3, sep1);
	if (sep2 != srcfile.npos)
		sep3 = max(sep3, sep2);
	if (srcfile[sep3] == '/' || srcfile[sep3] == '\\')
		++sep3;
	srcfile = srcfile.substr(sep3, srcfile.length() - sep3);

	cout.setTarget("../cvt_" + srcfile);
	cout.open();
	for (int i = 0; i < (int)inside.size(); ++i)
		cout << inside[i] << '\n';
	cout.close();

	return (0);
}
