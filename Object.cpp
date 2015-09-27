#include "Object.h"

void Object::setArea(int a){ area = a; }

void Object::setCenter(int r, int c){ 
  centerRow = r; 
  centerCol = c;
 };

void Object::updateXYProperties(int x, int y){
  area++;
  xSum += x; 
  ySum += y;
  xSqSum += (x*x);
  ySqSum += (y*y);
  xySum += (x*y);
};

pair<float,float> Object::calculateCenter(){
  centerRow = xSum / area;
  centerCol = yXum / area;
  return pair<float,float> (centerRow, centerCol);
}
