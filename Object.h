#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <vector>

#include "pgm/Image.h"

using namespace std;

class Object{

public:
  Object(int l): label(l){};

  int calculateProperties(){
    calcMoment();
    calcOrientation();
    calcCenter();
    calcArea();
  }

private:
  int label;
  int centerRow, centerCol;
  float moment;
  float orientation;
  float area;

  int calcMoment();
  int calcOrientation();
  int calcCenter();
  int calcArea();

};

#endif