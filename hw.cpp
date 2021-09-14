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
  int adult, children, mm, dd;
  char y1, y2;
  mm = 0, dd = 0;  //Initialize variables
  adult = 0, children = 0;
  char j;
  cout << "Filename: ";
  cin >> file;
  ifstream fin("file");

  //Use loop to sort through all data in file
  while(fin){
    cin >> junk >> mm >> j >> dd >> j >> y1 >> y2;
    if(y1 >= '2' && y2 >= '2'){
      adult = adult + 1;
    }
    else if (y1 == '0' && y2 == '0' && mm >= 9 && dd >= 27){ 
      adult = adult + 1;
    }
      else 
        children = children + 1;
  }
  //Output 
  cout << adult << " adults and " << children << " children" << endl;
}


