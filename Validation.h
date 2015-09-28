#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
#include <sstream>

#define PI 3.14159265

using namespace std;

// Convert angle in radians to value between 0 and 2 PI
float validRadians(float angle);

template<typename T, typename S> bool isValidType(const S str){
  istringstream ss(str);
  T f;
  ss >> noskipws >> f;
  return ss.eof() && !ss.fail(); 
}

#endif