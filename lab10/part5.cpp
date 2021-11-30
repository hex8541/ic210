//Nicholas Heil 242628
//Play a simple word game

#include "lab10.h"
#include <iostream>
#include <fstream>

int main()
{
  //Read in a file and open ifstream
  string file;
  cout << "Input file is: ";
  cin >> file;
  ifstream fin(file);
  if(!fin){ //checks that a valid file was inputted
    cout << "Error! File '" << file << "' not found!" << endl;
    return 1;
  }

  //Read in words to linked list 
  string current;
  int curr;
  char j; 
  //Define necessary lists
  Node* List = new Node;
  Node* prev = new Node;
  Node* tC = new Node; //the Current
  while(fin >> j){
    fin >> current >> curr >> j;
    List = add2front(current, curr, List);
  }

  //Iterate steps
  tC = List; 
  char con = 'a'; //condition
  while(con && length(tC)-1 > 0){
    con = print5Step(tC, prev);
    tC = tC->next;
  }

  //Final output
  cout << "\nSentence is: ";
  outList(prev);
  cout << "Score is: " << Score(prev);
  return 0;
}
