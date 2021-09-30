//Nicholas Heil 242628
//Practicum Problem 2

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
  string file;
  cout << "Filename: ";
  cin >> file;
  ifstream fin(file);

  if (!fin){
    cout << "File not found!" << endl;
    return 1;
  }

  string current, longest, shortest;
  char c;
  int lhr=0, shr=0, lmin=0, smin=5000, chr=0, cmin=0;  //For comparisons
  int totmin1=0, totmin2=0, lenmin=0;  //For calculations
  while (fin >> current >> chr >> c >> cmin){
    totmin1 = (chr*60) + cmin;
    fin >> c >> chr >> c >> cmin;
    totmin2 = (chr*60) + cmin;
    if (totmin1 > totmin2)
      totmin2 = totmin2 + 1440;
    lenmin = totmin2 - totmin1;
    if (lenmin > lmin){
      lmin = lenmin;
      longest = current;
    } 
    else if (lenmin < smin){
      smin = lenmin;
      shortest = current;
    }
  }
  lhr = lmin / 60;
  lmin = lmin % 60;
  shr = smin / 60;
  smin = smin % 60;
  cout << "Longest: " << longest << " with " << lhr << " hours and ";
  cout << lmin << " minutes" << endl;
  cout << "Shortest: " << shortest << " with " << shr << " hours and ";
  cout << smin << " minutes" << endl;
  return 0;
}
