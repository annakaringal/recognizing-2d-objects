#include "Validation.h"


bool isValidNumber(const char * str){
  // Return false if non-numeric character or if char is not . or -
  for (int i=0; i < strlen(str); i++){
    if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-') {
      return false;
    }
  }
  return true;
}

bool isValidNumber(const string str){
  // Return false if non-numeric character or if char is not . or -
  for (int i=0; i < str.length(); i++){
    if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-') {
      return false;
    }
  }
  return true;
}

float validRadians(float angle){
  if (angle < 0){
    return validRadians(2*PI - angle);
  }
  else if (angle > 2*PI){
    return validRadians(angle - 2*PI);
  } else {
    return angle;
  }
}