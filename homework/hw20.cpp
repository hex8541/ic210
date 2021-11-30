//Nicholas Heil 242628
//Print out reverse journey of a series of flights

#include <string>
#include <iostream>

using namespace std;



int main()
{
  //Initialize/setup program
  cout << "How many legs? ";
  int n;
  cin >> n; //number of legs determines amount of space in array
  string* AP = new string[n+1];  //Array to store airport codes
  for (int i = 0; i < n; i++){  //Sorts input by leg
    char j;
    char* flight = new char[3];
    string extra;
    for (int j=0; j < 3; j++)  //Gathers first airport on each line
      cin >> flight[j];
    AP[i] = flight;
    if (i == n-1){ //Special case for final leg, reads last airport too
      cin >> j >> j;
      for (int k=0; k <3; k++)
        cin >> flight[k];      
      AP[n] = flight;
    }
    else 
      cin >> extra;  //Rest of line
    delete [] flight;
  }

  //Output 
  cout << "Reverse trip: ";
  //initializes at end of array to send out in reverse order
  for (int i = n; i >= 0; i--){  
    cout << AP[i];
    if (i != 0)  //only sends if not on last term
      cout << "->";
  }
  return 0;
}

