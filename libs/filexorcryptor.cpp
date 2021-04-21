#include "filexorcryptor.h"


void crypt_file(const string input_file, const string output_file,const unsigned char *key, int key_length) {
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
