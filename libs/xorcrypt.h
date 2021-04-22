# ifndef XORCRYPT_LIB_H
# define XORCRYPT_LIB_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void crypt_file(const string input_file, const string output_file, const string key);
void crypt_text(const char *input, char *output, const unsigned int len, const string key_file);

# endif