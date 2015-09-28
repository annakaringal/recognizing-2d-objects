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

int ImageObjectDatabase::hasMatch(Object* obj){
  for (int i=1; i<=num_objects; i++){
    if (obj->getArea() == getObject(i)->getArea() && 
      fabs(obj->getRoundness() - getObject(i)->getRoundness()) < TOLERANCE){
      return i;
    }
  }
  return -1;
}

void ImageObjectDatabase::addObject(Object* obj){
  // add object to database and increment num of objects;
  objects.push_back(obj);
  num_objects++;
}

int readDatabase(ImageObjectDatabase* iodb, const char* fname){
  ifstream readf;
  readf.open(fname);

  // Return with error if opening file fails
  if (readf.fail()){
    return -1;
  }

  if (readf.is_open()){
    string obj_str;
    while (getline(readf, obj_str)){
      istringstream objss(obj_str);

      // Get label, check if valid number and valid label
      string label_str;
      objss >> label_str;
      int label;
      if (!isValidType<int, string>(label_str)){ throw -1; }
    
      label = stoi(label_str);
      if (label != iodb->getNumObjects()+1){ throw -1; }

      // Create new object with label and push to objects db
      Object *obj = new Object(label);
      iodb->addObject(obj);

      // Get rest of attributes and check each for valid num
      string cr, cc, minM, minA, a, r;
      objss >> cr >> cc >> minM >> minA >> a >> r;

      if (!isValidType<float, string>(cr) || !isValidType<float, string>(cc) || !isValidType<float, string>(minM) ||
          !isValidType<float, string>(minA) || !isValidType<int, string>(a) || !isValidType<float, string>(r)){
        return -1;
      }

      // Set object attributes
      obj->setCenter(stof(cr),stof(cc));
      obj->setArea(stoi(a));
      obj->setRoundness(stof(r));
      obj->setMinAngle(stof(minA));
      obj->setMinMoment(stof(minM));

      obj->calculateOrientationLine();
    }
  }
  readf.close();

  return 0;
}
