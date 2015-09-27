#include <iostream>

#include "ImageObjectDatabase.h"
#include "pgm/Image.h"

using namespace std;

int main(int argc, const char * argv[]) {
    if (argc != 4) {
      cerr << "ERROR: Invalid number of arguments." << endl;
      exit(-1);
    }

    const char* input_img_fname = argv[1];
    const char* output_db_fname = argv[2];
    const char* output_img_fname = argv[3];

    // Read image from input file
    Image* input_img;
    input_img = new Image;
    if (readImage(input_img, input_img_fname) < 0) {
      cerr << "ERROR: Something went wrong reading the input image" << endl;
      exit(-1);
    }

    // Generate database for image objects and write database to file
    ImageObjectDatabase iodb(input_img);

    if (iodb.writeDatabase(output_db_fname) < 0){
      cerr << "ERROR: Something went wrong writing the output database" << endl;
      exit(-1);
    }

    // Create output image as copy of input image
    Image* output_img(input_img);

    // Draw lines for each object
    int num_objs = iodb.getNumObjects();
    for (int i=1; i<= num_objs; i++){
      Object* obj = iodb.getObject(i);

      pair<float, float> center = obj->getCenter();
      pair<float, float> orientation = obj->getOrientation();
      float p = orientation.first;
      float angle = orientation.second;

      int endX = center.first + 20;
      int endY = (endX * sin(angle) + p) / cos(angle);

      line(output_img, center.first, center.second, endX, endY, 0);
    }

    // Write output image to file
    if (writeImage(output_img, output_img_fname) < 0){
      cerr << "ERROR: Something went wrong writing the output image" << endl;
      exit(-1);
    }

    delete input_img;

    return 0;
}
