#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <vector>
#include <math.h>

#include "pgm/Image.h"
#include "Validation.h"

#define PI 3.14159265

using namespace std;

class Object{

public:
  Object(int l, int a=0, int xS=0, int yS=0, int xxS=0, int yyS=0, int xy=0)
        : label(l), area(a), xSum(xS), ySum(yS), xSqSum(xxS), ySqSum(yyS), xySum(xy){};

  void updateXYProperties(int x, int y);

  int getLabel() const { return label; };

  int getArea() const { return area; };

  pair<float, float> getOrientation() const { return orientation_line; };

  float getMinMoment() const { return min_moment; };

  float getRoundness() const { return roundness; };

  pair<float,float> getCenter() const {
    return pair<float, float> (centerRow, centerCol);
  };

  pair<float,float> calculateCenter();

  void calculateOrientation();

  int setCenter(int r, int c);

private:
  int label;
  float centerRow, centerCol;
  float min_moment, max_moment;
  float min_angle, max_angle;
  float roundness;
  pair <float, float> orientation_line;
  int area;
  int xSum, ySum;
  int xSqSum, ySqSum; 
  int xySum;
};


#endif