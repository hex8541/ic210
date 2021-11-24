//Nicholas Heil 242628
//Definitions for functions
#ifndef LAB10
#define LAB10
#include <iostream>
#include <fstream>
#include "lab10.h"

Node* tC = new Node; //the Current
void outNode(Node* List){
  cout << "(" << List->WV.word << " " << List->WV.value << ") ";
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

Node* findlast(Node* L)  //When youcall this function, make sure L is not NULL
{
  if( L == NULL )
  {
    cerr << "error!" << endl;
    exit(1);
  }
  for(Node* p = L; p != NULL; p = p->next)
  {
    // If p points to the last node, p->next should be NULL.
    // See the picture above (the node containing 12).
    if( p->next == NULL)
      return p;
  }

  return NULL;    //needed by compiler to ensure function always returns a value
}

Node* add2back(Pair val, Node* List){
  if(List == NULL)
    List = new Node{val, NULL};
  else{
    Node* last = findlast(List);
    Node* T = new Node{val, last->next};
    last->next = T;
  }
  return List;
}

char printstep(Node* List, Node* prev){
  //Output current node
  cout << "The current node: ";
  outNode(tC);
  cout << endl;
  //Output previous nodes
  cout << "Nodes before the current: ";
  for(Node* temp = prev->next; temp != NULL; temp = temp->next)
    outNode(temp);
  cout << endl;
  //Output number of nodes left, a/r and cin input
  cout << "#nodes after the current: " << length(tC->next)-1 << endl;
  cout << "[a]ccept or [r]eject: ";
  char ans;
  cin >> ans;
  prev = add2back(List->WV, prev); //add to previous list
  tC = List->next; //increment the list
  return ans;
}

void outList(Node* List){
  for(Node* t = List->next; t != NULL; t = t->next)
    cout << t->WV.word << " ";
  cout << endl;
}

int Score(Node* List){
  int tot=0;
  for(Node* t = List->next; t != NULL; t = t->next)
    tot = tot + t->WV.value; 
  return tot;
}
#endif
