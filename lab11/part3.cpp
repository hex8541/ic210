//Nicholas Heil 242628
//Fractals lab

#include <iostream>
#include <string>
using namespace std;

void repeat(string s, int count); //print string s count times in a row
void cantor_row(int width, int levels); //print out the cantor set
int findLevels(int size); //Determines the number of levels needed 

int main() {
  //read in size
  int size;
  cout << "size: ";
  cin >> size;

  //output full Cantor
  cout << "Width-" << size << " Cantor set:" << endl;
  int lev = findLevels(size); //determine levels needed
  for(int i=0; i <= lev; i++){
    cantor_row(size, i);
    cout << endl;
  }

  return 0;
}

void repeat(string s, int count){
  if(count <= 0)
    return;
  repeat(s, count-1);
  cout << s;
  return;
}

void cantor_row(int width, int levels){
  if(levels == 0){ //base case
    repeat("X", width);  //outputs line of X's at appropriate width
    return;
  }
  //three equal parts, each of length/3

  cantor_row(width/3, levels-1); 
  repeat("_", width/3);
  cantor_row(width/3, levels-1);
  return;
}
int findLevels(int size){
  int levels=0;
  if(size == 1) //base case
    return 0;
  levels = 1+findLevels(size/3);
  return levels; //levels will equal the power of 3 that size represents
}
