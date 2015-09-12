#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "pgm.h"

using namespace std;

bool is_valid_number(const char * str){
  for (int i=0; i < strlen(str); i++){
    if (!isdigit(str[i]) && str[i] != '.') {
      return false;
    }
  }

  return true;
}
