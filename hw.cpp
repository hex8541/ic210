//Nicholas Heil, 242628
//Receive two numbers and perform a command that is received separately on one
//of those numbers.

#include <iostream>
#include <string>

using namespace std;

int main()
{
  //Gather values for a and b
  double a, b;
  char j;  //j used to sort out comma 
  cout << "Value for a and b?" << endl;
  cin >> a >> j >> b;

  //Determine command to be executed
  cout << "What do you want?" << endl; 
  string c, extra;  //Sorting commands
  double num;  //value for addition
  char t;  //target
  cin >> c;

  //Addition operations
  if (c == "add"){
    cin >> num >> extra >> t;
    if (t == 'a') {  //Addition to a
    a = (a + num);
    cout << "a = " << a << " and b = " << b;
    }
    else
    {
      if (c == "add" && t == 'b'){
        b = (b + num);
        cout << "a = " << a << " and b = " << b;
      }
    }
  }
  else 
    {
    cin >> t;  
    if (c == "square" && t == 'a'){
      a = a * a;
      cout << "a = " << a << " and b = " << b;
    }
    else {
          b = b * b;
          cout << "a = " << a << " and b = " << b;
        }
    }
}

