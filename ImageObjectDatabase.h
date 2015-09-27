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
    num_objects = labeled_img->getColors();
    generateObjects();
  };

  int getNumObjects() const { return num_objects; };

  int writeDatabase(const char* fname);

  Object* getObject(int label) const { return objects[label-1]; };

private:
  Image* img;
  int num_objects;
  vector<Object*> objects;

  void generateObjects();

  void calculateObjectProperties();
};

#endif