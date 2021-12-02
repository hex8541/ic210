//Nicholas Heil 242628
//Fractals lab

#include <iostream>
#include <string>
using namespace std;

void repeat(string s, int count); //print string s count times in a row
void cantor_row(int length); //print out the cantor set

int main() {
  //read in size
  int size;
  cout << "size: ";
  cin >> size;

  //output cantor row
  cout << "Width-" << size << " Cantor set:" << endl;
  cantor_row(size);
  cout << endl;

  return 0;
}

void repeat(string s, int count){
  if(count <= 0)
    return;
  repeat(s, count-1);
  cout << s;
  return;
}

void cantor_row(int length){
  if(length == 1){ //base case
    cout << "X";
    return;
  }
  //three equal parts, each of length/3
  cantor_row(length/3); 
  repeat("_", length/3);
  cantor_row(length/3);
  return;
}
