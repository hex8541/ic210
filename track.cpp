/* track.cpp: GPS tracks program main program
 * Nicholas Heil 242628
 * This is where you will write your main() for the entire project.
 */

#include "gps.h"
#include "proj3.h"

int main()
{
  //Receive user input and read in file
  string file;
  cout << "File: ";
  cin >> file;
  ifstream fin(file);
  if(!fin){ //invalid filename
    cout << "Error! File not found!" << endl;
    return 1;
  }
  //Read in waypoints to linked list
  tm curr = {}; 
  int points, y=0, mo=0, index=0;
  double Lat=0, Lon=0;
  fin >> points; //read in number of waypoints
  char j; //for punctuation in input lines 
  Node* list = new Node;
  while(fin >> Lat){
    fin >> Lon >> y >> j >> mo >> j >> curr.tm_mday >> curr.tm_hour >> j >>
      curr.tm_min >> j >> curr.tm_sec;
    curr.tm_year = y-1900;  //years since 1900
    curr.tm_mon = mo-1; //months since Jan
    time_t temp = mktime(&curr);
    list = add2front(Lat, Lon, temp, list);
    index++;
  }
  cout << "Opened " << file << " with " << index << " waypoints" << endl;

  //Execute commands
  string com = "f";
  while (com != "quit"){
    cout << "command: ";
    cin >> com;
    if(com == "linked")
      cout << "yes" << endl;
  }

  //Clear out file, delete lists 
  return 0;

}

