//Nicholas Heil 242628
//Simulate a game of Craps

#include <iostream>
#include <cstdlib>

using namespace std;

int throwdice();
int main()
{
  int seed;
  cout << "Enter seed value: ";
  cin >> seed;
  srand(seed);  //Use a seed value to make random output vary between runs
  int win = throwdice();  //Initialize with a throw
  while (win != 0 && win != -1)  //Reruns until house or player win conditions present
    win = throwdice();
  return 0;
}

int throwdice()  //Simulate a single throw of two dice and process that roll in the game
{  //Used for outputs because values of each roll are only stored here
  int i = (rand()%6) + 1;
  int j = (rand()%6) + 1;
  int tot = i + j;
  if (tot == 2 || tot == 3 || tot == 12){  //House wins
    cout << "Player rolled " << i << " + " << j << " = " << tot << " House wins!" << endl;
    return -1;
  }
  else if (tot == 7 || tot == 11){  //Player wins
    cout << "Player rolled " << i << " + " << j << " = " << tot << " Player wins!" << endl;
    return 0;
  }
  else{  //Neither wins 
    cout << "Player rolled " << i << " + " << j << " = " << tot << " roll again" << endl;
    return tot;
  }
}
