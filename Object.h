#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <vector>
#include <math.h>

#include "pgm/Image.h"

#define PI 3.14159265

using namespace std;

class Object{

public:
  Object(int l, int area=0, int xS=0, int yS=0, int xxS=0, int yyS=0, int xy=0)
        : label(l), area(a), xSum(xS), ySum(yS), xSqSum(xxS), ySqSum(yyS), xySum(xy){};

  int getArea() const { return area; };

  int getxSum() const { return xSum; };

  int getySum() const { return ySum; };

  pair<float,float> getCenter() const {
    return pair<float, float> (centerRow, centerCol);
  };

  pair<float,float> calculateCenter();

private:
  int label;
  float centerRow, centerCol;
  float moment;
  float orientation;
  int area;
  int xSum, ySum;
  int xSqSum, ySqSum; 
  int xy;
};

#endif