#include <gtk/gtk.h>
#include "cscheme/colors.h"
#include "utils/utils.h"


// void topSection(GtkWidget **root){

//     // heading section 
//     GtkWidget *topHeading = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
//     gtk_widget_modify_bg(GTK_WIDGET(topHeading),GTK_STATE_NORMAL,&BLUE_COLOR);
//     gtk_widget_set_size_request(
//         GTK_WIDGET(topHeading),
//         relativeDimension(root,0,100),
//         relativeDimension(root,0,10)
//     );
//     gtk_box_pack_start(GTK_BOX((**root)),topHeading,1,1,0);

//     GtkWidget *heading = gtk_label_new(NULL);
//     gtk_label_set_markup(GTK_LABEL(heading),"<b>Katsuki</b> Chat");
//     gtk_widget_modify_fg(GTK_WIDGET(heading),GTK_STATE_NORMAL,&BLACK_COLOR);
//     gtk_box_pack_start(GTK_BOX(topHeading),heading,1,1,1);

// }

void displayChatSection(GtkWidget *root){

    // making top display
    GtkWidget *displayBox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    gtk_widget_modify_bg(displayBox,GTK_STATE_FLAG_NORMAL,&GREEN_COLOR);
    gtk_widget_set_size_request(GTK_WIDGET(displayBox),100,500);
    gtk_widget_set_size_request(
        GTK_WIDGET(displayBox),
        relativeDimension(root,0,100),
        relativeDimension(root,1,60)
    );
    gtk_box_pack_start(GTK_BOX(root),displayBox,0,0,5);


}

void messagingSection(GtkWidget *root){

     // making bottom messaging 
    GtkWidget *bottomBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    gtk_widget_modify_bg(bottomBox,GTK_STATE_FLAG_NORMAL,&BLUE_COLOR);
    // printf("%d %d",relativeDimension(root,0,100),relativeDimension(root,0,30));
    gtk_widget_set_size_request(
        GTK_WIDGET(bottomBox),
        relativeDimension(root,0,100),
        relativeDimension(root,1,100)
    );
    gtk_box_pack_end(GTK_BOX(root),bottomBox,0,0,2);
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
    
    // topSection(&root);
    // displayChatSection(root);
    messagingSection(root);


    gtk_widget_show_all(window);
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_main();



}