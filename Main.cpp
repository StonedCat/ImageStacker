/* Author: Stephen Stinson/Matthew Austin
 * Date: 9/22/16
 * Description: main driver for the program. a work in progress.
 */

#include "ImageStacker.h"
#include <sstream>
//stacker stack(stacker s[]);

int main(){
  string file_number;
  stringstream itoa;
  string image;
  int number_of_images;
  stacker s[10];
  stacker Ave;
  string file_load;
  cout << "Enter the image you wish to stack: " << endl;
  cin >> image;
  cout << "Please enter the number of images you wish to stack: " << endl;
  cin >> number_of_images;
  
  for (int i = 0; i < number_of_images; i++){
    if(i < number_of_images){
      itoa << i+1;
      file_number = itoa.str();
      s[i].loadFile("./orion_00" + file_number + ".ppm");
      cout << "./orion/orion_00" + file_number + ".ppm" << endl;
      itoa.str("");
    }
    else if (i == number_of_images){
      itoa << i;
      file_number = itoa.str();
      s[i].loadFile("./orion_0" + file_number + ".ppm");
      cout << "./orion/orion_0" + file_number + ".ppm" << endl;
      itoa.str("");
    } 
    
    // s[i].loadFile(file_load.c_str());
      }
  
  Ave = s[0];
  Ave = Ave.ave_stack(s,number_of_images);
  
  cout << "Pleae enter a file to output your data to.";
  cin >> file_load;

  Ave.Writefile(file_load);
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






  
