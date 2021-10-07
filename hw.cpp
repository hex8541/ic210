// hw.cpp
#include <iostream>
#include <string>
using namespace std;

// TO DO: Give function prototypes
void get_names (string* x, string* y);
bool update_counts (string selection);




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
  exit(0);
}
bool update_counts(string s, string x, int* c1, string y, int* c2){
  if (s == "END")
    return false;
  else if (s == x){
    (*c1)++;
  }
}

