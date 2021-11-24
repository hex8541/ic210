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
  Node* List = new Node;
  while(fin >> j){
    fin  >> current >> curr >> j;
    List = add2front(current, curr, List);
  }
  
  //Output list and count
  cout << "Count is " << length(List)-1 << endl; //use length function
  while(List->next != NULL){
    cout << "(" << List->WV.word << " " << List->WV.value << ") ";
    List = List->next;
  }

  return 0;
}
