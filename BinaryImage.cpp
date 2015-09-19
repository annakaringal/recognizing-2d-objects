#include <iostream>
#include <string.h>

#include "BinaryImage.h"
#include "pgm/Image.h"

using namespace std;

bool isValidNumber(const char * str){
  for (int i=0; i < strlen(str); i++){
    if (!isdigit(str[i]) && str[i] != '.') {
      return false;
    }
  }
  return true;
}

void convertToBinary(Image* greyscale_img, Image* binary_img, int threshold){
  int rows = greyscale_img->getNRows();
  int cols = greyscale_img->getNCols();
  binary_img->setSize(rows, cols);

  for (int i=0; i<rows; i++){
    for (int j=0; j<cols; j++){
      if (greyscale_img->getPixel(i, j) < threshold){
        binary_img->setPixel(i, j, 0);
      } else {
        binary_img->setPixel(i, j, 1);
      }
    }
  }

}