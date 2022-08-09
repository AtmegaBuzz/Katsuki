#include <gtk/gtk.h>
#include "colors.h"



void initColorScheme(){
    gdk_color_parse("#ff0000",&RED_COLOR);
    gdk_color_parse("#33cc33",&GREEN_COLOR);
    gdk_color_parse("#0000e6",&BLUE_COLOR);
    gdk_color_parse("#000000",&BLACK_COLOR);
    gdk_color_parse("#ffffff",&WHITE_COLOR);

}
