#include "entity.h"
#include "cell.h"
#include "map.h"

Entity::Entity() : glyph(32), color(TCOD_white), cell(NULL), priority(1), is_wall(false), fov_initialised(false){

}

void Entity::init_fov(){
  fov = TCOD_map_new(cell->map->w, cell->map->h);
  TCOD_map_copy(cell->map->fov_map, fov);
}

void Entity::update_fov(){
  if (!fov_initialised){
    init_fov();
  }

  TCOD_map_compute_fov(fov, cell->x, cell->y, 0, true, FOV_SHADOW);
}
