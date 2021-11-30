//Nicholas Heil 242628
//Determine if adult or child based on birthday from text file.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{ 
  //Gather input and setup
  string file, junk;
  int adult, children, m, d, y;
  m = 0, d = 0, y = 0;  //Initialize variables
  adult = 0, children = 0;
  char j;
  cout << "Filename: ";
  cin >> file;
  ifstream fin(file);

  //Use loop to sort through all data in file
  while(fin){
    cin >> junk >> m >> j >> d >> j >> y;

    if(y >= 21){
      adult = adult + 1;
    }
    else if (y == 0 && m >= 9 && d >= 27){ 
      adult = adult + 1;
    }
      else 
        children = children + 1;
  }
  //Output 
  cout << adult << " adults and " << children << " children" << endl;
  return 0;
}


