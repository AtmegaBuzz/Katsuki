#ifndef __UTILS_H
#define __UTILS_H
#include <gtk/gtk.h>

extern GdkColor RED_COLOR;
extern GdkColor GREEN_COLOR;
extern GdkColor BLUE_COLOR;
extern GdkColor BLACK_COLOR;
extern GdkColor WHITE_COLOR;
extern GdkColor LIGHT_BLUE_COLOR;
extern GdkColor LIGHT_YELLOW_COLOR;

void initColorScheme();

int relativeDimension(GtkWidget *window,int dimension,int percentage);

#endif
