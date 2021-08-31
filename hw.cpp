//Nicholas Heil, 242628

#include <iostream>

using namespace std;

//Read three letter word in uppercase and print out the same word lowercase.
int main()
{
  //Ask for 3-letter word in all caps
  cout << "Input a 3-letter word in uppercase letters:";
  //Read the 3-letter word and assign letters to variables 
  char c1, c2, c3;
  cin >> c1 >> c2 >> c3;
  //Convert letters to lowercase equivalents from ASCII table values 
  cout << "Output: " << char(c1 + 32) << char(c2 + 32) << char(c3 + 32) << endl;
}
