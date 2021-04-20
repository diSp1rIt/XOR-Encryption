#include "filexorcryptor.h"


void open_input_file(const char *filename) {
	input_file_d = open(filename, O_RDONLY, S_IWUSR|S_IRUSR);
	if (input_file_d == -1) {
		printf("Error opening file. Check for exists\n");
		exit(-1);
	}
}


void open_output_file(const char *filename) {
	output_file_d = open(filename, O_WRONLY|O_CREAT|O_TRUNC, S_IWUSR|S_IRUSR);
	if (output_file_d == -1) {
		printf("Error creating file.");
		exit(-1);
	}
}


void close_all(void) {
	close(input_file_d);
	close(output_file_d);
}


void crypt_file(const char *key, int key_length) {
	while (1) {
		int bytes = read(input_file_d, buffer, key_length);
		if (bytes == 0)
			break;
		crypt(buffer, key, bytes, key_length);
		write(output_file_d, buffer, bytes);
	}
}


void crypt(char *data, const char *key, int data_len, int key_len) {
	for (int i = 0; i < data_len; i++) {
		data[i] = data[i] ^ key[i % key_len];
	}
}