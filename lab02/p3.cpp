//Nicholas Heil 242628
//Read a chmod triple and print a summary of the permissions.

#include <iostream>

using namespace std;

int main()
{
  //Collect the triple and separate the three decimal numbers. 
  cout << "Permissions: ";
  char user, group, other;
  cin >> user >> group >> other;

  //Separate each number from the triple into its bits.
  int x, u1, u2, u3, g1, g2, g3, f1, f2, f3;
  x = user-48;  //x used for calculations
  
  //Perform calculations for user
  u1 = x/4, x = x%4;
  u2 = x/2, x = x%2;
  u3 = x/1;
  cout << "\nUser: \nread " << u1 << "\nwrite " << u2 << "\nexecute " << u3 << endl;

  //Perform calculations for group
  x = group-48;  //variable -48 is used to cancel out ASCII values of characters
  g1 = x/4, x = x%4;
  g2 = x/2, x = x%2;
  g3 = x/1;
  cout << "\nGroup: \nread " << g1 << "\nwrite " << g2 << "\nexecute " << g3 << endl;

  //Perform calculations for other (variable f for final)
  x = other-48;
  f1 = x/4, x = x%4;
  f2 = x/2, x = x%2;
  f3 = x/1;
  cout << "\nOther: \nread " << f1 << "\nwrite " << f2 << "\nexecute " << f3 << endl;
}


