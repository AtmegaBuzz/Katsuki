#include <gtk/gtk.h>

GdkColor RED_COLOR;
GdkColor GREEN_COLOR;
GdkColor BLUE_COLOR;
GdkColor BLACK_COLOR;
GdkColor WHITE_COLOR;



void initColorScheme(){
    gdk_color_parse("#ff0000",&RED_COLOR);
    gdk_color_parse("#33cc33",&GREEN_COLOR);
    gdk_color_parse("#0000e6",&BLUE_COLOR);
    gdk_color_parse("#000000",&BLACK_COLOR);
    gdk_color_parse("#ffffff",&WHITE_COLOR);

}

int relativeDimension(GtkWidget &window,int dimension,int percentage){
    
    /* 
        returns dimension relative to parent window
        Window -> refrence to window obj
        dimension:
            0 -> HEIGHT
            1 -> WIDTH

         
    */

    int WIDTH;
    
}


int main (int argc,char** argv){

    initColorScheme();

    gtk_init(&argc,&argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window),500,700);
    gtk_window_set_title(GTK_WINDOW(window),"TOP APP");
    
    // making root
    GtkWidget *root = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);

    gtk_container_add(GTK_CONTAINER(window),root);
    gtk_widget_modify_bg(GTK_WIDGET(root),GTK_STATE_FLAG_NORMAL,&RED_COLOR);

    // heading section 
    GtkWidget *topHeading = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    gtk_widget_modify_bg(GTK_WIDGET(topHeading),GTK_STATE_NORMAL,&BLUE_COLOR);
    gtk_widget_set_size_request(GTK_WIDGET(topHeading),100,10);
    gtk_box_pack_start(GTK_BOX(root),topHeading,1,1,0);

    GtkWidget *heading = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(heading),"<b>Katsuki</b> Chat");
    gtk_widget_modify_fg(GTK_WIDGET(heading),GTK_STATE_NORMAL,&BLACK_COLOR);
    gtk_box_pack_start(GTK_BOX(topHeading),heading,1,1,1);



    // making top display
    GtkWidget *displayBox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    gtk_widget_modify_bg(displayBox,GTK_STATE_FLAG_NORMAL,&GREEN_COLOR);
    gtk_widget_set_size_request(GTK_WIDGET(displayBox),100,500);
    gtk_box_pack_start(GTK_BOX(root),displayBox,0,0,10);
    
    // making bottom messaging 
    GtkWidget *bottomBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    gtk_widget_modify_bg(bottomBox,GTK_STATE_FLAG_NORMAL,&BLUE_COLOR);
    gtk_widget_set_size_request(GTK_WIDGET(bottomBox),100,100);
    gtk_box_pack_end(GTK_BOX(root),bottomBox,1,1,2);
    
    gtk_widget_show_all(window);

    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_main();



}