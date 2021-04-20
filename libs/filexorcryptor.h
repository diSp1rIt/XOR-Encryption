# ifndef FILEXORCRYPTOR_LIB_H
# define FILEXORCRYPTOR_LIB_H

#include "sys/stat.h"
#include "fcntl.h"
#include "stdio.h"
#include "stdlib.h"

static int input_file_d, output_file_d;
static char buffer[1024];


void open_input_file(const char *filename);
void open_output_file(const char *filename);
void close_all(void);
void crypt_file(const char *key, int key_length);

# endif