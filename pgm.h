#ifndef PGM_IMG
#define PGM_IMG

#include <iostream>
#include <string.h>

using namespace std;

class PGMImg {

public:

  PGMImg(int w=0, int h=0, int g=0) :
    width(w), height(h), max_gray(g){};

  ~PGMImg();

  int get_width(){ return width; };

  int get_height(){ return height; };

  int get_max_gray(){ return max_gray; };

  void save(string file_name) { SaveToFile(file_name); };
  
private:

  // Member vars
  int width;
  int height; 
  int max_gray;

  void SaveToFile(string file_name);

};

#endif