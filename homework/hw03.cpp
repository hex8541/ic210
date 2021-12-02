//Nicholas Heil, 242628
//Determine if a year is a leap year.

#include <iostream>

using namespace std;

int main()
{
  //Gather input and assign it to variable year.
  cout << "Enter year: ";
  int year;
  cin >> year;
  //Starts by determining if a year divisible by 100 is a leap year
  if (year%100 == 0)
  {
    if (year%400 == 0)
    {
      cout << "Is Leap Year" << endl;
      return (0);  //Stop program from running next if statement
    }
    else
    {
      cout << "Is Not Leap Year" << endl; 
      return (0); 
    }
  }
  //Next determines if a year not divisible by 100 is a leap year
  if ((year%4 == 0) && (year%100 != 0))
  {
     cout << "Is Leap Year" << endl;
  }
  else
  {
    cout << "Is Not Leap Year" << endl;
  }
}
