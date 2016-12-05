#include "image.h"

std::string make_glyph_imagemagick(std::string file_name, int size, std::string glyph){
  using namespace std;

  stringstream command;
  command << "convert -background transparent -font Nimbus-Mono-L -pointsize ";
  command << size << " label:" << glyph << " images/" << file_name;
  cout << command.str();
  system(command.str().c_str());

  return "images/" + file_name;

}
