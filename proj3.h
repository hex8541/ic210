//Nicholas Heil 242628

#ifndef PROJ3_HEADER
#define PROJ3_HEADER

#include <ctime> //for time comparisons
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

struct Waypoint{
  double lat, lon;
  time_t time;
};

struct Node{
  Waypoint data;
  Node* next;
};

Node* add2front(double Lat, double Lon, time_t Time, Node* list);

#endif
