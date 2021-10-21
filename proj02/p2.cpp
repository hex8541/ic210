//Nicholas Heil 242628
//Printing out a deck of cards

#include <iostream>

using namespace std;

void deal(int* hand, int& hN, int* deck, int& card); //Deals 1 card to desired hand 
void printHands(int* player, int* dealer, int PC, int DC);  //Prints the Player and Dealer's current hands

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
  
  //Create arrays for hands knowing max hand size is five cards
  int* player = new int[5];
  int* dealer = new int[5];
  int PC=0, DC=0, card=0; //Player Card, Dealer Card, card position in deck

  //Deal cards
  deal(player, PC, deck, card);
  deal(dealer, DC, deck, card);
  //Deal and print
  for (int i=1; i <=4; i++){  //Only goes up to  because first cards already dealt
    deal(player, PC, deck, card);
    deal(dealer, DC, deck, card);
    printHands(player, dealer, PC, DC);
    cout << "\n"; //Separates printed iterations with a blank line
  }

  //Delete arrays
  delete [] deck;
  delete [] player;
  delete [] dealer;

  return 0;
}

void deal(int* hand, int& hN, int* deck, int& card) //Deals 1 card to desired hand 
{
  hand[hN] = deck[card];
  card++;
  hN++;
}

void printHands(int* player, int* dealer, int PC, int DC)  //Prints the Player and Dealer's current hands
{
  //output player's hand based on number of cards dealt to player
  cout << "Player: [";
  for(int i = 0; i < PC; i++){
    cout << player[i];
    if(i < PC-1)
      cout << " ";  //Add spaces between cards in hand
    else 
      cout << "]" << endl;  //Close out hand
  }
  //output dealer's hand based on number of cards dealt to dealer
  cout << "Dealer: [";
  for(int i = 0; i < DC; i++){
    cout << dealer[i];
    if(i < DC-1)
      cout << " ";
    else
      cout << "]" << endl;
  }
}
