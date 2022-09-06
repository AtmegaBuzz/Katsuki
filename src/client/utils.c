#include <gtk/gtk.h>



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



int relativeDimension(GtkWidget *window,int dimension,int percentage){
    
    /* 
        returns dimension relative to parent window
        Window -> refrence to window obj
        dimension:
            0 -> WIDTH
            1 -> HEIGHT

         
    */
    int WIDTH;
    int HEIGHT;
    gtk_window_get_size(GTK_WINDOW(window),&WIDTH,&HEIGHT);

    switch (dimension){
        case 0:
            return (WIDTH/100)*percentage;
        case 1:
            return (HEIGHT/100)*percentage;
        default:
            return -1;
    }

    return -1;    
}

