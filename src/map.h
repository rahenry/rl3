#ifndef MAP_H
#define MAP_H

#include "general.h"
#include "cell.h"

struct Entity;

struct Map{
  std::vector< std::vector<Cell> > cells;

  int w, h;
  Light_Map * light_map;
  TCOD_map_t fov_map;

  Map(int w_, int h_);

  void draw(TCOD_console_t con, Cell *focus, bool use_fov);
  void init_fov();
  void update_fov();

};

#endif
