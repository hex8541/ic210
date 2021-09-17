//Nicholas Heil 242628
//Draw a histogram based on numeric inputs from a file read by the program

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{ 
  //Gather input
  string file; 
  cout << "Enter a filename: ";
  cin >> file;
  ifstream fin(file);

  //Check that filename is valid
  if (!fin){
    cout << "Invalid filename" << endl;
    return 1;
  }

  //Data processing
  int row1 = 0, row2 = 0, c = 0;  //c = current
  while (fin >> c){
    if (c > 19)
      row2++;
    else 
      row1++;
  }
<<<<<<< HEAD
  //Output 
  cout << adult << " adults and " << children << " children" << endl;
}
=======
>>>>>>> e832c1e14828d0670f0dc3c9403e275de8b3691c

  //Draw histogram
  cout << "[10,19]: ";
  while (row1 > 0){
    cout << "*";
    row1--;
  }
  cout << "\n[20,29]: ";
  while (row2 > 0){
    cout << "*";
    row2--;
  }
}

