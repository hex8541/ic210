//Nicholas Heil 242628
//Fractals lab

#include <iostream>
#include <string>
using namespace std;

void repeat(string s, int count); //print string s count times in a row
void carpet_row(int width, int row_index); //print out the cantor set
int findLevels(int size); //Determines the number of levels needed 

int main() {
  //read in size
  int size;
  cout << "size: ";
  cin >> size;

  //output full Sierpinski Carpet
  cout << "Width-" << size << " Sierpinski carpet:" << endl;
  for(int i=0; i <= size-1; i++){
    if(i < size/3){ //upper third
      carpet_row(size, i);
      cout << endl;
    }
    else if(i >= size/3){
      if(i > size-(size/3)){  //bottom third
        carpet_row(size, i-((size/3)*2));
        cout << endl;
      }
      else{ //middle third
        carpet_row(size, i-(size/3));
        cout << endl;
      }
    }
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

void carpet_row(int width, int row_index){
  string DIAMOND = "\u2bc1";
  if(row_index == 0 || row_index == width/3 || row_index == (width/3)-1){ //base case
    repeat(DIAMOND, width);  //outputs line of X's at appropriate width
    return;
  }
  carpet_row(width/3, row_index-1); 
  repeat(" ", width/3);
  carpet_row(width/3, row_index-1);
  return;
}

int findLevels(int size){
  int levels=0;
  if(size == 1) //base case
    return 0;
  levels = 1+findLevels(size/3);
  return levels; //levels will equal the power of 3 that size represents
}
