//Nicholas Heil 242628
//Print out total number of words in a file and average word length

#include <string>
#include <iostream>
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
  if(!fin){
    cout << "Invalid filename" << endl;
    return 1;
  }
  
  //Count words in file and save data to calculate average length
  string w;  //current word
  double avg = 0, tot = 0, length = 0;
  int wordCount = 0; 
  while(fin >> w){  //Ends loop without counting last word twice
    length = w.length();  //Determine length of current word
    tot = tot + length;  
    wordCount++;
  }    

  //Output
  avg = tot / wordCount;  //Calculate average
  cout << "\nWord count: " << wordCount << endl;
  cout << "Average word length: " << avg << endl;
  
  return 0;
}

