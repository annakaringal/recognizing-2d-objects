#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {

    if (argc != 4) {
      cerr << "ERROR: Invalid number of arguments." << endl;
      exit(-1);
    }
    // TODO: Check var types
    string input_img_name = argv[1];
    string threshold = argv[2];
    string output_img_name = argv[3];

    // Open image file
    ifstream read_img; 
    read_img.open(input_img_name.c_str());

    if (read_img.fail()){
      cerr << "ERROR: Invalid file. Please check file name and try again." << endl;
      exit(-1);
    }

    if (read_img.is_open()){
      string line;
      while(getline(read_img, line)){
        cout << line << endl;
      }
    }

    read_img.close();


    return 0;
    
}
