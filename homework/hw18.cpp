// hw.cpp
#include <iostream>
#include <string>
using namespace std;

// TO DO: Give function prototypes
void get_names (string* x, string* y);
bool update_counts (string s, string x, int* c1, string y, int* c2);
void display_results (string x, int c1, string y, int c2);



// *** DON'T CHANGE main()!! ****
int main() 
{
  string candidate1;
  string candidate2;

  get_names(&candidate1, &candidate2);

  int count1 = 0;
  int count2 = 0;

  cout << "Enter votes, ending with \"END\":" << endl;

  string selection;
  cin >> selection;
  while (update_counts(selection, candidate1, &count1, candidate2, &count2)) 
  {
    cin >> selection;
  }

  display_results(candidate1, count1, candidate2, count2);

  return 0;
}


// TO DO: Give function definitions
void get_names(string* x, string* y){
  cout << "Candidate names: ";
  cin >> *x >> *y;
}
bool update_counts(string s, string x, int* c1, string y, int* c2){
  if (s == "END")
    return false;
  else if (s == x){
    *c1 += 1;
    return true;
  }
  else if (s == y){
    *c2 += 1;
    return true;
  }
  else {
    cout << "Invalid name" << endl;
    return true;
  }
}
void display_results (string x, int c1, string y, int c2){
  int tot = c1 + c2;
  if (c1 > c2)
    cout << x << " wins with " << c1 << " out of " << tot << " votes" << endl;
  else if (c2 > c1)
    cout << y << " wins with " << c2 << " out of " << tot << " votes" << endl;
  else
    cout << "Tie!" << endl;
}
