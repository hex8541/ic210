//Nicholas Heil 242628
//Convert between Dollars, Euros, and Pounds

#include <iostream>
#include <string>

using namespace std;

int main()
{ 
  //Determine what the user wants to do
  string junk, currency_1, currency_2;
  double amount, DE, ED, DP, PD, EP, PE;  //DE=Dollar to Euro, etc....
  DE = .8886, ED = 1 / .8886;  //Dollar and Euro conversions
  DP = .7446, PD = 1/ .7446;  //Dollar and Pound conversions
  EP = .7446 / .8886, PE = .8886 / .7446;  //Euro and Pound conversions
  //cout << "What would you like to do?" << endl;
  cin >> junk >> amount >> currency_1 >> junk >> currency_2;
  
  //Catch for duplicate currencies 
  if (currency_1 == currency_2)
  {
    cout << amount << endl;
    return 0;
  }
  //Conversions beginning with Dollars
  if (currency_1 == "Dollars" || currency_1 == "Dollar") //Includes singular 
  {
    if (currency_2 == "Euros" || currency_2 == "Euro")
      cout << amount * DE << endl;
    else  //known that Pounds are only remaining possibility
      cout << amount * DP << endl;
  }

  //Conversions beginning with Euros
  if (currency_1 == "Euros" || currency_1 == "Euro")
  {
    if (currency_2 == "Dollars" || currency_2 == "Dollar")  
      cout << amount * ED << endl;
    else 
      cout << amount * EP << endl;
  }

  //Conversions beginning with Pounds
  if (currency_1 == "Pounds" || currency_1 == "Pounds")
  {
    if (currency_2 == "Euros" || currency_2 == "Euro")
      cout << amount * PE << endl;
    else 
      cout << amount * PD << endl;
  }
  return 0;
}
