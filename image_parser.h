#ifndef IMAGE_PARSER
#define IMAGE_PARSER

#include "pgm.h"

using namespace std;

bool is_valid_number(const char * str);

bool is_valid_number(const string str);

bool is_valid_number(const string str_arr[]);

PGMImg parseImage(ifstream &readf);

#endif