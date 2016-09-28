/* Author: Stephen Stinson
 * Date: 9/22/16
 * Description: main driver for the program. a work in progress.
 */

#include "ImageStacker.h"

//stacker stack(stacker s[]);

int main(){
  string image;
  int number_of_images;
  stacker s[10];
  cout << "Enter the image you wish to stack: " << endl;
  cin >> image;
  cout << "Please enter the number of images you wish to stack: " << endl;
  cin >> number_of_images;
  s[0].loadFile("orion_001.ppm");
  s[1].loadFile("orion_002.ppm");
  s[2].loadFile("orion_003.ppm");
  s[3].loadFile("orion_004.ppm");
  s[4].loadFile("orion_005.ppm");
  s[5].loadFile("orion_006.ppm");
  s[6].loadFile("orion_007.ppm");
  s[7].loadFile("orion_008.ppm");
  s[8].loadFile("orion_009.ppm");
  s[9].loadFile("orion_010.ppm");
  stacker Ave;
  Ave  = s[0].ave_stack(s[1]);
  for(int i = 1; i < 9; i++)
    Ave = Ave.ave_stack(s[i+1]);
  return 0; 
}
/*Stacker stack(stacker s[]){
  int redsum = 0;
  int greensum = 0;
  int bluesum = 0;
  for(int i = 0; i < s[i].get_width(); i++){
    for(int j = 0; j < s[i].get_height(); j++){
      s[i].
*/






  





  
