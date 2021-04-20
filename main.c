#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "time.h"
#include "math.h"


void usage(void);


time_t seconds;
int fd;
unsigned char key[8];
char *message;
int message_len;


int main(int argc, char const *argv[]) {
	if (argc != 2)
		exit(-1);

	seconds = time(NULL);
	printf("Time is: %d\n", seconds);

	fd = open("xor.key", O_RDONLY, S_IRUSR|S_IWUSR);
	if (fd == -1)
		exit(-1);

	message = (char *)malloc(1024 * sizeof(char));
	strcpy(message, argv[1]);
	message_len = strlen(message);

	for (short i = 0; i < 8; i++) {
		read(fd, key, 8);
	}

	printf("Key: ");
	for (int i = 0; i < 8; i++) {
		printf("%x ", key[i]);
	}
	printf("\n");

	printf("Message: %s\n", message);

	for (int i = 0; i < message_len; i++) {
		message[i] = message[i] ^ key[i % 8];
	}

	printf("Crypted message: ");
	for (int i = 0; i < message_len; i++) {
		printf("%x ", message[i]);
	}
	printf("\n");

	for (int i = 0; i < message_len; i++) {
		message[i] = message[i] ^ key[i % 8];
	}

	printf("Derypted message: ");
	for (int i = 0; i < message_len; i++) {
		printf("%c ", message[i]);
	}
	printf("\n");	

	free(message);
	close(fd);
	return 0;
}
