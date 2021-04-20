#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "time.h"
#include "math.h"


void usage(void);
void encrypt(char *data, const char *key, int data_len, int key_len);
void decrypt(char *data, const char *key, int data_len, int  key_len);
void load_key(const char *filename);
void print_hex(const unsigned char *data, int len_data, int column_count, const char *separator);


time_t seconds;
int fd;
unsigned char key[1024];
char *message;
int message_len;
int key_length = 0;


int main(int argc, char const *argv[]) {
	if (argc != 2)
		exit(-1);

	seconds = time(NULL);
	printf("Time is: %d\n", seconds);

	message = (char *)malloc(1024 * sizeof(char));
	strcpy(message, argv[1]);
	message_len = strlen(message);

	load_key("xor.key");

	printf("Key length: %d\n", key_length);

	printf("Key:\n");
	printf("-------- START XOR KEY ---------\n");
	print_hex(key, key_length, 16, "");
	printf("--------- END XOR KEY ----------\n");
	printf("\n");

	printf("Message: %s\n\n", message);

	printf("Hex message:\n");
	print_hex(message, message_len, 16, "");
	printf("\n");

	encrypt(message, key, message_len, key_length);

	printf("Crypted message:\n");
	print_hex(message, message_len, 16, "");
	printf("\n");

	decrypt(message, key, message_len, key_length);

	printf("Derypted message:\n");
	print_hex(message, message_len, 16, "");
	printf("\n");	

	free(message);
	return 0;
}


void encrypt(char *data, const char *key, int data_len, int key_len) {
	for (int i = 0; i < data_len; i++) {
		data[i] = data[i] ^ key[i % key_len];
	}
}


void decrypt(char *data, const char *key, int data_len, int key_len) {
	for (int i = 0; i < data_len; i++) {
		data[i] = data[i] ^ key[i % key_len];
	}
}

void load_key(const char *filename) {
	int fd;
	fd = open(filename, O_RDONLY, S_IWUSR|S_IRUSR);
	if (fd == -1) {
		printf("[-] Error opening \"%s\" to load key.\n", filename);
		printf("Be sure the file exists.\n");
		exit(-1);
	}

	for (int i = 0; i < 1024; i++) {
		char buffer;
		if (read(fd, &buffer, 1) == 0) {
			key_length = i + 1;
			break;
		}
		else {
			key[i] = buffer;
		}
	}
	if (key_length == 0)
		key_length = 1024;

	if (close(fd) == -1) {
		printf("[-] Error closing \"%s\".\n", filename);
		exit(-1);
	}
}


void print_hex(const unsigned char *data, const int len_data, const int column_count, const char *separator) {
	char buffer[3];
	for (int i = 0; i < len_data; i += column_count) {
		for (int j = 0; j < column_count; j++) {
			if (i + j < len_data) {
				sprintf(buffer, "%x", data[i + j]);
				if (strlen(buffer) == 1) {
					buffer[1] = buffer[0];
					buffer[0] = '0';
				}
				printf("%s", buffer);
				if (j != column_count - 1)
					printf("%s", separator);
			}
		}
		printf("\n");
	}
}
