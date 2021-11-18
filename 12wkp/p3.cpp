//Nicholas Heil 242628
//Practicum part 3

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  //input
  string file;
  cout << "filename: ";
  cin >> file;
  fstream fin(file);

  //initialize and create grid arrays
  int st, ave;
  string junk;
  fin >> st >> junk >> ave >> junk;
  int** Crashes = new int*[ave];
  for(int i=0; i < ave; i++)
    Crashes[i] = new int[st];
  
  //Read in to grid, characters
  char cSt, cAve, j;
  while (fin >> cSt){
    int col, row;
    col = cSt - 65;
    fin >> j >> cAve >> j >> j;
    row = cAve - 49;
    Crashes[row][col]++;
  }

  //output grid
  char letter = 'A';
  cout << "   ";
  for (int i=0; i < st; i++)
    cout << char(letter + i) << " ";
  for (int i =1; i <= ave; i++){
    cout << "\n" << i << ": ";
    for (int j=0; j < st; j++)
      cout << Crashes[i-1][j] << " ";
  }
   

  //delete and exit
  for(int i=0; i < st; i++)
    delete [] Crashes[i];
  delete [] Crashes;
  return 0;
}
