//Nicholas Heil 242628
//create a linked list of word/value pairs

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Pair{
  string word;
  int value;
};
struct Node{ //now updated with pairs for data
  Pair WV; //WV = WordValue
  Node* next;
};

Node* add2front(string word, int val, Node* List); 
int length(Node* List);

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

Node* add2front(string word, int val, Node* List){ //adds a new term to front of a list
  Pair New; //creates a new pair for the node being created
  New.word = word;
  New.value = val;
  Node* a = new Node{New, List}; 
  return a;
}

int length(Node* List){ //function finds number of terms in a linked list
  int count = 0;
  for(Node* current = List; current != NULL; current = current->next)
    count++;
  return count;
}
