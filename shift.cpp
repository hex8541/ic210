//Nicholas Heil 242628
//Shift an image vertically and horizontally while superimposed over background

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
  //Ask for input
  string fore, back, out;
  int rs, cs; //Row Shift, Column Shift
  cout << "Foreground file: ";
  cin >> fore;
  cout << "Background file: ";
  cin >> back;
  cout << "Row shift: ";
  cin >> rs;
  cout << "Column shift: ";
  cin >> cs;
  cout << "Output file: ";
  cin >> out;
  ifstream fin1(fore);
  ifstream fin2(back);
  ofstream fout(out);

  if (!fin1 || !fin2){  //Check that files can be read
    cout << "Error: Input file not found" << endl;
    return 1;
  }

 //Read the files
  string header;
  int w, h, max, v, h2, w2, max2;
  int row = 0, col = 0;  //Row and column
  int r = 0, g = 0, b = 0, r2 = 0, g2 = 0, b2 = 0;
  fin1 >> header >> w >> h >> max;  //Read unique values separately
  fin2 >> header >> w2 >> h2 >> max2;  //Read info for background img
  int cRow = (rs + h);  //Find cutoff row, after which only fout is background
  int cCol = (cs + w);  //Find cutoff column, where foreground img ends

  //Determine if row or column shift is too large to fit
  if (cRow > h2 || cCol > w2){
    cout << "Error: The foreground goes past the background";
    exit(1);
  }
  
  //Outputs file header
  fout << header << endl << w2 << " " << h2 << endl << max2 << endl;

  
  //Output pixels from background equal to rows shifted
  for (row; row < rs; row++){
    while (col < w2){
      fin2 >> r2 >> g2 >> b2;  //Read from background file
      fout << r2 << " " << g2 << " " << b2 << " ";  //Output to new image
      col++;
    }
    col = 0;
  }

  for (row; row < cRow; row++){  //Continues until cutoff is reached
    while (col < cs){  //Output columns shifted from background
      fin2 >> r2 >> g2 >> b2;
      fout << r2 << " " << g2 << " " << b2 << " ";
      col++;
    } 
    while (col < cCol){  //Greenscreen processing for primary image
      fin1 >> r >> g >> b;
      fin2 >> r2 >> g2 >> b2;
      if (r == 0 && g == 255 && b ==0)  //Green background
          fout << r2 << " " << g2 << " " << b2 << " ";
      else  //Output non-green image
          fout << r << " " << g << " " << b << " ";
      col++; 
    }
    while (col < w2){  //Output remainder of row from background
      fin2 >> r2 >> g2 >> b2;
      fout << r2 << " " << g2 << " " << b2 << " ";
      col++;
    }
    col = 0;
  }
  
  //Output the remainder of the background file image
  for (row; row < h2; row++){
    while (col < w2){
      fin2 >> r2 >> g2 >> b2;  //Read from background file
      fout << r2 << " " << g2 << " " << b2 << " ";  //Output to new image
      col++;
    }
    col = 0;
  }
  cout << "Image saved to " << out << endl;
  return 0;
}
