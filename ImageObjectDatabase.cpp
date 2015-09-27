#include "ImageObjectDatabase.h"

int ImageObjectDatabase::writeDatabase(const char* fname){
  for (int i = 1; i <= num_objects; i++){
    Object* obj = getObject(i);
    cout << "label: " << obj->getLabel() << " | ";
    cout << "area: " << obj->getArea() << " | ";
    cout << "p min: " << obj->getOrientation().first << " | ";
    cout << "angle min: " << obj->getOrientation().second << " | ";
    cout << "center r: " << obj->getCenter().first << " | ";
    cout << "center c: " << obj->getCenter().second << " | ";
    cout << "roundness: " << obj->getRoundness() << " | ";
    cout << endl;
  }
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