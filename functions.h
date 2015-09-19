#include <iostream>

#include "pgm/Image.h"

using namespace std;

bool isValidNumber(const char* str);

int convertToBinary(Image* greyscale_img, Image* binary_img, int threshold);