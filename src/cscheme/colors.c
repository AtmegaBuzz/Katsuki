#include <gtk/gtk.h>
#include "colors.h"

GdkColor RED_COLOR;
GdkColor GREEN_COLOR;
GdkColor BLUE_COLOR;
GdkColor BLACK_COLOR;
GdkColor WHITE_COLOR;

GdkColor LIGHT_BLUE_COLOR;
GdkColor LIGHT_YELLOW_COLOR;


void initColorScheme(){
    gdk_color_parse("#ff0000",&RED_COLOR);
    gdk_color_parse("#33cc33",&GREEN_COLOR);
    gdk_color_parse("#0000e6",&BLUE_COLOR);
    gdk_color_parse("#030e12",&BLACK_COLOR);
    gdk_color_parse("#ffffff",&WHITE_COLOR);
    gdk_color_parse("#5bccf6",&LIGHT_BLUE_COLOR);
    gdk_color_parse("#fcde67",&LIGHT_YELLOW_COLOR);


}
