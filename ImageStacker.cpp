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
  pixels.reserve(600*600);
 new_input >> magic_number >> width >> height >> max_color;
 int w = 0;
  for(int i = 0; i < height; i++)
  {
    for(int j = 0; j < width; j++)
      {
	
	pixel Pixel;
	new_input >> Pixel.red >> Pixel.green >> Pixel.blue;
	//xels.push_back(Pixel);
	  pixels[w].red = Pixel.red;
	 pixels[w].green = Pixel.green;
	 pixels[w].blue = Pixel.blue;
	 //cout << Pixel.red << Pixel.green << Pixel.blue << endl;
	 //	cout << pixels[w].red << pixels[w].green << pixels[w].blue << endl;
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

  
stacker stacker::ave_stack(stacker s[], int n){
  stacker New = s[0];
  int redsum = 0;
  int greensum = 0;
  int bluesum = 0;
  // New.width = width;
  //New.height = height;
  int w = 0;
  New.pixels.reserve(600 * 600);
   //New = stacker();
 
  for(int i = 0; i < height; i++)
  {
    for(int j = 0; j < width; j++)
      {
	cout << s[w].width << s[w].height;
	// New.pixels[w].red = s[0].pixels[w].red;
	// New.pixels[w].green = s[0].pixels[w].green;
	// New.pixels[w].blue = s[0].pixels[w].blue;
	for (int i = 0; i < n; i++){
	  
	  //	pixel Pixel;
		//New.pixels.push_back(Pixel);
		//s[n].pixels[w].red + pixels[w]
		// New.pixels.push_back(Pixel);
	  	redsum += s[n].pixels[w].red;
	  	greensum += s[n].pixels[w].green;
	  	bluesum += s[n].pixels[w].blue;
		// New.pixels[w].green = (pixels[w].green +s[n].pixels[w].green)/2;
	  //New.pixels[w].red = (pixels[w].blue +s[n].pixels[w].blue)/2;
      }
	//	New.height = height;
	//New.width = width;
	New.pixels[w].red = redsum / n ;
	New.pixels[w].green =greensum / n ;
	New.pixels[w].blue = bluesum / n ;
	w++;
	cout << "test" << endl;
      }
  }
  cout << New.get_width() << " " << New.get_height();
  cout << "test1" ;
  return New;
  cout << "test" ;
}
stacker&  stacker::operator=(stacker LHS){
  int w = 0;
  for(int i = 0; i < height; i++)
  {
    for(int j = 0; j < width; j++)
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

   new_output << magic_number << "\n" << "600"  << " " << "600" << "\n" << max_color << "\n";
 int w = 0;
  for(int i = 0; i < height; i++)
  {
    for(int j = 0; j < width; j++)
      {
	new_output << pixels[w].red << pixels[w].green << pixels[w].blue  << "\n";
	w++;
      }
    
  }
}
