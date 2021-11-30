//Nicholas Heil 242628
//Prototypes for functions

#ifndef LAB10_HEADER
#define LAB10_HEADER

#include <string>

using namespace std;

struct Pair{
  string word;
  int value;
};

struct Node{ //now updated with pairs for data
  Pair WV; //WV = WordValue
  Node* next;
};

int Score(Node* List); //calculates total score of a list
void outList(Node* List); //outputs a list, without parentheses
void outNode(Node* List); //outputs a single node, with parentheses
Node* add2back(Pair val, Node* List); //starts with pair b/c pair is defined
Node* add2front(string word, int val, Node* List); 
Node* findlast(Node* L);
int length(Node* List);
char printstep(Node* List, Node* prev); //prints each step and gather a/r input
char print5Step(Node* List, Node* prev); //modifies printstep for part 5

#endif
