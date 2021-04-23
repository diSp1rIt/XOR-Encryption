#include <stdio.h>
#include <iostream>
#include <string>
#include "libs/xorcrypt.h"
#include "libs/argparser.h"

using namespace std;

extern string key_file;
extern string text;
extern string output_file;
extern string input_file;

void usage(string filename);


int main(int argc, char const *argv[]) {
	switch (parse(argc, argv)) {
		case ERROR:
			cerr << "Error with parse.\n"; 
			return -1;
		case PLAINTEXT:
			cout << "Work with plain text\n";
			// cout << key_file << endl;
			// cout << text << endl;
			// cout << output_file << endl;
			crypt_text(text, output_file, key_file);
			break;
		case FILEIO:
			cout << "Work with files\n";
			// cout << key_file << endl;
			// cout << text << endl;
			// cout << output_file << endl;
			// cout << input_file << endl;
			crypt_file(input_file, output_file, key_file);
			break;
	}
}


void usage(string filename) {
	cout << "Usage: " << filename << " <input file> <output file> <key file>" << endl;
}