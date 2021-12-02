//Nicholas Heil 242628
//create a linked list of word/value pairs

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
<<<<<<< HEAD
  Node* tC = new Node; //the Current
=======
  Node* tC = new Node; //the Current;

>>>>>>> a84cfdbca973e1395af76d677eb75f632d08906c
  while(fin >> j){
    fin >> current >> curr >> j;
    List = add2front(current, curr, List);
  }

  //Iterate steps
  tC = List; 
  char con = 'a';
<<<<<<< HEAD
  while(con && length(tC)-1 > 0){
    con = printstep(tC, prev);
    tC = tC->next;
  }

=======
  while(con && length(tC)-1 > 0)
    con = printstep(tC, List, prev);
>>>>>>> a84cfdbca973e1395af76d677eb75f632d08906c
  //Final output
  cout << "List is: ";
  outList(prev);
  cout << "Score is: " << Score(prev);
  return 0;
}
