//Nicholas Heil 242628
//create a linked list and print the strings it stores in reverse order

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Node{
  string word;
  Node* next;
};

Node* add2front(string value, Node* List); 
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
  Node* List = new Node;
  while(fin >> current)
    List = add2front(current, List);
  
  //Output list and count
  cout << "Count is " << length(List)-1 << endl; //use length function
  while(List->next != NULL){
    cout << List->word << " ";
    List = List->next;
  }

  return 0;
}

Node* add2front(string value, Node* List){ //adds a new term to front of a list
  Node* a = new Node{value, List};
  return a;
}

int length(Node* List){ //function finds number of terms in a linked list
  int count = 0;
  for(Node* current = List; current != NULL; current = current->next)
    count++;
  return count;
}
