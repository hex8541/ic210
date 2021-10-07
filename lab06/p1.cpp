//Nicholas Heil 242628
//Roll two six-sided dice for each of five rounds


#include <iostream>
#include <cstdlib>

using namespace std;

int rolldie();
int main()
{
  int seed;
  cout << "Enter seed value: ";
  cin >> seed;
  srand(seed);  //Makes the output of the program closer to being truly random
  for (int i=1; i <= 5; i++){  //Run for each of the five rounds
    int d1 = rolldie();  //First roll
    int d2 = rolldie();  //Second roll
    cout << "Player rolled " << d1 << " + " << d2 << " = " << d1+d2 << endl;  //Output results
  }
  return 0;
}

int rolldie(){  //Simulate single roll of a single 6-sided die
  int i = (rand()%6) + 1;
  return i;
}
