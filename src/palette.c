#include "palette.h"

void palette_init(Palette *p){
  p->count = 0;
}

void palette_add(Palette *p, Color c){
  p->colors[p->count] = c;
  p->count++;
}

void palette_remove(Palette *p, int index){
  if(index < 0 || index >= p->count){
    return;
  }
  for(int i = index; i < p->count - 1; i++){
    p->colors[i] = p->colors[i + 1];
  }
  p->count--;
}

int palette_count(const Palette *p){
  return p->count;
}

Color palette_get(const Palette *p, int index){
  if(index < 0 || index >= p->count){
    return BLACK;
  }
  return p->colors[index];
}
