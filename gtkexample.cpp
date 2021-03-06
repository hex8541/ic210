/* gtkexample.cpp
 * Example program to draw a line on an 800x800 window using GTK+
 */

#include <iostream>
using namespace std;

#include <gtk/gtk.h>

struct Node
{
  int x;
  int y;
  Node* next;
};

/* This is the function that opens the window once GTK starts up. */
void activate (GtkApplication* app, gpointer user_data);

/* This is the function that actually draws the lines (or anything else).
 * It gets called when the window is displayed to the user.  */
void on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data);

int main () {
  // set up data
  Node* tail = new Node{100, 200, NULL};
  Node* middle = new Node{200, 200, tail};
  Node* head = new Node{300, 300, middle}; 

  // you have to make an "application" that has some arbitrary name
  GtkApplication *app = gtk_application_new ("my.awesome.app", G_APPLICATION_FLAGS_NONE);

  // tell GTK what function to call when the application starts
  g_signal_connect(app, "activate", G_CALLBACK(activate), head);

  // this line is printed just BEFORE the window pops up.
  cout << "start" << endl;

  // show the actual window and wait until the user closes it...
  g_application_run (G_APPLICATION (app), 0, NULL);

  // this line is printed just AFTER the window pops up.
  printf("done\n");

  // cleanup time
  g_object_unref(app);

  delete head;
  delete middle;
  delete tail;

  return 0;
}

/* This is the function that actually draws the lines (or anything else).
 * It gets called when the window is displayed to the user.  */
void on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
  // set the line color to blue and line width to 2 points
  cairo_set_source_rgb(cr, 0,0,255);
  cairo_set_line_width(cr, 2.0);

  // to draw, you move the "cursor" somewhere first...
  Node* L = (Node*) user_data; 
  cairo_move_to(cr, L->x, L->y);

  // and then call cairo_line_to to draw a line to wherever you want
  for(Node* t = L->next; t != NULL; t = t->next)
    cairo_line_to(cr, t->x, t->y);

  // the path you made isn't actually drawn until you call cairo_stroke.
  cairo_stroke(cr);
}

/* This is the function that opens the window once GTK starts up. */
void activate (GtkApplication* app, gpointer user_data) {
  // create the window and give it a title
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title (GTK_WINDOW (window), "Map");

  // make a drawing canvas inside the window
  GtkWidget *drawing_area = gtk_drawing_area_new ();
  gtk_widget_set_size_request (drawing_area, 800, 800);
  gtk_container_add(GTK_CONTAINER(window), drawing_area);

  // tell GTK what function to call to draw the window
  g_signal_connect(G_OBJECT(drawing_area), "draw",
            G_CALLBACK(on_draw_event), user_data);

  // well you don't want your beautiful window to be hidden do you?
  gtk_widget_show_all(window);
}

