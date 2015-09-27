#include "Object.h"

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
  centerCol = ySum / area;
  return pair<float,float> (centerRow, centerCol);
}

void Object::calculateOrientation(){
  float a = xSqSum - (centerRow * centerRow * area);
  float b = xySum - (2 * centerRow * centerCol * area);
  float c = ySqSum - (centerCol * centerCol * area);

  if (b!=0 && a!=c){
    min_angle = validRadians(atan((2*b) / (a-c))) / 2;
  } else { 
    min_angle = 0;
  }
  max_angle = validRadians((PI / 2) + min_angle);

  min_moment = (a*sin(min_angle)*sin(min_angle)) - (b*sin(min_angle)*cos(min_angle)) + (c*cos(min_angle)*cos(min_angle));
  max_moment = (a*sin(max_angle)*sin(max_angle)) - (b*sin(max_angle)*cos(max_angle)) + (c*cos(max_angle)*cos(max_angle));

  roundness = min_moment / max_moment;

  orientation_line.first = (centerCol*cos(min_angle)) - (centerRow*sin(min_angle));
  orientation_line.second = min_angle;
}

float validRadians(float angle){
  if (angle < 0){
    return validRadians(2*PI - angle);
  }
  else if (angle > 2*PI){
    return validRadians(angle - 2*PI);
  } else {
    return angle;
  }
}