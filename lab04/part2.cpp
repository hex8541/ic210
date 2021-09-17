//Nicholas Heil 242628
//Find the length of a sentence, total number of words, and avg word length

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
  
  //Count words and sentences in file and save this data
  string w;  //current word
  double avgW = 0, totW = 0, lengthW = 0;  //For word stats
  double avgS = 0, totS = 0, lengthS;  //For sentence stats
  int wordCount = 0, sentenceCount = 0;  
  while(fin >> w){  //Ends loop without counting last word twice
    lengthW = w.length();  //Determine length of current word
    totW = totW + lengthW;  
    lengthS++;  //Increments the length of current sentence
    wordCount++;
    if (w.find(".") != string::npos || w.find("!") != string::npos)
    {
      totS = totS + lengthS;  //Used for average length
      lengthS = 0;  //Resets length of sentence
      sentenceCount++;  //Counts number of sentences processed
    }
    else if (w.find("?") != string::npos){
      totS = totS + lengthS;
      lengthS = 0;
      sentenceCount++;
    }
  }    

  //Output
  avgS = totS / sentenceCount;  //Calculate average sentence
  avgW = totW / wordCount;  //Calculate average word
  cout << "\nWord count: " << wordCount << endl;
  cout << "Average word length: " << avgW << endl;
  cout << "Average sentence length: " << avgS << endl;
  
  return 0; 
}
