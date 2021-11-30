//Nicholas Heil 242628
//Read in names and scores, then print out the high score for each name

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct game{
  string fname, lname;
  int score;
};

void selection_sort(game* A, int n);
bool before(game a, game b);

int main()
{
  //Gather input
  string fname;
  cout << "Filename: ";
  cin >> fname;
  ifstream fin(fname);
  int size;
  fin >> size;
  game* Scores = new game[size];
  for(int i=0; i < size; i++) //Read into the array of scores
    fin >> Scores[i].fname >> Scores[i].lname >> Scores[i].score;

  //sort 
  selection_sort(Scores, size);

  //Output high scores for each player
  string first, last;//initialize with last name in list so first won't match
  first = Scores[size-1].fname;
  last = Scores[size-1].lname;
  for(int i=0; i < size; i++){
    //output if this is the first appearance of the name & move to next
    if(first != Scores[i].fname || last != Scores[i].lname){
      cout << Scores[i].fname << " " << Scores[i].lname << " " 
        << Scores[i].score << endl;
      first = Scores[i].fname;
      last = Scores[i].lname;
    }
    else{ //move to next saved score
      first = Scores[i].fname;
      last = Scores[i].lname;
    }
  }

  //End run, delete array
  delete [] Scores;
  return 0;
}

void selection_sort(game* A, int n) {//modified for games
  for (int i = 0; i < n - 1; ++i) {
    // find nexti, the index of the next element
    int nexti = i;
    for (int j = i + 1; j < n; ++j) {
      if (before(A[j], A[nexti])) {
        nexti = j;
      }
    }
    // swap A[i] and A[nexti]
    game temp = A[i];
    A[i] = A[nexti];
    A[nexti] = temp;
  }
}

bool before(game a, game b){ //sort primarily by last name
  if(a.lname == b.lname && a.fname == b.fname)
    return a.score > b.score; //sort by score for same person (highest first)
  else if(a.lname == b.lname)
    return a.fname < b.fname; //sort by first name
  else
    return a.lname < b.lname; //sort by last name
}
