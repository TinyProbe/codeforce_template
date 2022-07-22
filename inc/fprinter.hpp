/*------------------------------*
  |                              |
  |   Author : Tiny Probe        |
  |   Date   : 22-02-03          |
  |                              |
 *------------------------------*/

#ifndef FPRINTER_H
#define FPRINTER_H
#define cout fout

#include <fstream>
#include <string>
#include <algorithm>

class FilePrinter {
	std::string buffer;
	std::string target;
	std::ofstream ofs;

public:
	FilePrinter() {}
	~FilePrinter() {
		if (ofs.is_open()) {
			ofs.write(buffer.c_str(), buffer.length());
			ofs.close();
		}
	}
	FilePrinter& operator<<(const char& obj) {
		buffer += obj;
		return *this;
	}
	FilePrinter& operator<<(const short& obj) {
		buffer += std::to_string(obj);
		return *this;
	}
	FilePrinter& operator<<(const unsigned short& obj) {
		buffer += std::to_string(obj);
		return *this;
	}
	FilePrinter& operator<<(const int& obj) {
		buffer += std::to_string(obj);
		return *this;
	}
	FilePrinter& operator<<(const unsigned int& obj) {
		buffer += std::to_string(obj);
		return *this;
	}
	FilePrinter& operator<<(const long& obj) {
		buffer += std::to_string(obj);
		return *this;
	}
	FilePrinter& operator<<(const unsigned long& obj) {
		buffer += std::to_string(obj);
		return *this;
	}
	FilePrinter& operator<<(const long long& obj) {
		buffer += std::to_string(obj);
		return *this;
	}
	FilePrinter& operator<<(const unsigned long long& obj) {
		buffer += std::to_string(obj);
		return *this;
	}
	FilePrinter& operator<<(const float& obj) {
		buffer += std::to_string(obj);
		return *this;
	}
	FilePrinter& operator<<(const double& obj) {
		buffer += std::to_string(obj);
		return *this;
	}
	FilePrinter& operator<<(const std::string& obj) {
		buffer += obj;
		return *this;
	}
	const std::string& getTarget() {
		return target;
	}
	void setTarget(const std::string& tar) {
		this->target = tar;
	}
	void open() {
		if (!(ofs.is_open())) {
			ofs.open(target);
			buffer.clear();
		}
	}
	void close() {
		if (ofs.is_open()) {
			ofs.write(buffer.c_str(), buffer.length());
			ofs.close();
		}
	}
};

FilePrinter fout;
#endif
