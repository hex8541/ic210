//Nicholas Heil 242628
//Vertically shift an image that is superimposed on another image

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
  //Ask for input
  string fore, back, out;
  int rs; //Row Shift
  cout << "Foreground file: ";
  cin >> fore;
  cout << "Background file: ";
  cin >> back;
  cout << "Row shift: ";
  cin >> rs;
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
  int row = 0, row2=0, col = 0, col2=0;  //Row and column for both images
  int r = 0, g = 0, b = 0, r2 = 0, g2 = 0, b2 = 0;
  fin1 >> header >> w >> h >> max;  //Read unique values separately
  fin2 >> header >> w2 >> h2 >> max2;  //Read info for background img

  //Outputs file header
  fout << header << endl << w2 << " " << h2 << endl << max2 << endl;
  
  //Apply rowshift in reading of first file
/*  for(int i = 0; i < rs; i++){
    while (row2 < rs){
      if (col2 < w2){
        fin2 >> r2 >> g2 >> b2;
        fout << r2 << g2 << b2;
        //if (r != 0 || g != 255 || b != 0){  //Check that image fits
         // cout << "Error: The foreground goes past the background";
         // exit(1);
        //}
        col2++;
      }
      else {
        col2 = 0;
        row2++;
      }
    }
    cout << i << endl;
  }
*/
  while (fin1){
    //Cycle through each row
    while (row < h){
      if (col < w){  //For each row, work through each column one by one
        fin1 >> r >> g >> b;
        fin2 >> r2 >> g2 >> b2;
        if (r == 0 && g == 255 && b ==0)  //Green background
          fout << r2 << " " << g2 << " " << b2 << " ";
        else  //Output non-green image
          fout << r << " " << g << " " << b << " ";
        col++;
        col2++;
        cout << '2';
      }

      //When each row finishes, reset col and advance row
      else while (col2 < w2){  //Finish reading background image for each row
        fin2 >> r2 >> g2 >> b2;
        fout << r2 << g2 << b2;
        col2++;
        cout << '3';
      }
      if(col2 ==  w2){
        col2 = 0;
        row2++;
      }  
      col = 0;
      row++;
    }
  }

  while (fin2){ //output the rest of the background image
    while (row2 < h2){
      if (col2 < w2){
        fin2 >> r2 >> g2 >> b2;
        fout << r2 << g2 << b2; 
        cout << "I'm here" << endl;
        col++;
      }
      else {
        col2 = 0;
        row2++;
      }
    }
  }

  cout << "Image saved to " << out << endl;
  return 0;
}
