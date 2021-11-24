//Nicholas Heil 242628
//create a linked list of word/value pairs

#include "lab10.h"
#include "lab10.cpp"

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

  while(fin >> j){
    fin >> current >> curr >> j;
    List = add2front(current, curr, List);
  }
  tC = List; 
  char con = 'a';
  while(con && length(tC)-1 > 0)
    con = printstep(tC, prev);
  cout << "List is: ";
  for(Node* t = prev->next; t != NULL; t = t->next)
    outNode(t);
  return 0;
}
