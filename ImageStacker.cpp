/* Author: Stephen Stinson/Matthew Austin
 * Date: 9/22/16
 * Description: The implementation file for the header file.
 */

#include "ImageStacker.h"




//Default constructor.
stacker::stacker(){
  magic_number = "P3";
  width = 0;
  height = 0;
  max_color = 255;

  /*pixel.red = 0;
  pixel.geen = 0;
  pixel.blue = 0;*/
}

/*stacker::push(pixel n){
  
  }*/

void stacker::loadFile(string file){
  ifstream new_input(file.c_str());

 new_input >> magic_number >> width >> height >> max_color;
 int w = 0;
  for(int i = 0; i < width; i++)
  {
    for(int j = 0; j < height; j++)
      {
	
	pixel Pixel;
	new_input >> Pixel.red >> Pixel.green >> Pixel.blue;
	 pixels.push_back(Pixel);
	  pixels[w].red = Pixel.red;
	 pixels[w].green = Pixel.green;
	 pixels[w].blue = Pixel.blue;
	 //cout << Pixel.red << Pixel.green << Pixel.blue << endl;
	// //	cout << pixels[w].red << pixels[w].green << pixels[w].blue << endl;
	w++;
      }
    
  }
}	
int stacker::get_width(){
  return  width;
}
int stacker::get_height(){
  return  height;
}

  
stacker stacker::ave_stack(stacker s){
  stacker New;
  int w = 0;
  for(int i = 0; i < width; i++)
  {
    for(int j = 0; j < height; j++)
      {

	New.pixels[w].red = (pixels[w].red +s.pixels[w].red)/2;
	New.pixels[w].green = (pixels[w].green +s.pixels[w].green)/2;
	New.pixels[w].red = (pixels[w].blue +s.pixels[w].blue)/2;
      }
  }
  return New;
}
stacker&  stacker::operator=(stacker LHS){
  int w = 0;
  for(int i = 0; i < width; i++)
  {
    for(int j = 0; j < height; j++)
      {
	LHS.pixels[w].red = pixels[w].red;
	LHS.pixels[w].green = pixels[w].green;
	LHS.pixels[w].blue = pixels[w].blue;
	w++;
      }
  }
  return LHS;
}
void stacker::Writefile(string file){
   ofstream new_output(file.c_str());

   new_output << magic_number << "\n" << width  << " " << height << "\n" << max_color << "\n";
 int w = 0;
  for(int i = 0; i < width; i++)
  {
    for(int j = 0; j < height; j++)
      {
	new_output << pixels[w].red << " " << pixels[w].green << " " << pixels[w].blue  << "\n";
	w++;
      }
    
  }
