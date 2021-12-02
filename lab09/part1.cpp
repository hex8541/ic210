//Nicholas Heil
//Read in RSS file, search for given word in titles of episodes

#include <iostream>
#include "rss.h"
using namespace std;

string capitalize(string w);

int main() 
{
  //Read in inputs
  cout << "RSS filename: ";
  string fname, search;
  cin >> fname; 
  cout << "Search for: ";
  cin >> search; 
  search = capitalize(search); //case insensitive search, titles are caps too
  int match=0; //used to determine if matches were found
  
  // Notice, we call open_rss to open a file instead of using ifstream.
  RssFile* rss = open_rss(fname);
  if (!rss) 
  {
    cout << "ERROR: invalid rss file" << endl;
    return 1;
  }

  // Declare strings to hold the info for each episode
  string title, url, date;

  // Continue looping through until there is not a next episode
  while(next_episode(rss)){

    // call functions from rss.h to get episode information
    title = episode_title(rss);
    string Ctitle = capitalize(title); //allows for case insensitive search
    date = episode_date(rss);
    url = episode_url(rss);

    // display the information we just looked up if search term is in title
    if(Ctitle.find(search) != string::npos){
      cout << "title: " << title << endl;
      cout << "url: " << url << endl;
      match++;
    }
  }
  //Print out no matches found if no results
  if(match == 0)
    cout << "No matches found" << endl;

  // It's always good to clean up after yourself.
  close_rss(rss);
  return 0;
}

string capitalize(string w){ //Used to make titles case insensitive
  for(int i = 0; i < w.length(); i++) 
  {
    char c = w[i];                    
    if( 'a' <= c && c <= 'z')
      w[i] = 'A' + (c - 'a');           
  }
  return w;
}
