#include <iostream>
#include <string.h>

#include "BinaryImage.h"
#include "pgm/Image.h"
#include "disjsets/DisjointSet.h"

using namespace std;

bool isValidNumber(const char * str){
  // Return false if non-numeric character or if char is not . or -
  for (int i=0; i < strlen(str); i++){
    if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-') {
      return false;
    }
  }
  return true;
}

int convertToBinary(Image* greyscale_img, Image* binary_img, int threshold){
  // Check if threshold is valid
  if (threshold > greyscale_img->getColors() || threshold < 0) { return -1; }

  // Set rows & cols of binary_img
  int rows = greyscale_img->getNRows();
  int cols = greyscale_img->getNCols();
  binary_img->setSize(rows, cols);
  binary_img->setColors(1);

  // Set colors of binary_img based on given threshold
  for (int i=0; i<rows; i++){
    for (int j=0; j<cols; j++){
      if (greyscale_img->getPixel(i, j) < threshold){
        if (binary_img->setPixel(i, j, 0) < 0) {
          return -1;
        };
      } else {
        if (binary_img->setPixel(i, j, 1) < 0){
          return -1;
        }
      }
    }
  }

  return 0;
}

int labelObjects(Image* binary_img, Image* labeled_img){
  // Get and set num of rows & cols
  int rows = binary_img->getNRows();
  int cols = binary_img->getNCols();
  int num_objects = 1;
  labeled_img->setSize(rows, cols);

  // Equivalency table of worst case size
  // (every pixel is a different object)
  DisjointSet equivalent_labels(rows*cols);

  // First pass
  for (int i=0; i<rows; i++){
    for (int j=0; j<cols; j++){
      // If pixel is the background, label as background.
      if (binary_img->getPixel(i,j) == 0) {
        labeled_img->setPixel(i,j,0);
      } else {
        // Current pixel is part of an object.
        // Look at already labeled neighboring pixels.

        // D has a label, current pixel gets D's label
        int D = labeled_img->getPixel(i-1,j-1)
        if (D > 0){
          labeled_img->setPixel(i,j,D);
        } else {
          int B = labeled_img->getPixel(i-1,j);
          int C = labeled_img->getPixel(i,j-1);

          // B, C and D are all background. New object!
          if (B == 0 && C == 0){
            num_objects++;
            labeled_img->setPixel(i,j,num_objects)

          // Only C has a label, current pixel gets C's label
          } else if (C > 0 && B == 0) {
            labeled_img->setPixel(i,j,C);

          // Only B has a label, current pixel gets B's label
          } else if (B > 0 && C == 0){ 
            labeled_img->setPixel(i,j,B);

          // B & C have same label, current pixel gets that label
          } else if (B == C) {
            labeled_img->setPixel(i,j,B);

          // B and C are both labeled but label B != label C
          // B and C's labels are equivalent, mark as equivalent
          // current pixel gets B's label
          } else {
            labeled_img->setPixel(i,j,B);
            equivalent_labels.unionSets(B,C);
          }
        }
      }
    }
  }

  // Second pass: resolve equivalences
  for (int i=0; i<rows; i++){
    for (int j=0; j<cols; j++){
      int cur = labeled_img->getPixel(i,j);
      if (cur > 0){
        labeled_img->setPixel(i,j,equivalent_labels.find(cur));
      }
    }
  }

  // set number of objects for labeled_img
  labeled_img->setColors(num_objects);

  return 0;
}
