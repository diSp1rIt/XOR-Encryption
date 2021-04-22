#include <stdio.h>
#include <iostream>
#include <string>
#include "libs/xorcrypt.h"

using namespace std;


void usage(string filename);


int main(int argc, char const *argv[]) {
	if (argc != 4) {
		usage(string(argv[0]));
		return -1;
	}

	crypt_file(string(argv[1]), string(argv[2]), string(argv[3]));

	return 0;
}


void usage(string filename) {
	cout << "Usage: " << filename << " <input file> <output file> <key file>" << endl;
}