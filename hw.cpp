//Nicholas Heil 242628

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Section{
  string course, schedule;
  int number;
};

void searchByCourse(Section* sections, int n);
void searchBySection(Section* sections, int n);
Section* read(istream* pin, int* pn);

int main()
{
  string fname;
  cout << "Filename: ";
  cin >> fname;
  ifstream fin(fname);

  int n;
  Section* sections = read(&fin, &n);

  string cmd;
  cout << "> ";
  while( (cin >> cmd) && (cmd != "quit") )
  {
    if( cmd == "course" )
      searchByCourse(sections, n);
    else if ( cmd == "section" )
      searchBySection(sections, n);

    cout << endl << "> ";
  }


  delete [] sections;
  return 0;
}

Section* read(istream* pin, int* pn)
{
  char j;
  *pin >> j >> j >> *pn; //Read in number of sections to main function
  Section* current = new Section[*pn];
  for(int i=0; i < *pn; i++){ //read in each element in order
    *pin >> current[i].course >> current[i].number >> current[i].schedule;
  }
  return current;  //returns the pointer to the array
}

void searchByCourse(Section* sections, int n)
{
  string search;
  cin >> search;
  for(int i=0; i < n; i++){
    if(sections[i].course == search){
      cout << sections[i].course << " " <<  sections[i].number << " "
        << sections[i].schedule << endl;
    }
  }
}

void searchBySection(Section* sections, int n)
{
  int search;
  cin >> search;
  for(int i=0; i < n; i++){
    if(sections[i].number == search){
      cout << sections[i].course << " " << sections[i].number << " "
        << sections[i].schedule << endl;
    }
  }

}
