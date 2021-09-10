//Nicholas Heil 242628
//Generate numbers based on set conditions and four provided integers

#include <iostream>
#include <string>
using namespace std;

int main()
{
  //Assign variables from input
  int s, e, a, b, t;  //t is test variable
  cout << "Enter four integers: " << endl;
  cin >> s >> e >> a >> b;
  t = s;
  while (t <= e && t >= s)
  {
    if ((t % a) == 0 && (t % b) ==0) //test if number is a multiple of a and b
    {
      cout << t << " ";
      t++;
    }
    else
      t++;  //if not, just move on to next number
  }
}


