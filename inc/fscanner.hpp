/*------------------------------*
  |                              |
  |   Author : Tiny Probe        |
  |   Date   : 22-02-03          |
  |                              |
 *------------------------------*/

#ifndef FSCANNER_H
#define FSCANNER_H
#define cin fin

#include <fstream>
#include <string>
#include <algorithm>

class FileScanner {
	std::string buffer;
	std::string target;
	std::ifstream ifs;

public:
	FileScanner() {}
	~FileScanner() {
		if (ifs.is_open()) {
			ifs.close();
        }
	}
	FileScanner& operator>>(char& obj) {
		static char	tmp;
		while (!ifs.eof()) {
			ifs.get(tmp);
			if (tmp != ' ' && tmp != '\n') {
				obj = tmp;
				break ;
			}
		}
		return *this;
	}
	FileScanner& operator>>(short& obj) {
		if (fillBuffer()) {
			obj = (short)(stol(buffer));
        }
		return *this;
	}
	FileScanner& operator>>(unsigned short& obj) {
		if (fillBuffer()) {
			obj = (unsigned short)(stoul(buffer));
        }
		return *this;
	}
	FileScanner& operator>>(int& obj) {
		if (fillBuffer()) {
			obj = stoi(buffer);
        }
		return *this;
	}
	FileScanner& operator>>(unsigned int& obj) {
		if (fillBuffer()) {
			obj = (unsigned int)(stoul(buffer));
        }
		return *this;
	}
	FileScanner& operator>>(long& obj) {
		if (fillBuffer()) {
			obj = stol(buffer);
        }
		return *this;
	}
	FileScanner& operator>>(unsigned long& obj) {
		if (fillBuffer()) {
			obj = stoul(buffer);
        }
		return *this;
	}
	FileScanner& operator>>(long long& obj) {
		if (fillBuffer()) {
			obj = stoll(buffer);
        }
		return *this;
	}
	FileScanner& operator>>(unsigned long long& obj) {
		if (fillBuffer()) {
			obj = stoull(buffer);
        }
		return *this;
	}
	FileScanner& operator>>(float& obj) {
		if (fillBuffer()) {
			obj = stof(buffer);
        }
		return *this;
	}
	FileScanner& operator>>(double& obj) {
		if (fillBuffer()) {
			obj = stod(buffer);
        }
		return *this;
	}
	FileScanner& operator>>(std::string& obj) {
		if (fillBuffer()) {
			obj = buffer;
        }
		return *this;
	}
	const std::string& getTarget() {
		return this->target;
	}
	bool getLine(std::string& str) {
		if (!ifs.eof()) {
			getline(ifs, str);
			return true;
		}
		return false;
	}
	void setTarget(const std::string& tar) {
		this->target = tar;
	}
	void open() {
		if (!(ifs.is_open())) {
			ifs.open(target);
        }
	}
	void close() {
		if (ifs.is_open()) {
			ifs.close();
        }
	}

private:
	bool fillBuffer() {
		static char	tmp;
		static bool	isin;
		isin = false;
		buffer.clear();
		while (!ifs.eof()) {
			ifs.get(tmp);
			if (!((tmp >= 9 && tmp <= 13) || tmp == 32)) {
				if (!isin) {
					isin = true;
                }
				buffer += tmp;
			} else {
				if (isin) {
					break ;
                }
            }
		}
		return isin;
	}
};

FileScanner fin;
#endif
