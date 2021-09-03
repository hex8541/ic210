//Nicholas Heil 242628
//Convert a 4-bit binary number to its decimal equivalent.

#include <iostream>

using namespace std;

int main()
{
  cout << "Enter a 4-bit binary number: ";
  char b1, b2, b3, b4;
  cin >> b1 >> b2 >> b3 >> b4;    //Extracts the bits from the number
  
  //Convert each bit to its corresponding decimal value and add them together
  //Change char values to int, 48 is difference on ASCII Table
  int decimal = (8 * (int(b1)-48)) + (4 * (int(b2)-48)) + (2 * (int(b3)-48)) + (1 * (int(b4)-48));
  cout << "In decimal " << b1 << b2 << b3 << b4 << " = " << decimal << endl;
}
