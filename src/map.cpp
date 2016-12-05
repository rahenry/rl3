#include "map.h"
#include "entity.h"

Map::Map(int w_, int h_): w(w_), h(h_){
  for (int x=0; x<w; x++){
    cells.push_back(std::vector<Cell>());
    for (int y=0; y<h; y++){
      cells.back().push_back(Cell(x, y));
    }
  }
}

void Map::draw(TCOD_console_t con, Cell *focus){
  TCOD_console_clear(con);
  int W = TCOD_console_get_width(con);
  int H = TCOD_console_get_height(con);
  for (int x=0; x<W; x++){
    for (int y=0; y<H; y++){
      int X = focus->x - x + W/2;
      int Y = focus->y - y + H/2;
      if (X >= 0 &&
	  X < w &&
	  Y >= 0 &&
	  Y < h){
	Cell cell = cells[X][Y];
	TCOD_console_put_char_ex(con, x, y, cell.get_glyph(), cell.get_color_fg(), cell.get_color_bg());
      }
    }
  }
  TCOD_console_flush();
}

void Map::init_fov(){
  fov_map = TCOD_map_new(w, h);
}

void Map::update_fov(){
  for (int x=0; x<w; x++){
    for (int y=0; y<h; y++){
      TCOD_map_set_properties(fov_map, x, y,
	  cells[x][y].entity->is_wall,
	  cells[x][y].entity->is_wall);
    }
  }
}
