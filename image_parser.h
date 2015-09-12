#ifndef IMAGE_PARSER
#define IMAGE_PARSER

#include <iostream>
#include <fstream>

#include "pgm.h"

bool is_valid_number(const char * str);

PGMImg parseImage(istream &readf);

#endif