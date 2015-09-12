#include <iostream>
#include <fstream>

#include "functions.h"

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

    cout << "threshold: " << threshold << endl;
    cout << "inptu: " << input_img_name << endl;
    cout << "ouput: " << output_img_name << endl;


    if (read_img.fail()){
      cerr << "ERROR: Invalid file. Please check file name and try again." << endl;
      exit(-1);
    }

    if (read_img.is_open()){
      string line;
      while(getline(read_img, line)){
        // cout << line << endl;
      }
    }

    read_img.close();


    return 0;
    
}
