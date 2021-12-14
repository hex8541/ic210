//Nicholas Heil 242628

#ifndef PROJ3_HEADER
#define PROJ3_HEADER

#include <string>
#include <fstream>
#include <iostream>
#include <gtk/gtk.h>
#include "gps.h" //included here so that gpsco struct from gps.h can be used
using namespace std;

struct Waypoint{
  gpsco co;
  time_t time;
};

struct landmark{
  gpsco co;
  string name;
  double shortest; //store as part of struct for ease of sorting
};

struct Node{
  Waypoint data;
  Node* next;
};

Node* add2front(double Lat, double Lon, time_t Time, Node* list);
void Stats(Node* L, int i); //calculate and output relevant statistics
void landmarks(Node* L, int i);
bool before(double a, double b); //used to compare  shortest distances
void selection_sort(landmark* A, int n); //sort the landmarks by shortest distance
void activate (GtkApplication* app, gpointer user_data);
void on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data);

#endif
