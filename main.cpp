#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include "libs/xorcrypt.h"

using namespace std;


void usage(string filename);


int main(int argc, char const *argv[]) {
	if (argc == 4) {
		crypt_file(string(argv[1]), string(argv[2]), string(argv[3]));
	}
	if (argc == 2) {
		unsigned int l = strlen(argv[1]);
		char buffer[l + 1];
		buffer[l] = '\0';
		crypt_text(argv[1], buffer, l, "xor.key");
		cout << buffer;
	}
	return 0;
}


void usage(string filename) {
	cout << "Usage: " << filename << " <input file> <output file> <key file>" << endl;
}