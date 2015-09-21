#ifndef IMAGE_OBJECT_DB_H
#define IMAGE_OBJECT_DB_H

#include <iostream>
#include <vector>

#include "pgm/Image.h"
#include "Object.h"

using namespace std;

class ImageObjectDatabase{

public:
  ImageObjectDatabase(Image* labeled_img) : img (labeled_img) {
    generateObjects(labeled_img);
  };

  int writeDatabase(const char* fname);

private:
  Image* img;
  vector <Object> objects;

  void generateObjects(labeled_img);
};

#endif