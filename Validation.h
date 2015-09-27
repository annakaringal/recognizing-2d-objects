#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>

#define PI 3.14159265

using namespace std;

// Returns true if char * is a decimal number
bool isFloat(const char* str);
bool isFloat(const string str);

// Returns true if char * is a decimal number
bool isInt(const char* str);
bool isInt(const string str);

// Convert angle in radians to value between 0 and 2 PI
float validRadians(float angle);

#endif