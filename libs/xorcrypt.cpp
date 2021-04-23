#include "xorcrypt.h"


static unsigned char *key= new unsigned char [1024];
static int key_length = 0;


static void load_key(const string key_file) {
	ifstream fd (key_file);
	if (!fd.is_open()) {
		cout << "[-] Error opening \"" << key_file << "\" to load key." << endl;;
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


void crypt_file(const string input_file, const string output_file, const string key_file) {
	ifstream input (input_file);
	ofstream output (output_file, ios_base::trunc);

	if (!input.is_open()) {
		cerr << "Can not open file" << endl;
		exit(-1);
	}

	if (!output.is_open()) {
		cerr << "Can not open or create file" << endl;
		exit(-1);
	}

	load_key(key_file);

	unsigned int i = 0;
	while (1) {
		char byte;
		input.read(&byte, 1);
		if (input.eof())
			break;
		byte = byte ^ key[i];
		output.write(&byte, 1);
		i = (i + 1) % key_length;
	}

	if (input.is_open())
		input.close();
	if (output.is_open())
		output.close();
}


void crypt_text(const string input, const string output_file, const string key_file) {
	ofstream output (output_file, ios_base::trunc);

	if (!output.is_open()) {
		cerr << "Can not open or create file" << endl;
		exit(-1);
	}

	load_key(key_file);

	unsigned int j = 0;
	for (unsigned int i = 0; i < input.size(); i++) {
		char byte;
		byte = input[i] ^ key[j];
		output.write(&byte, 1);
		j = (j + 1) % key_length;
	}

	if (output.is_open())
		output.close();
}