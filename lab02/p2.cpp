//Nicholas Heil 242628
//Convert a decimal number to binary

#include <iostream>

using namespace std;

int main()
{
  cout << "Enter a number between 0 and 15: ";
  int x, num, b1, b2, b3, b4;
  cin >> num;
  x = num;  //num used to save original number

  //Use division to separate each bit from the decimal bases they represent
  b1 = x/8; 
  x = x%8;  //Remove values accounted for from x
  b2 = x/4;
  x = (x%4);
  b3 = (x/2);
  x = x%2;
  b4 = (x/1);

  //Display the final result
  cout << num << " in binary is " << b1 << b2 << b3 << b4 << endl;
}

