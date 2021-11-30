//Nicholas Heil 242628

#include "proj3.h"

//adds a new term to front of list
Node* add2front(double Lat, double Lon, time_t Time, Node* list){ 
  Waypoint New; //creates a new waypoint for the node being created
  //assign values given to function
  New.lat = Lat;
  New.lon = Lon;
  New.time = Time; 
  Node* a = new Node{New, list};
  return a;
}
