//Nicholas Heil 242628
//Print out contents by pixel for a ppm image

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  //Ask for input
  string file;
  cout << "Input file: ";
  cin >> file;
  ifstream fin(file);

  if (!fin){  //Check that file can be read
    cout << "Invalid file!" << endl;
    return 1;
  }

  //Read the file
  string header;
  int w, h, max, v;
  int row = 0, col = 0;  //Row and column
  int r = 0, g = 0, b = 0;
  fin >> header >> w >> h >> max;  //Read unique values separately
  //Outputs separate from cycle
  cout << header << endl << "width = " << w << ", height = " << h << endl;
  cout << "max value = " << max << endl;
  cout << "*** row 0 ***" << endl;

  while (fin){
    //Cycle through each row
    while (row < h){
      if (col < w){  //For each row, work through each column one by one
      fin >> r >> g >> b;
      cout << "row " << row << ", col " << col << ": r" << r;
      cout << " g" << g << " b" << b << endl;
      col++;
      }
      else {  //When each row finishes, reset col and advance row
        col = 0;
        row++;
        if (!(row == h))  //only outputs if there will be a new row
        cout << "*** row " << row << " ***" << endl;
      }
    }
    return 0;
  }
}
