#ifndef PALETTE_H
#define PALETTE_H
#include <raylib.h>

#define MAX_COLORS 32

typedef struct{
  Color colors[MAX_COLORS];
  int count;
} Palette;

void palette_init(Palette *p);
void palette_add(Palette *p, Color c);
void palette_remove(Palette *p, int index);
int palette_count(const Palette *p);
Color palette_get(const Palette *p, int index);


#endif
