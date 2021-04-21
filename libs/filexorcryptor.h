# ifndef FILEXORCRYPTOR_LIB_H
# define FILEXORCRYPTOR_LIB_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void crypt_file(const string input_file, const string output_file,const unsigned char *key, int key_length);

# endif