#ifndef OBJECT_LABELER_H
#define OBJECT_LABELER_H

#include <iostream>
#include <vector>
#include <set>

#include "pgm/Image.h"

using namespace std;

class ObjectLabeler{

  ObjectLabeler(){ num_objects = 0; }

  ~ObjectLabeler();

  void labelObjects(Image* binary_img, Image* labeled_img){
    // First pass
    ScanAndLabel(binary_img, labeled_img);

    // Second pass
    ResolveEquivalences(labeled_img);

    // Set number of objects for labeled_img
    labeled_img->setColors(getNumObjects());
  }

  int getNumObjects() {return num_objects};

private:
  vector <set<int>> equivalencies;
  int num_objects;

  void ScanAndLabel(Image* binary_img, Image* labeled_img);

  void ResolveEquivalences(Image* labeled_img);

  void AddToEquivalencyTable(int labelA, int labelB);

  int getLowestEquivalentLabel(int label);

  int hasEquivalenctLabel(int label);
};

#endif