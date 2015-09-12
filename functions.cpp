#include <iostream>
#include <string.h>

#include "functions.h"

using namespace std;

bool is_valid_number(const char * str){
  cout << "checking " << str << endl;

  for (int i=0; i < strlen(str); i++){
    if (!isdigit(str[i]) && str[i] != '.') {
      return false;
    }
  }

  return true;
}
