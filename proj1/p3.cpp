//Nicholas Heil 242628
//Practicum Problem 3

#include <iostream>
#include <string>

using namespace std;

int main()
{
  int num;
  cout << "Enter number rows: "; 
  cin >> num;
  int row=1, col=1;
  char c = 'A';
  while (row <= num){
    if (row < 10)
      cout << " ";
    cout << row << ":";
    while (col <= num){
      if (col % row == 0){
        cout << c;
        if (c == 'Z' || c == '!')
          c = '!';
        else
          c = char(c+1);
      }
      else 
        cout << " ";
      col++;
    }
    cout << endl;
    c = 'A';
    col = 1;
    row++;
  }
  return 0;
}
