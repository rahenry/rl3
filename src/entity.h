#ifndef ENTITY_H
#define ENTITY_H

#include "general.h"

struct Cell;

struct Entity{
  int glyph;
  TCOD_color_t color;
  Cell * cell;
  int priority;

  bool is_wall;

  Entity();

  TCOD_map_t fov;
  void update_fov();
};


#endif
