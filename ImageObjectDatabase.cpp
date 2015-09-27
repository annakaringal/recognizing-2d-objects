#include "ImageObjectDatabase.h"

int ImageObjectDatabase::writeDatabase(const char* fname){

}

void ImageObjectDatabase::generateObjects(){

  for (int i = 0; i < num_objects; i++){
    // Create new empty object and add to object array
    int label = i+1;
    Object obj(label);
    objects[i] = &obj;
  }

  calculateObjectProperties();
}

void ImageObjectDatabase::calculateObjectProperties(){

  // Scan image pixel by pixel
  // update properties of obj labelled at pixel
  for (int i=0; i<img->getNRows(); i++){
    for (int j=0; j<img->getNCols(); j++){
      label = img->getPixel(i,j);
      if (label > 0){
        obj = getObject(label);
        obj->updateXYProperties(i,j);
      }
    }
  }

  // Calculate center, orientation and moment for each obj
  for (int i=1; i<=num_objects; i++){
    obj = getObject(i);
    obj->calculateCenter();
    obj->calculateOrientation();
  }

}