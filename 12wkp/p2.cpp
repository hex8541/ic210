//Nicholas Heil 242628
//Practicum part 2

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string Caps(string event);

int main()
{
  //input 
  string file;
  cout << "Enter filename: ";
  cin >> file;
  ifstream fin(file);
  if (!fin){
    cout << "File not found!";
    return 1;
  }
  
  //read in file, output as you go
  string event, team;
  int navy=0; 
  int army=0;
  int index = 0;
  while(fin >> event){
    if(Caps(event) == "TOUCHDOWN"){
      fin >> team;
      if (team == "Navy")
        navy = navy +6;
      else 
        army = army +6;
    }
    else if(Caps(event) == "FIELD"){
      fin >> event >> team;
      if(team == "Navy")
        navy = navy +3;
      else
        army = army +3;
    }
    if(Caps(event) != "TIMEOUT"){
    index++;
    cout << "After event " << index << ", Navy " << navy 
      << " Army " << army << endl;
    }
  }
  
  cout << "Game over!" << endl;
  return 0;
}

string Caps(string event)
{
  int len = event.length();
  for(int i=0; i < len; i++){
    if(event[i] > 90)
      event[i] = event[i] - 32;
  }
  return event;
}

