#include "general.h"
#include "image.h"
#include "map.h"
#include "entity.h"

int main() {
 /* while (!TCODConsole::isWindowClosed() ){
    eng.update();
    eng.render();
    TCODConsole::flush();
  }*/
  TCOD_console_init_root(80, 50, "rl1", false, TCOD_RENDERER_SDL);

  Map m1(500, 500);
  Entity *player = new Entity();
  player->glyph = 55;
  player->color = TCOD_celadon;
  player->cell = &(m1.cells[250][250]);
  m1.cells[250][250].entity = player;

  for (int x=0; x<m1.w; x++){
    for (int y=0; y<m1.h; y++){
      if (TCOD_random_get_float(NULL, 0, 10) > 5.0){
	continue;
      }
      if (x == 250 && y == 250){
	continue;
      }
      int glyph = TCOD_random_get_float(NULL, 32, 127);
      bool is_wall = false;
      TCOD_color_t col1 = TCOD_white;
      if (TCOD_random_get_float(NULL, 0, 50) < 15.0){
	is_wall = true;
      }
      else{
	TCOD_color_set_HSV(&col1,
	    TCOD_random_get_float(NULL, 0, 360.0),
	    TCOD_random_get_float(NULL, 0, 1.0),
	    TCOD_random_get_float(NULL, 0, 1.0)
	    );
      }

      Entity **e = &m1.cells[x][y].entity;
      *e = new Entity();
      (*e)->is_wall = is_wall;
      (*e)->glyph = 176;
      if (!is_wall){
	(*e)->glyph = glyph;
	(*e)->color = col1;
      }

    }
  }

  m1.init_fov();
  m1.update_fov();

  player->update_fov();

  m1.draw(NULL, player->cell, true);
  sleep(5);

  for (int x=0; x<m1.w; x++){
    for (int y=0; y<m1.h; y++){
      if(bool(TCOD_map_is_in_fov(player->fov, x, y))){
      }
    }
  }


  delete player;

  return 0;
}
