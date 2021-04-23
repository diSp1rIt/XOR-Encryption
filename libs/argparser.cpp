#include "argparser.h"


string key_file;
string text;
string output_file;
string input_file;


static unsigned int index = 0;


static bool findflag(int argc, const char * argv[], string flag) {
	for (int i = 0; i < argc; i++) {
		if (flag == argv[i]) {
			index = i;
			return true;
		}
	}
	return false;
}


Mode parse(int argc, const char * argv[]) {
	if (argc < 7) {
		return ERROR;
	}

	if (!findflag(argc, argv, "-k")) {
		return ERROR;
	} else {
		key_file = string (argv[index + 1]);
	}

	if (!findflag(argc, argv, "-o")) {
		return ERROR;
	} else {
		output_file = string (argv[index + 1]);
	}

	if (!findflag(argc, argv, "-t")) {
		if (findflag(argc, argv, "-i")) {
			input_file = string (argv[index + 1]);
			return FILEIO;
		}
		return ERROR;
	} else {
		if (!findflag(argc, argv, "-i")) {
			text = string (argv[index + 1]);
			return PLAINTEXT;
		}
		return ERROR;
	}
}
