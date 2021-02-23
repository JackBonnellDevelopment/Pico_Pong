#include <string.h>
#include <math.h>
#include <vector>
#include <cstdlib>
#include "pico_display.hpp"

using namespace pimoroni;

extern unsigned char image_tif[];
extern unsigned int image_tif_len;

uint16_t buffer[PicoDisplay::WIDTH * PicoDisplay::HEIGHT];
PicoDisplay pico_display(buffer);
int main() {
  pico_display.init();
  pico_display.set_backlight(100);
  bool a_pressed = false;
  bool b_pressed = false;
  bool x_pressed = false;
  bool y_pressed = false;
int x = 10;
int y = 10;
int linenum = 1;
  while(true) {
    pico_display.set_pen(0, 0, 0);
    pico_display.clear();
    pico_display.set_pen(255, 40, 60);
    if(pico_display.is_pressed(pico_display.A)) {
      x = 50;
    }else{
      x = 10;
    }
    if(pico_display.is_pressed(pico_display.B)) {
      std::string image_width = std::to_string(pico_display.WIDTH);
      for(int i = 0; i < linenum; i++){
        int ypos = y + (15*i);
        pico_display.text(image_width, Point(x,ypos), 100);
      }
      
    }
    if(pico_display.is_pressed(pico_display.X)) {
      linenum = linenum + 1;
      sleep_ms(200);
    }
    if(pico_display.is_pressed(pico_display.Y)) {
      linenum = linenum - 1;
      sleep_ms(200);
    }
    // update screen
    pico_display.update();
  }
}
