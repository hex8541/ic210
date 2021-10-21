//Nicholas Heil 242628
//Printing out a deck of cards

#include <iostream>

using namespace std;

int main()
{
  //Create the deck as an array
  int* deck = new int[52];
  int face = 2;  //Initialize with first face value
  int suit = 1;  //Initialize with 1 representing clubs
  for(int i=0; i < 52; i++){
    deck[i] =  face + (100*suit);  //Calculate card value
    if (face < 14)
      face++;  //Increments face for current suit
    else {  //Move to next suit
      face = 2;  //Resets face
      suit++;  //Increments suit
    }

  }

  //Output deck
  cout << "[";
  for(int i=0; i < 52; i++){
    cout << deck[i];
    if (i < 51) 
      cout << " ";  //Add space for most of output
    else 
      cout << "]" << endl;  //Close deck if at end
  }
  
  return 0;
}
