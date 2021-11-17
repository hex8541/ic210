//Nicholas Heil 242628
//Read in lowercase words and a single letter l, output all words starting w/l

#include <iostream>
#include <string>

using namespace std;

struct Node{  //Use nodes storing the words given
  string word;
  Node* next;
};

Node* add2front(string value, Node* List);

int main()
{
  //Read in words
  Node* List = new Node;
  cout << "Enter words followed by END: " << endl;
  string current;
  cin >> current;
  while(current != "END"){
    List = add2front(current, List); //Use function to add new nodes to list
    cin >> current; //cycles through inputs
  }

  //Read in letter
  char l;
  cout << "What letter? ";
  cin >> l; 

  //Output words starting with letter
  for(Node* current = List; current != NULL; current = current->next){
    if(current->word[0] == l)
      cout << current->word << endl; //if first letter matches, output word
  }

  return 0;
}

Node* add2front(string word, Node* List){ //modified for strings
  Node* a = new Node{word, List};
  return a;
}
