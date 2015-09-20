#include "ObjectLabeler.h"

void ObjectLabeller::ScanAndLabel(Image* binary_img, Image* labeled_img){
  // Get and set num of rows & cols
  int rows = binary_img->getNRows();
  int cols = binary_img->getNCols();
  labeled_img->setSize(rows, cols);

  for (int i=0; i<rows; i++){
    for (int j=0; j<cols; j++){
      // If pixel is the background, label as background.
      if (binary_img->getPixel(i,j) == 0) {
        labeled_img->setPixel(i,j,0);
      } else {
        // Current pixel is part of an object.
        // Look at already labeled neighboring pixels.

        // D has a label, current pixel gets D's label
        int D = labeled_img->getPixel(i-1,j-1);
        if (D > 0){
          labeled_img->setPixel(i,j,D);
        } else {
          int B = labeled_img->getPixel(i-1,j);
          int C = labeled_img->getPixel(i,j-1);

          // B, C and D are all background. New object!
          if (B == 0 && C == 0){
            num_objects++;
            labeled_img->setPixel(i,j,num_objects);

          // Only C has a label, current pixel gets C's label
          } else if (C > 0 && B == 0) {
            labeled_img->setPixel(i,j,C);

          // Only B has a label, current pixel gets B's label
          } else if (B > 0 && C == 0){ 
            labeled_img->setPixel(i,j,B);

          // B & C have same label, current pixel gets that label
          } else if (B == C && B > 0 && C > 0) {
            labeled_img->setPixel(i,j,B);

          // B and C are both labeled but label B != label C
          // B and C's labels are equivalent, mark as equivalent
          // current pixel gets B's label
          } else {
            labeled_img->setPixel(i,j,B);
            AddToEquivalencyTable(B,C);
          }
        }
      }
    }
  }
}

void ObjectLabeler::ResolveEquivalences(Image* labeled_img){
  for (int i=0; i < labeled_img->getNRows()){
    for (int j=0; j < labeled_img->getNCols()){
      int cur_pix = labeled_img->getPixel();
      // If pixel is not background, set to lowest equivalent label
      if (cur_pix > 0){
        labeled_img->setPixel(i,j, getLowestEquivalentLabel(cur_pix));
      }
    }
  }
}

void ObjectLabeler::AddToEquivalencyTable(int labelA, int labelB){

  if (hasEquivalentLabel(labelA) > 0){

  } else if (hasEquivalentLabel(labelB) > 0){
    

  } else {
    set<int> equivalent_labels = {labelA, labelB};
    equivalencies.push_back(equivalent_labels);
  }

}

int ObjectLabeler::hasEquivalentLabel(int label){
  // Check every entry in equivalencies table
  for (int i=0; i < equivalencies.size(); i++){

    // If entry contains label, return index of entry
    if (equivalencies[i].find(label) != equivalencies[i].end()){
      return i;
    }
  }

  // Label not found
  return -1;
}



