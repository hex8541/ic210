//Nicholas Heil 242628
//Practicum part 1

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct point
{
  double x;
  double y;
};

bool distance(point* A, int i, double len);

int main()
{
  //Input, file and length
  string filename;
  cout << "File: ";
  cin >> filename;
  fstream fin(filename);
  double len;
  cout << "Length: ";
  cin >> len;

  //Read file
  int size; 
  string junk;
  fin >> size;
  point* pts = new point[size];
  fin >> junk;
  for(int i=0; i < size; i++)
    fin >> pts[i].x;  //x values
  fin >> junk;
  for(int i=0; i < size; i++)
    fin >> pts[i].y;  //y values
  
  //Find points and return
  for(int i=0; i < size; i++){
    if(distance(pts, i, len))
      cout << "(" << pts[i].x << "," << pts[i].y << ") ";
  }


  delete []pts;
  return 0;
}

bool distance(point* A, int i, double len)
{
  double dist, goal;
  goal = len*len;
  dist = (A[i].x * A[i].x) + (A[i].y * A[i].y);
  if (dist > goal)
    return true;
  return false;
}
