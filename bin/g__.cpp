#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
	if (argc <= 1)
		return (1);

	auto	path = string();
	auto	cmd = string();
	for (int i = 1; i < argc; ++i)
	{
		path = argv[i];
		while (path.back() == '/' || path.back() == '\\')
			path.pop_back();
		cmd = "g++ ";
		cmd += "-Wall -Wextra -Werror ";
		cmd += path + " ";
		cmd += "-o ";
		auto	sep1 = path.find_last_of('/');
		auto	sep2 = path.find_last_of('\\');
		auto	sep3 = size_t();
		if (sep1 != path.npos)
			sep3 = max(sep3, sep1);
		if (sep2 != path.npos)
			sep3 = max(sep3, sep2);
		if (path[sep3] == '/' || path[sep3] == '\\')
			++sep3;
		auto	file = path.substr(sep3, path.length() - sep3);
		auto	cnt = count(file.begin(), file.end(), '.');
		if (file[0] == '.')
			--cnt;
		if (cnt)
			cmd += path.substr(0, path.find_last_of('.'));
		else
			cmd += path;
		system(cmd.c_str());
	}

	return (0);
}
