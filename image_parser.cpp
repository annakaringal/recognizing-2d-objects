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

  try{
    max_gray = stoi(line);
    width = stoi(width_str);
    height = stoi(height_str);
  } catch (invalid_argument ia){
    cerr << "ERROR: Invalid image headers (" << ia.what() << ")"<< endl;
    exit(-1);
  }

  cout << "width: " << width << endl;
  cout << "height: " << height << endl;
  cout << "max_gray: " << max_gray << endl;

  PGMImg img(width, height, max_gray);

  return img;

}
