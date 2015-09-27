#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>

#define PI 3.14159265

// Returns true if char * is a decimal number
bool isValidNumber(const char* str);

// Convert angle in radians to value between 0 and 2 PI
float validRadians(float angle);

#endif