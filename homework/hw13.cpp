//Nicholas Heil 242628
//Draw rectangles with inputs for height, width, and offset.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{ 
  //Gather input from user
  int h=0, w=0, off=0;
  cout << "Enter height (greater than 2): ";
  cin >> h;
  cout << "\nEnter width (greater than 2): ";
  cin >> w;
  cout << "\nEnter offset: ";
  cin >> off;

  //Draw rectangle
  for (int i=1; i <= h; i++){  //initialize 1 for conditionals to work
    if (i == 1 || i == h){ //Draw first and last rows
      for (int k=0; k < off; k++)  //Offset
        cout << " ";
      for (int k=0; k < w; k++)
        cout << "*";
    cout << endl;
    }
    else { //Draw a normal row
      for (int k=0; k < off; k++)
        cout << " ";
      cout << "*";
      for (int k=0; k < (w-2); k++)
        cout << " ";
      cout << "*" << endl;
    } 
  } 
}

