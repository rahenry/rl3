#ifndef LIGHTS_H
#define LIGHTS_H

#include "general.h"

struct Cell; 
struct Map;

struct Light_Effect{

  TCOD_color_t color;

};

struct Light_Source{
  TCOD_color_t color;
  double intensity;
  Cell *cell;
};

struct Light_Map{
  std::vector< std::vector<int> > walls;
  std::vector< std::vector<Light_Source> > light_sources;

  Light_Map(Map map_);
  void update();

};


#endif
