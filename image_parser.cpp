#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "pgm.h"

using namespace std;

bool is_valid_number(const char * str){
  for (int i=0; i < strlen(str); i++){
    if (!isdigit(str[i]) && str[i] != '.') { return false; }
  }
  return true;
}

bool is_valid_number(const string str){
  for (int i=0; i < str.length(); i++){
    if (!isdigit(str[i]) && str[i] != '.') { return false; }
  }
  return true;
}

bool is_valid_number(const string str_arr[]){
  for (int i=0; i < str_arr->length(); i++){
    if (!is_valid_number(str_arr[i])){ return false; }
  }
  return true;
}

PGMImg parseImage(ifstream &readf){
  int width, height, max_gray;
  string line, width_str, height_str;

  // GET AND CHECK IMAGE HEADERS

  // Check version
  getline(readf, line);
  if (line.compare("P5") != 0){
    // TODO: Raise exception
    cerr << "ERROR: Not a valid PGM File" << endl;
  }

  // Ignore comment
  getline(readf, line);

  // Get width & height
  getline(readf, line);
  istringstream ss(line);
  getline(ss, width_str, ' ');
  getline(ss, height_str);

  // Get max gray
  getline(readf, line);

  string header_attrs[3] = {line, width_str, height_str};
  if (is_valid_number(header_attrs)){
    max_gray = stoi(line);
    width = stoi(width_str);
    height = stoi(height_str);
  } else {
    // TODO: Raise exception
    cout << "INVALID" << endl;
    exit(-1);
  }

  PGMImg img(width, height, max_gray);

  return img;

}
