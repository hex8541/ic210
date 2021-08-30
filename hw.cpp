#include <iostream>

using namespace std;

int main()
{
  int feet1;
  int inches1;
  int feet2;
  int inches2;
  string junk; //string junk is used to separate ' and " from user input
  //The following process takes user input and separates it into 
  cout << "Enter two lengths in feet and inches (larger first!)" << endl;
  cin >> feet1;
  cin >> junk;
  cin >> inches1;
  cin >> junk; 
  cin >> feet2;
  cin >> junk;
  cin >> inches2;
  int total1 = (feet1*12) + inches1; //total variables convert ft -> in
  int total2 = (feet2*12) + inches2;
  int difference = total1 - total2; //operation performed on total inches
  int ft = difference/12;
  int in = difference%12;
  cout << "Difference is " << ft << "\' " << in << "\'\'" << endl;
  return 0;
}
