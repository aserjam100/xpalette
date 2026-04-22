#include "ui.h"

#define PAD 20
#define CONTROL_H 50
#define GAP 15

Layout ui_compute_layout(int screen_w, int screen_h){
  Layout layout;
  
  // Picker
  float picker_size = (screen_w - 2 * PAD < screen_h * 0.6f) ? (screen_w - 2 * PAD) : (screen_h * 0.6f);
  layout.picker.x = (screen_w - picker_size) / 2.0f;
  layout.picker.y = PAD;
  layout.picker.width = picker_size;
  layout.picker.height = picker_size;

  // Controls
  layout.controls.x = PAD;
  layout.controls.y = layout.picker.y + layout.picker.height + GAP;
  layout.controls.width = screen_w - 2 * PAD;
  layout.controls.height = CONTROL_H;

  // Palette
  layout.palette.x = PAD;
  layout.palette.y = layout.controls.y + layout.controls.height + GAP;
  layout.palette.width = screen_w - 2 * PAD;
  layout.palette.height = screen_h - layout.palette.y - PAD;

  return layout;
}
