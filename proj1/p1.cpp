//Nicholas Heil 242628
//Practicum Problem 1

#include <string>
#include <iostream>

using namespace std;

int main()
{
  double expr = 0, n1 = 0, n2 = 0, out = 0;
  int num = 0;
  string things, junk, out2;
  char c;
  cin >> n1 >> c;
  if (c == '/'){
    cin >> n2 >> junk >> num >> things >> junk;
    expr = n1 / n2;
    out = expr * num;
    if (out - int(out) != 0)
      cout << int(out) << "+ " << things << endl;
    else 
      cout << int(out) << " " << things << endl;
    return 0;
  }
  else {
    cin >> junk >> num >> things >> junk;
    expr = n1 / 100;
    out = expr * num;
    if (out - int(out) != 0)
      cout << int(out) << "+ " << things << endl;
    else
      cout << int(out) << " " << things << endl;
    return 0;
  }
  return 0;
}
