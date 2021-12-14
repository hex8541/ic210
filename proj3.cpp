//Nicholas Heil 242628

#include "proj3.h"

//adds a new term to front of list
Node* add2front(double Lat, double Lon, time_t Time, Node* list){  Waypoint New; //creates a new waypoint for the node being created
  //assign values given to function
  New.co.lat = Lat;
  New.co.lon = Lon;
  New.time = Time; 
  Node* a = new Node{New, list};
  return a;
}

//stats
void Stats(Node* L, int i) //list and index
{
  //initialize necessary variables
  double tot=0;
  time_t prevtime = L->data.time;
  gpsco prevloc = L->data.co; //previous location
  double dist=0; //distance traveled
  //find total distance traveled and time elapsed in one iteration
  Node* temp = L;
  for(int j=0; j < i; j++){
    temp = temp->next;
    if(temp->next == NULL){
      break; //add a break condition to prevent crashes
    }
    dist = dist + gps_dist(prevloc, temp->data.co); //add up distance traveled
    tot = tot + difftime(temp->data.time, prevtime);
    prevloc = temp->data.co; //previous location
    prevtime = temp->data.time; //previous time
  }
  int hour=0, min=0, sec=0;
  if(tot >= 3600){ //over an hour
    hour = int(tot)/3600;
    min = int(tot)%3600;
    min = min/60;
    sec = min%60;
  }
  else{
    min = int(tot)/60;
    sec = min%60;
  }
  //calculate and output total time elapsed
  cout << "Total time: ";
  if(hour > 0) //add hours if present
    cout << hour << " hours, ";
  cout << min << " minutes, " << sec <<" seconds" << endl;

  //output total distance traveled
  cout << "Total distance: " << dist << " miles" << endl;

  //calculate and output average speed (mph)
  double speed = dist/tot;
  cout << "Average speed: " << speed << " mph" << endl;

  //calculate and output average pace (min/sec per mile)
  double totpace = tot/dist;
  min = int(totpace)/60;
  cout << "Average pace: " << min << " minutes, " << totpace-double(min)
    << " seconds per mile" << endl;

  return;
}

void landmarks(Node* L, int i)
{
  //read in landmarks file
  string file;
  cin >>file;
  ifstream fin(file);
  if(!fin){ //invalid filename
    cout << "Error! File not found!" << endl;
    return;
  }
  //save landmarks in an array
  int size;
  fin >> size; //read in number of landmarks
  landmark* Landmarks = new landmark[size]; 
  for(int j=0; j < size; j++)
    fin >> Landmarks[j].co.lat >> Landmarks[j].co.lon >> Landmarks[j].name;
  
  //find shortest distance to each landmark and add that to each struct
  for(int j=0; j < size; j++){
    double shortest=0, curr=0;
    for(Node* t=L; t->next != NULL; t=t->next){
      curr = gps_dist(t->data.co, Landmarks[j].co);
      if(shortest == 0 || curr < shortest) //find shortest value
        shortest = curr;
    }
    Landmarks[j].shortest = shortest; //save shortest value
  }
  
  //sort landmarks by shortest distance
  selection_sort(Landmarks, size);

  //output landmarks
  for(int j=0; j < size; j++){
    cout << Landmarks[j].name << " " << Landmarks[j].shortest 
      << " miles" << endl;
  }
  
  return;
}

void selection_sort(landmark* A, int n) {  
  for (int i = 0; i < n - 1; ++i) {
    // find nexti, the index of the next element
    int nexti = i;
    for (int j = i + 1; j < n; ++j) {
      if (before(A[j].shortest, A[nexti].shortest)) {
        nexti = j;
      }
    }
    // swap A[i] and A[nexti]
    landmark temp = A[i];
    A[i] = A[nexti];
    A[nexti] = temp;
  }
}

bool before(double a, double b)
{
  return a < b;
}

void on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
  // set the line color to blue and line width to 2 points
  cairo_set_source_rgb(cr, 0,0,255);
  cairo_set_line_width(cr, 2.0);

  // to draw, you move the "cursor" somewhere first...
  Node* L = (Node*) user_data; 
  cairo_move_to(cr, L->data.co.lat, L->data.co.lon);

  // and then call cairo_line_to to draw a line to wherever you want
  for(Node* t = L->next; t != NULL; t = t->next)
    cairo_line_to(cr, t->data.co.lat, t->data.co.lon);

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

