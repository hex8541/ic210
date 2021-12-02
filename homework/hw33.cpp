//Nicholas Heil 242628
//Read in linked list of ints, add other ints to list where user wants

#include <iostream>
#include <string>

using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* add2back(int val, Node* List);
Node* add2front(int val, Node* List);
Node* findlast(Node* List);
Node* find(int val, Node* List);

int main()
{
  //Read in list of numbers until negative, read the list back to user 
  int num;
  cin >> num;
  Node* List = new Node{num, NULL};
  cin >> num;
  while (num >= 0){ //ends once negative number inputted
    List = add2back(num, List);
    cin >> num;
  }
  for(Node* i = List; i != NULL; i = i->next){ //output list
    cout << i->data << " ";
  }
  
  //Take commands from user for manipulation
  string command;
  int num2;
  while(command != "quit"){ //ends once quit command given
    cout << "\n> ";
    cin >> command;
    if(command == "enter"){
      cin >> num >> command >> num2; //read in relevant information
      //add new term after num2
      Node* location = find(num2, List);  
      Node* nuevo = new Node{num, location->next};
      location->next = nuevo;
    }
    else if(command != "quit"){ //assuming only other option is add to front
      cin >> num; //read in number to be added to front
      List = add2front(num, List);
    } 
    if(command != "quit"){
      for(Node* i = List; i != NULL; i = i->next) //output list
        cout << i->data << " ";
    }
  }
  return 0;
}

Node* add2back(int val, Node* List){
  if(List == NULL)  //creates a one term list if one does not already exist
    List = new Node{val, NULL};
  else { //Add new term to end of existing list
    Node* last = findlast(List);
    Node* nuevo = new Node{val, NULL}; 
    last->next = nuevo;
  }
  return List; //return pointer to the list
}

Node* add2front(int val, Node* List){
  if(List == NULL) //creates new list if necessary
    List = new Node{val, NULL};
  else { //add new term to front of existing list
    Node* nuevo = new Node{val, List};
    List = nuevo;
  }
  return List;
}

Node* findlast(Node* List){
  if(List == NULL){ //failsafe in case invalid Node* is inputted
    cout << "Error!" << endl;
    exit(1);
  }
  for(Node* t = List; t != NULL; t = t->next){
    if(t->next == NULL) //if final term reached, return its pointer
      return t;
  }
  return NULL; //for compiler to work
}

Node* find(int val, Node* List){
  if(List == NULL){  //safeguard
    cout << "Error!" << endl;
    exit(1);
  }
  for(Node* t = List; t != NULL; t = t->next){
    if(t->data == val) //search through list for pointer to Node with data val
      return t;
  }
  return NULL;
}

