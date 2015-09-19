#include <iostream>
#include <string.h>

#include "BinaryImage.h"
#include "pgm/Image.h"

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
  if (threshold > binary_img.getNColors() || threshold < 0) { return -1; }

  // Set rows & cols of binary_img
  int rows = greyscale_img->getNRows();
  int cols = greyscale_img->getNCols();
  binary_img->setSize(rows, cols);

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