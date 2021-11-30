//Nicholas Heil 242628
//Write recursive version of calcspace

#include <iostream>
using namespace std;

int calspace(int num);

int main()
{
  int n;
  cout << "Integer? ";
  cin >> n;

  cout << "#spaces= " << calspace(n) << endl;
  return 0;
}

int calspace(int num)
{
  int sp = 0; 
  if( num < 0 ) {
    sp++;         // +1 for '-' sign
    num = -num;   // make num positive 
  }

  if( num >= 10 )
    sp = sp + 1 + calspace(num/10);
  else //last digit
    return sp+1;
}
