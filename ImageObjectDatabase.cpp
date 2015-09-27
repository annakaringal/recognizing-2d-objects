#include "ImageObjectDatabase.h"

int ImageObjectDatabase::writeDatabase(const char* fname){

  ofstream writef;
  writef.open(fname);
  // Return if fail to open file
  if (writef.fail()) {
    return -1;
  }
  // Write image attributes to file
  if (writef.is_open()) {
    for (int i = 1; i <= num_objects; i++){
      Object* obj = getObject(i);
      writef << obj->getLabel() << " ";
      writef << obj->getCenter().first<< " ";
      writef << obj->getCenter().second<< " ";
      writef << obj->getMinMoment()<< " ";
      writef << obj->getOrientation().second << " ";
      writef << obj->getArea() << " ";
      writef << obj->getRoundness() << "\n";
    }
  }
  writef.close();
  return 0;
}

void ImageObjectDatabase::generateObjects(){

  for (int i = 0; i < num_objects; i++){
    // Create new empty object and add to object array
    int label = i+1;
    objects.push_back(new Object(label));
  }
  calculateObjectProperties();
}

void ImageObjectDatabase::calculateObjectProperties(){

  // Scan image pixel by pixel
  // update properties of obj labelled at pixel
  for (int i=0; i<img->getNRows(); i++){
    for (int j=0; j<img->getNCols(); j++){
      int label = img->getPixel(i,j);
      if (label > 0){
        Object* obj = getObject(label);
        obj->updateXYProperties(i,j);
      }
    }
  }

  // Calculate center, orientation and moment for each obj
  for (int i=1; i<=num_objects; i++){
    Object* obj = getObject(i);
    obj->calculateCenter();
    obj->calculateOrientation();
  }

}