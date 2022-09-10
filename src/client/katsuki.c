#include <gtk/gtk.h>
#include <pthread.h>
#include <string.h>
#include "utils.h"
#include "client.h"

#define BUFFER_LEN 1024
#define SERVER_IP "127.0.0.1"
#define PORT 9999


GtkWidget *messageEntry;
GtkWidget *submitBtn ;

struct IP_PORT *config_bind;


void submitMessage(GtkWidget *wid, gpointer data);

void topSection(GtkWidget *root, int WIDTH, int HEIGHT);

void displayChatSection(GtkWidget *root, int WIDTH, int HEIGHT);

void messagingSection(GtkWidget *root, int WIDTH, int HEIGHT);

int main(int argc, char **argv)
{

    char *SEND_BUFFER = (char *) malloc(sizeof(char)*BUFFER_LEN);
    bzero(SEND_BUFFER,BUFFER_LEN);

    config_bind = (struct IP_PORT*) malloc(sizeof(struct IP_PORT));
    config_bind->ip = SERVER_IP;
    config_bind->port = PORT;
    config_bind->buffer = SEND_BUFFER;
    config_bind->buffer_len = BUFFER_LEN;

    // init client 

    pthread_t client_t;
    pthread_create(&client_t,NULL,&client_awk,(void*)config_bind);

    // init gui 

    initColorScheme();

    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 700);
    gtk_window_set_title(GTK_WINDOW(window), "TOP APP");
    gtk_window_set_resizable(window, FALSE);
    // making root
    GtkWidget *root = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_container_add(GTK_CONTAINER(window), root);

    topSection(
        root,
        relativeDimension(window, 0, 100),
        relativeDimension(window, 1, 5));
    displayChatSection(
        root,
        relativeDimension(window, 0, 100),
        relativeDimension(window, 1, 80));
    messagingSection(
        root,
        relativeDimension(window, 0, 100),
        relativeDimension(window, 1, 15));

    gtk_widget_show_all(window);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();
}


void submitMessage(GtkWidget *wid, gpointer data)
{
    const gchar *submitData = gtk_entry_get_text(GTK_ENTRY(messageEntry));
    strncpy(config_bind->buffer,(char*)submitData,BUFFER_LEN);
    printf("%s \n", submitData);
    gtk_entry_set_text(GTK_ENTRY(messageEntry),"");
}

void topSection(GtkWidget *root, int WIDTH, int HEIGHT)
{

    // heading section
    GtkWidget *topHeading = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_widget_modify_bg(GTK_WIDGET(topHeading), GTK_STATE_NORMAL, &LIGHT_YELLOW_COLOR);
    gtk_widget_set_size_request(
        GTK_WIDGET(topHeading),
        WIDTH,
        HEIGHT);
    gtk_box_pack_start(GTK_BOX(root), topHeading, 1, 1, 1);

    GtkWidget *heading = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(heading), "<b>Katsuki</b> Chat");
    gtk_widget_modify_fg(GTK_WIDGET(heading), GTK_STATE_NORMAL, &BLACK_COLOR);
    gtk_box_pack_start(GTK_BOX(topHeading), heading, 1, 1, 1);
}

void displayChatSection(GtkWidget *root, int WIDTH, int HEIGHT)
{

    // making top display
    GtkWidget *displayBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    GtkWidget* textArea = gtk_text_view_new();
    GtkWidget* scrolledwindow = gtk_scrolled_window_new(NULL, NULL);

    gtk_widget_modify_bg(displayBox, GTK_STATE_FLAG_NORMAL, &LIGHT_YELLOW_COLOR);
    gtk_widget_modify_bg(scrolledwindow, GTK_STATE_FLAG_NORMAL, &LIGHT_BLUE_COLOR);

    gtk_widget_set_size_request(GTK_WIDGET(displayBox), 100, 500);
    gtk_widget_set_size_request(
        GTK_WIDGET(displayBox),
        WIDTH,
        HEIGHT);
    gtk_container_add(GTK_CONTAINER(scrolledwindow), textArea);
    gtk_box_pack_start(GTK_BOX(root), displayBox, 1, 1, 0);

}

void messagingSection(GtkWidget *root, int WIDTH, int HEIGHT)
{

    // making bottom messaging
    GtkWidget *bottomBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    // gtk_widget_modify_bg(bottomBox,GTK_STATE_FLAG_NORMAL,&BLUE_COLOR);
    gtk_widget_set_size_request(
        GTK_WIDGET(bottomBox),
        WIDTH,
        HEIGHT);
    gtk_box_pack_end(GTK_BOX(root), bottomBox, 1, 1, 2);

    // message entry
    messageEntry = gtk_entry_new();
    submitBtn = gtk_button_new_with_label("<--");
    g_signal_connect(submitBtn, "clicked", G_CALLBACK(submitMessage), NULL);

    gtk_entry_set_placeholder_text(GTK_ENTRY(messageEntry), "message");
    // gtk_widget_set_size_request(
    //     GTK_WIDGET(messageEntry),
    //     (WIDTH/100)*90,
    //     (HEIGHT/100)*70
    // );
    gtk_box_pack_start(GTK_BOX(bottomBox), messageEntry, 1, 1, 0);
    gtk_box_pack_end(GTK_BOX(bottomBox), submitBtn, 0, 0, 0);
}
