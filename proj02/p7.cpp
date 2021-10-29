//Nicholas Heil 242628
//Play with full functionality

#include <iostream>
#include <string>
#include <cstdlib>  //for seed and random functions 
#include <unistd.h>  //for sleep function

using namespace std;

void deal(int* hand, int& hN, int* deck, int& card); //Deals 1 card to desired hand 
void printHands(int* player, int* dealer, int PC, int DC, bool LH);  //Prints the Player and Dealer's current hands
bool HitStand(int round, string P);  //Asks player or dealer to hit or stand
void shuffle(int* deck);  //Shuffles the deck
void Card(int* hand, int i);  //Returns card value to be printed
int BestScore(int* hand, int i);  //Returns best score for current player
int* Deck();  //Returns a fresh deck

int main()
{ 

  //User input and seed for shuffle if desired
  char c;
  int seed;
  cout << "Shuffle: [n | u <seed>]: ";
  cin >> c;
  if (c == 'u'){  //User decides to shuffle
    cin >> seed;
    srand(seed);  //Seeds random function
  }
  //create game as a while loop to repeat until an end is reached (repeat ties) 
  bool play=true, winner=true;  //winner assumes winner will need to be determined
  int dealerScore=0, playerScore=0;
  int* deck;
  while(play){
    deck = Deck();  //recreates deck for each run through
    shuffle(deck);  //Shuffles deck
    //Create arrays for hands
    int* player = new int[10];
    int* dealer = new int[10];
    int PC=0, DC=0, card=0; //Player Card, Dealer Card, card position in deck
    //Initializes last hand bool
    bool LH=false; 

    //Deal and output starting hand
    for(int i=1; i <=2; i++){  
      deal(player, PC, deck, card);
      deal(dealer, DC, deck, card);
      if(i ==2)
        printHands(player, dealer, PC, DC, LH);
    }


    //Adjusted to allow for infinite rounds
    bool p=true, d=true; //player and dealer continuing
    int round=1;
    //Includes assessment within for additional end conditions of "busts"
    while(p || d){ //Use while loop to continue running while bool applies
      //Player's turn in round
      if(HitStand(round, "Player's")){
        deal(player, PC, deck, card);
        if(BestScore(player, PC) > 21)
          printHands(player, dealer, PC, DC, true);
        else
          printHands(player, dealer, PC, DC, LH);
        p = true; //adjust conditions as necessary
        playerScore = BestScore(player, PC); //Only changes if player hits
      }
      else{
        if(d==false)
          LH=true; //This is the last hand displayed
        printHands(player, dealer, PC, DC, LH);
        p = false;  //adjust conditions
        if(LH)  //Ends early if in last round player hit and dealer stood
          break;
      }
      if(playerScore > 21){ //player busts
        cout << "Player busts, dealer wins" << endl;
        play=false;
        winner=false;  //doesn't need to determine which player won again
        break;
      }
      //Dealer's turn in round
      cout << "Round " << round << " Dealer's turn" << endl;
      cout << "hit or stand ? [h/s] ";  //illusion of dealer making choice
      dealerScore = BestScore(dealer, DC);  //Only changes if dealer hits
      if(dealerScore < 17){
        sleep(1); //dramatic effect
        cout << "h" << endl;
        deal(dealer, DC, deck, card);
        if(BestScore(dealer, DC) > 21)
          printHands(player, dealer, PC, DC, true);
        else
          printHands(player, dealer, PC, DC, LH);
        d = true; //adjust conditions
        dealerScore = BestScore(dealer, DC);  //Only changes if dealer hits
      }
      else{
        sleep(1); //dramatic effect
        cout << "s" << endl;
        if(p==false)
          LH=true;
        printHands(player, dealer, PC, DC, LH);
        d = false; //adjust conditions
      }
      if(dealerScore > 21){ //dealer busts
        cout << "Dealer busts, player wins" << endl;
        play=false;
        winner=false;  //doesn't need to determine winner again
        break;
      }
      round++; //increment round for while loop
    }
    playerScore = BestScore(player, PC);
    dealerScore = BestScore(dealer, DC);
    if (dealerScore != playerScore)
      play=false;
    //Delete arrays
    delete [] player;
    delete [] dealer;
  }
  if(dealerScore > playerScore && winner)
    cout << "Dealer wins" << endl;
  else if(playerScore > dealerScore && winner)
    cout << "Player wins" << endl;
  
  delete [] deck;
  return 0;
}

void deal(int* hand, int& hN, int* deck, int& card) //Deals 1 card to desired hand 
{
  hand[hN] = deck[card];
  card++;
  hN++;
}

//Now include a bool parameter to determine if dealer's first card is concealed
void printHands(int* player, int* dealer, int PC, int DC, bool LH)  //Prints the Player and Dealer's current hands
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
    if(i == 0  && LH == false)
      cout << " **"; //conceals first dealer card unless last hand
    else
      Card(dealer, i);
    cout << "  |";
    cout << endl;
  }
}

int BestScore(int* hand, int i)  //Returns best score for current player
{
  int total=0, best=0, value=0; 
  bool ace = false; //False till proven true, if there is an ace
  for(int j=0; j < i; j++){
    value = hand[j]%100;  //value refers to point value of card
    if (value > 10 && value < 14)
      value = 10;  //Set K, Q, J to 10
    else if (value == 14){  //set A to 1
      ace = true;
      value = 1;
    }
    total = total + value;  //Increment total while sifting for aces
  }
  if (ace && total <= 11)
    best = total+10;
  else 
    best = total;
  return best;
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

int* Deck()  //Returns a fresh deck
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
  return deck;
}
