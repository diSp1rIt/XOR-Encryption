#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "libs/filexorcryptor.h"

using namespace std;


void usage(string filename);
void load_key(const string filename);
void print_hex(const unsigned char *data, int len_data, int column_count, const string separator);


unsigned char key[1024];
char *message;
int key_length = 0;


int main(int argc, char const *argv[]) {
	if (argc != 3) {
		usage(string(argv[0]));
		return -1;
	}

	load_key("xor.key");

	cout << "Key length: " << key_length << endl;

	cout << "Key:" << endl;
	cout << "-------- START XOR KEY ---------" << endl;
	print_hex(key, key_length, 16, " ");
	cout << "--------- END XOR KEY ----------" << endl;

	crypt_file(string(argv[1]), string(argv[2]), key, key_length);

	return 0;
}


void load_key(const string filename) {
	ifstream fd (filename);
	if (!fd.is_open()) {
		cout << "[-] Error opening \"" << filename << "\" to load key." << endl;;
		cout << "Be sure the file exists." << endl;
		exit(-1);
	}

	for (int i = 0; i < 1024; i++) {
		char buffer;
		if (fd.eof()) {
			key_length = i + 1;
			break;
		} else {
			fd.read(&buffer, 1);
			key[i] = buffer;
		}
	}
	if (key_length == 0)
		key_length = 1024;

	fd.close();
}


void print_hex(const unsigned char *data, const int len_data, const int column_count, const string separator) {
	char buffer[3];
	for (int i = 0; i < len_data; i += column_count) {
		for (int j = 0; j < column_count; j++) {
			if (i + j < len_data) {
				sprintf(buffer, "%x", data[i + j]);
				if (strlen(buffer) == 1) {
					buffer[1] = buffer[0];
					buffer[0] = '0';
				}
				cout << buffer;
				if (j != column_count - 1)
					cout << separator;
			}
		}
		cout << endl;
	}
}


void usage(string filename) {
	cout << "Usage: " << filename << " <input file> <output file>" << endl;
}