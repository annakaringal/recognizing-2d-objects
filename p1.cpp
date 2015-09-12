#include <iostream>
#include <fstream>
#include <string>

#include "pgm.h"
#include "image_parser.h"

using namespace std;

int main(int argc, const char * argv[]) {

    if (argc != 4) {
      cerr << "ERROR: Invalid number of arguments." << endl;
      exit(-1);
    }

    string input_img_name = argv[1];
    string output_img_name = argv[3];
    int threshold;

    if (is_valid_number(argv[2])){
      threshold = atoi(argv[2]);
    } else {
      cerr << "ERROR: Invalid threshold number." << endl;
      exit(-1);
    }

    // Open image file
    ifstream read_img; 
    read_img.open(input_img_name.c_str());

    if (read_img.fail()){
      cerr << "ERROR: Invalid file. Please check file name and try again." << endl;
      exit(-1);
    }

    PGMImg input_img; 

    if (read_img.is_open()){
      input_img = parseImage(read_img);
    }

    read_img.close();


    return 0;
    
}
