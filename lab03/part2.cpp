//Nicholas Heil 242628
//Convert between Dollars US, Dollars Canadian, Euros, and Pounds

#include <iostream>
#include <string>

using namespace std;

int main()
{ 
  //Determine what the user wants to do and gather inputs
  string junk, currency_1, currency_2;
  double amount, DE, ED, DP, PD, EP, PE, DC, CD, EC, CE, CP, PC; 
  //DE=Dollar US to Euro, etc....
  DE = .8886, ED = 1 / .8886;  //Dollar US and Euro conversions
  DP = .7446, PD = 1/ .7446;  //Dollar US and Pound conversions
  EP = .7446 / .8886, PE = .8886 / .7446;  //Euro and Pound conversions
  DC = 1.2841, CD = 1 / 1.2841;  //Dollar US to Dollar Canadian conversions
  EC = 1.2841 / .8886, CE = .8886 / 1.2841; //Euro to Dollar Canadian conversion
  PC = 1.2841 / .7446, CP = .7446 / 1.2841; // Pound to Canadian conversion 
  
  //Ensure that correct values are assigned to each variable by checking dollar
  cin >> junk >> amount >> currency_1;
  if (currency_1 == "Dollars")
    cin >> currency_1;  //Repeats assignment (to US or Canadian)
  cin >> junk >> currency_2;
  if (currency_2 == "Dollars")
    cin >> currency_2;
  
  //Catch for duplicate currencies 
  if (currency_1 == currency_2)
  {
    cout << amount << endl;
    return 0;
  }

  //Conversions beginning with US Dollars
  if (currency_1 == "US")
  {
    if (currency_2 == "Euros")
      cout << amount * DE << endl;
    else if (currency_2 == "Pounds")
      cout << amount * DP << endl;
      else  //Canadian dollars are only option left 
        cout << amount * DC << endl;
  }

  //Conversions beginning with Euros
  if (currency_1 == "Euros") 
  {
    if (currency_2 == "US") 
      cout << amount * ED << endl;
    else if (currency_2 == "Pounds")
      cout << amount * EP << endl;
      else 
        cout << amount * EC << endl;
  }

  //Conversions beginning with Pounds
  if (currency_1 == "Pounds")
  {
    if (currency_2 == "Euros")
      cout << amount * PE << endl;
    else if (currency_2 == "US") 
      cout << amount * PD << endl;
      else 
        cout << amount * PC << endl; 
  }

  //Conversions beginning with Canadian dollars
  if (currency_1 == "Canadian")
  {
    if (currency_2 == "Euros")
      cout << amount * CE << endl;
    else if (currency_2 == "Pounds")
      cout << amount * CP << endl;
      else
        cout << amount * CD << endl;
  }

  return 0;
}
