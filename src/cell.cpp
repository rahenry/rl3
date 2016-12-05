#include "cell.h"
#include "entity.h"
#include "floor.h"
#include "lights.h"

int Cell::get_glyph(){
  if (entity){
    return entity->glyph;
  }
  return 32;
}

TCOD_color_t Cell::get_color_fg(){
  if (entity){
    return entity->color;
  }
  return TCOD_white;
}

TCOD_color_t Cell::get_color_bg(){
  if (floor_current){
    return floor_current->color;
  }
  if (floor_base){
    return floor_base->color;
  }

  return TCOD_black;
}
