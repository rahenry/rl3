#ifndef CELL_H
#define CELL_H

#include "general.h"
#include "lights.h"

struct Floor;
struct Entity;
struct Map;

struct Cell{
  int x, y;

  Entity *entity;
  Map *map;
  std::vector<Light_Effect> light_effects;
  Floor *floor_base, *floor_current;

  int get_glyph();
  TCOD_color_t get_color_fg();
  TCOD_color_t get_color_bg();

  Cell(Floor *floor_base_) : floor_base(floor_base_){};
  Cell(int x_, int y_): x(x_), y(y_), entity(NULL), map(NULL), floor_base(NULL), floor_current(NULL){};
};

#endif
