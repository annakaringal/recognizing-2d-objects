#ifndef IMAGE_OBJECT_DB_H
#define IMAGE_OBJECT_DB_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>

#include "pgm/Image.h"
#include "Object.h"
#include "Validation.h"

#define TOLERANCE 0.00001

using namespace std;

class ImageObjectDatabase{

public:
  // create image object database from image
  ImageObjectDatabase(Image* labeled_img) : img (labeled_img) {
    num_objects = labeled_img->getColors();
    generateObjects();
  };

  ImageObjectDatabase() { 
    num_objects = 0;
  };

  ~ImageObjectDatabase(){
    for (int i=0; i<objects.size(); i++){
      delete objects[i];
    }
  }

  int getNumObjects() const { return num_objects; };

  int writeDatabase(const char* fname);

  Object* getObject(int label) const { return objects[label-1]; };

  int hasMatch(Object* obj);

private:
  Image* img;
  int num_objects;
  vector<Object*> objects;

  void generateObjects();

  void calculateObjectProperties();
};

int readDatabase(ImageObjectDatabase* iodb, const char* fname);

#endif