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
    const char* objs_db_fname = argv[2];
    const char* output_img_fname = argv[3];

    // Read image from input file
    Image* input_img;
    input_img = new Image;
    if (readImage(input_img, input_img_fname) < 0) {
      cerr << "ERROR: Something went wrong reading the input image" << endl;
      exit(-1);
    }

    // Generate database for input image objects
    ImageObjectDatabase input_iodb(input_img);

    // Read input database of objects from file
    ImageObjectDatabase* objs_iodb = new ImageObjectDatabase;
    if (readDatabase(objs_iodb, objs_db_fname) < 0){
        cerr << "ERROR: Something went wrong reading the input object database" << endl;
        exit(-1);
    }

    // Create output image as copy of input image
    Image* output_img(input_img);

    // Check each object db image to see if there's a matching object in the input image
    int num_objs = objs_iodb->getNumObjects();
    for (int i=1; i<= num_objs; i++){
      Object* obj = objs_iodb->getObject(i);
      int match_label = input_iodb.hasMatch(obj);

      // If there's a match, draw the center orientation line
      if (match_label > 0) {
        cout << "Input object " << match_label << " was a match for object " << obj->getLabel() << "!" << endl;
        Object* match_object = input_iodb.getObject(match_label);
        pair<float, float> center = match_object->getCenter();
        pair<float, float> orientation = match_object->getOrientation();
        float p = orientation.first;
        float angle = orientation.second;

        int endX = center.first + 20;
        int endY = (endX * sin(angle) + p) / cos(angle);

        line(output_img, center.first, center.second, endX, endY, 0);
      }
    }

    // Write output image to file
    if (writeImage(output_img, output_img_fname) < 0){
      cerr << "ERROR: Something went wrong writing the output image" << endl;
      exit(-1);
    }

    delete input_img;

    return 0;
}
