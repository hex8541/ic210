//Nicholas Heil
//Read in RSS file, find episode w/closest duration to target w/o going over

#include <iostream>
#include "rss.h"
#include <sstream>

using namespace std;

struct Podcast{ //used to store values for shortest podcast
  string title, url;
  int dif;
};

//Take pointer to open RSS file project, return duration of the episode
string episode_duration(RssFile* rfile);
int seconds(string s); //Converts time as a string (h:m:s, m:s, or s) to sec

int main() 
{
  //Read in input
  cout << "RSS filename: ";
  string fname, search, desired;
  cin >> fname; 
  cout << "Desired duration: ";
  cin >> desired;
  int maxLength = seconds(desired);
  
  // Notice, we call open_rss to open a file instead of using ifstream.
  RssFile* rss = open_rss(fname);
  if (!rss) 
  {
    cout << "ERROR: invalid rss file" << endl;
    return 1;
  }

  // Declare strings to hold the info for each episode
  string title, url, date, duration;
  Podcast shortest = {};
  // Continue looping through until there is not a next episode
  while(next_episode(rss)){
    // call functions from rss.h to get episode information
    title = episode_title(rss);
    date = episode_date(rss);
    url = episode_url(rss);
    duration = episode_duration(rss);
    if(maxLength >= seconds(duration)){ //if shorter than cap
      //and shorter than established shortest
      if(shortest.dif == 0 || (maxLength - seconds(duration)) < shortest.dif){
        //rewrite values for shortest podcast
        shortest.title = title; 
        shortest.url = url;
        shortest.dif = maxLength - seconds(duration);
      }
    }
  }
  if(shortest.dif == 0)
    cout << "No shorter episodes found" << endl;
  else
    cout << "title: " << shortest.title << endl << "url: " << shortest.url 
      << endl << shortest.dif << " seconds shorter";
  // It's always good to clean up after yourself.
  close_rss(rss);
  return 0;
}

string episode_duration(RssFile* rfile)  //modified from episode_title 
{
  if (!rfile || !rfile->current_item) 
  {
    cerr << "ERROR in call to episode_duration: did you call next_episode() first?" << endl;
    exit(2);
  }

  xmlNode* item_child = rfile->current_item->children->next;
  string duration;//change string to duration 
  while (item_child) 
  {
    string name = (char*) item_child->name;
    if( name == "duration")  //read in following appearance of duration tag
      return (char*) item_child->children->content;
    
    item_child = item_child->next;
  }

  // no duration found within the item
  // better to use a default than to make an error
  return "1";
}

int seconds(string s){ 
  istringstream TIME(s); //use string stream to process the time as a string
  int seconds=0, minutes=0, hours=0;
  char j; //for reading colons
  if(s.find(":") == string::npos) //if no colon, just seconds
    TIME >> seconds;
  else{
    TIME >> hours >> j >> minutes;
    if(TIME >> j){ //if there's a second colon (meaning hours are present)
      TIME >> seconds;
      seconds = seconds + (60*minutes) + (3600*hours);
    }
    else{ //if there's only one colon (meaning just minutes and seconds)
    seconds = minutes; //adjust variables to match values
    minutes = hours;
    seconds = seconds + (60*minutes);
    }
  }
  return seconds;
}
