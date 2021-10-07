//Nicholas Heil 242628
//Simulate a game of Craps with additions to favor the house
//Include option to play again

#include <iostream>
#include <cstdlib>

using namespace std;

int throwdice(int setpoint, int turn);
int main()
{
  int seed;
  cout << "Enter seed value: ";
  cin >> seed;
  srand(seed);  //Use a seed value to make random output vary between runs
  char cont = 'y';  //Sets initial condition to play the game
  while (cont == 'y'){
    int setpoint = 0;  //Initialize with an invalid setpoint for function
    int turn = 1;  //Runs the first roll with special rules
    int win = setpoint = throwdice(setpoint, turn);  //First throw, set setpoint
    while (win != 0 && win != -1){  //Reruns until house or player win conditions present
      turn++;
      win = throwdice(setpoint, turn);
    }
    cout << "Play again? ";  //Gives player option to play again
    cin >> cont;
  }
  return 0;
}

int throwdice(int setpoint, int turn)  //Simulate a single throw of two dice and process that roll in the game
{  //Used for outputs because values of each roll are only stored here
  int i = (rand()%6) + 1;
  int j = (rand()%6) + 1;
  int tot = i + j;
  if (turn == 1){  //Plays with different win conditions for first turn, also outputs setpoint
      if (tot == 2 || tot == 3 || tot == 12){  //House wins
      cout << "Player rolled " << i << " + " << j << " = " << tot << " House wins!" << endl;
      return -1;
    }
    else if (tot == 7 || tot == 11){  //Player wins
      cout << "Player rolled " << i << " + " << j << " = " << tot << " Player wins!" << endl;
      return 0;
    }
    else{  //Neither wins 
      cout << "Player rolled " << i << " + " << j << " = " << tot << " setpoint is " << tot << "!" << endl;
      return tot;
    }
  }
  else{  //Plays with different win conditions after first turn
      if (tot == 7 || tot == 12){  //House wins
      cout << "Player rolled " << i << " + " << j << " = " << tot << " House wins!" << endl;
      return -1;
    }
    else if (tot == setpoint){  //Player wins after getting setpoint
      cout << "Player rolled " << i << " + " << j << " = " << tot << " Player wins!" << endl;
      return 0;
    }
    else{  //Neither wins 
      cout << "Player rolled " << i << " + " << j << " = " << tot << " roll again" << endl;
      return tot;
    }
  } 
}
