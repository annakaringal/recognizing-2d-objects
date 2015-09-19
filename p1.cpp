#include <iostream>
#include <fstream>

#include "BinaryImage.h"
#include "pgm/Image.h"

using namespace std;

int main(int argc, const char * argv[]) {
    if (argc != 4) {
      cerr << "ERROR: Invalid number of arguments." << endl;
      exit(-1);
    }

    const char* input_img_fname = argv[1];
    const char* output_img_fname = argv[3];
    int threshold;

    if (isValidNumber(argv[2])){
      threshold = atoi(argv[2]);
    } else {
      cerr << "ERROR: Invalid threshold number." << endl;
      exit(-1);
    }

    Image input_img, binary_img;
    Image* input_img_ptr = &input_img;
    Image* binary_img_ptr = &binary_img;

    if (readImage(input_img_ptr, input_img_fname) < 0) {
      cerr << "ERROR: Something went wrong reading the input image" << endl;
      exit(-1);
    }

    ConvertToBinary(input_img_ptr, binary_img_ptr, threshold);

    writeImage()

    return 0;
}
