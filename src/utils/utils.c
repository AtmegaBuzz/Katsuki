#include <gtk/gtk.h>


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
    printf("%d %d %d|",WIDTH,HEIGHT,percentage);

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

