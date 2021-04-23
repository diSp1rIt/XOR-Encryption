# ifndef ARGPARSER_LIB_H
# define ARGPARSER_LIB_H

#include <string>
#include <iostream>

using namespace std;

extern string key_file;
extern string text;
extern string output_file;
extern string input_file;

enum Mode {
	FILEIO,
	PLAINTEXT,
	ERROR
};

Mode parse(int argc, const char * argv[]);

# endif 