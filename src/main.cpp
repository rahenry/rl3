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

  m1.draw(NULL, player->cell);
  sleep(1);

  delete player;

  return 0;
}
