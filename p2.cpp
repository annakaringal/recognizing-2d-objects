#include <iostream>
#include <cstdlib>

#include "ObjectLabeler.h"
#include "pgm/Image.h"

using namespace std;

int main(int argc, const char * argv[]) {
    if (argc != 3) {
      cerr << "ERROR: Invalid number of arguments." << endl;
      exit(-1);
    }

    const char* input_img_fname = argv[1];
    const char* output_img_fname = argv[2];

    // Read image from input file, label objects in image and write to output file
    Image* input_img = new Image;
    Image* labeled_img = new Image;

    if (readImage(input_img, input_img_fname) < 0) {
      cerr << "ERROR: Something went wrong reading the input image" << endl;
      exit(-1);
    }

    ObjectLabeler labeler;
    labeler.labelObjects(input_img, labeled_img);

    if (writeImage(labeled_img, output_img_fname) < 0){
      cerr << "ERROR: Something went wrong writing the output image" << endl;
      exit(-1);
    }

    delete input_img;
    delete labeled_img;

    return 0;
}
