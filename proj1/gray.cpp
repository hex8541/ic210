//Nicholas Heil 242628
//Apply grayscale effect to an image
//I continued using the "typewriter" mechanism from my first program to process
//the input files.

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
  //Ask for input
  string file, out;
  cout << "Input file: ";
  cin >> file;
  cout << "Output file: ";
  cin >> out;
  ifstream fin(file);
  ofstream fout(out);

  if (!fin){  //Check that file can be read
    cout << "Error: Input file not found" << endl;
    return 1;
  }

  //Read the file
  string header;
  int w, h, max, v;
  int row = 0, col = 0;  //Row and column
  int r = 0, g = 0, b = 0;
  double avg = 0;
  fin >> header >> w >> h >> max;  //Read unique values separately
  //Outputs file header
  fout << header << endl << w << " " << h << endl << max << endl;

  while (fin){
    //Cycle through each row
    while (row < h){
      if (col < w){  //For each row, work through each column one by one
      fin >> r >> g >> b;
      //Change values to grayscale variants
      avg = (r + g + b)/3;
      r = avg, g = avg, b = avg;

      fout << r << " " << g << " " << b << " ";
      col++;
      }
      else {  //When each row finishes, reset col and advance row
        col = 0;
        row++;
      }
    }
    cout << "Image saved to " << out << endl;
    return 0;
  }
}
