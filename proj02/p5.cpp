//Nicholas Heil 242628
//Play with aesthetics: vertically printed hands, deck not printed, and suits

#include <iostream>
#include <string>
#include <cstdlib>  

using namespace std;

void deal(int* hand, int& hN, int* deck, int& card); //Deals 1 card to desired hand 
void printHands(int* player, int* dealer, int PC, int DC);  //Prints the Player and Dealer's current hands
bool HitStand(int round, string P);  //Asks player or dealer to hit or stand
void shuffle(int* deck);  //Shuffles the deck
void Card(int* hand, int i);  //Returns card value to be printed

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

  //User input and shuffle if desired
  char c;
  int seed;
  cout << "Shuffle: [n | u <seed>]: ";
  cin >> c;
  if (c == 'u'){  //User decides to shuffle
    cin >> seed;
    srand(seed);  //Seeds random function
    shuffle(deck);  //Shuffles deck
  }

  
  //Create arrays for hands knowing max hand size is five cards
  int* player = new int[5];
  int* dealer = new int[5];
  int PC=0, DC=0, card=0; //Player Card, Dealer Card, card position in deck

  //Deal and output starting hand
  for(int i=1; i <=2; i++){  
    deal(player, PC, deck, card);
    deal(dealer, DC, deck, card);
    if(i ==2)
      printHands(player, dealer, PC, DC);
  }

  //Run through three rounds of hit/stand
  for(int round=1; round <=3; round++){
    //Player's turn in round
    if(HitStand(round, "Player's")){
      deal(player, PC, deck, card);
      printHands(player, dealer, PC, DC);
    }
    else
      printHands(player, dealer, PC, DC);
    //Dealer's turn in round
    if(HitStand(round, "Dealer's")){
      deal(dealer, DC, deck, card);
      printHands(player, dealer, PC, DC);
    }
    else
    printHands(player, dealer, PC, DC);
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
    
  //Initializes a max index for the for loop
  int max = PC;
  if (max < DC)
    max = DC;
  
  cout << "\n Player Dealer " << endl;
  //Outputs hands line by line
  for (int i = 0; i < max; i++){
    cout << "| ";
    Card(player, i);
    cout << "  | ";
    Card(dealer, i);
    cout << "  |";
    cout << endl;
  }
}

void Card(int* hand, int i)  //Outputs value of a card
{
  //Initialize strings for suits
  string club = "\u2663";  //100 series
  string diamond = "\u2666";  //200 series
  string heart = "\u2665";  //300 series
  string spade = "\u2660";  //400 series

  //If player doesn't have a card, output spaces
  if(hand[i] == 0)
    cout << "   ";
  else{ 
    string card;
    int cardV = hand[i]%100;
    if (cardV == 10)  //if card value is 10 skip extra space
      card = "10";
    else if (cardV == 11)  //Jack
      card = " J"; 
    else if (cardV == 12)  //Queen
      card = " Q";
    else if (cardV == 13)  //King
      card = " K";
    else if (cardV == 14)  //Ace
      card = " A";
    else 
      cout << " " << hand[i]%100;
    //Check suit value and add to card string
    if(hand[i]/100 == 1) 
      card = card + club;
    else if(hand[i]/100 == 4)
      card = card + spade;
    else if(hand[i]/100 == 2)
      card = card + diamond;
    else
      card = card + heart;
    cout << card;
  }
}

bool HitStand(int round, string P)  //Asks player or dealer to hit/stand
{
  char A; //Action
  cout << "Round " << round << " " << P << " turn" << endl 
    << "hit or stand ? [h/s] "; 
  cin >> A;
  cout << "\n";  //separate blocks of text
  if (A == 'h')  //returns true if player chooses to hit
    return true;
  else   //returns false if standing
    return false;
}

void shuffle(int* deck)  //Shuffles the deck
{
  for(int i=0; i < 52; i++){
    int j = rand() % 52;
    int temp;
    temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

