//Nicholas Heil 242628
//Read a file given by user, then search within the file for protocols

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

bool QuitSearch();  //Asks user what they want to do, true for search
string Capitalize(string a);  //Capitalizes string if in lowercase

int main()
{
  //Gather input
  string filename;
  cout << "What file? ";
  cin >> filename;
  ifstream fin(filename);
  
  //Create array and read in
  int size;
  fin >> size; //Read in number of connections logged
  string* protocol = new string[size];
  for(int i = 0; i < size; i++){
    string junk;  //Used to skip first pieces of information on each line
    fin >> junk >> junk >> junk >> junk >> protocol[i] >> junk;
  }
  
  //Quit or Search
  while(QuitSearch()){  //Stops running when QuitSearch doesn't return S
    string search;
    cout << "Protocol? ";
    cin >> search;  //Search parameter
    //Capitalizing search allows for case insensitive searches
    string CSearch = Capitalize(search);  //capitalize search term if lowercase
    bool found=false; //initialize
    for(int i=0; found != true; i++){
      if(protocol[i] == CSearch){  //Returns current index if term found
        cout << "Index " << i << " protocol " << CSearch << endl << flush;
        found = true;
      }
      else if(i == size-1){  //Haven't found search term by end of array
        cout << "Array size " << size << " Protocol not found" << endl << flush;
        found = true;  //Allows loop to end before segmentation fault
      }
    }
  }

  delete [] protocol;  //delete array
  return 0;
}

bool QuitSearch()  //Asks user what they want to do, true for search
{
  cout << "(Q)uit or (S)earch? ";
  char c;
  cin >> c; 
  if (c == 'S')
    return true;
  return false;
}

string Capitalize(string a)
{
  int Wlength = a.length();
  if(a[0] > 90){ //if a lowercase letter, assume rest are lowercase
    for(int i=0; i < Wlength; i++)
      a[i] = a[i] - 32;
    return a;
  }
  else
    return a;
}
