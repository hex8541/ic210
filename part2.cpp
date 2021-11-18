//Nicholas Heil
//Read in RSS file, find difference in time between oldest and newest episodes

#include <iostream>
#include "rss.h"
#include <ctime>
#include <sstream>

using namespace std;

int convertMon(string month); //used to convert months to numbers 0-12

int main() 
{
  //Read in input
  cout << "RSS filename: ";
  string fname, search;
  cin >> fname; 
  
  // Notice, we call open_rss to open a file instead of using ifstream.
  RssFile* rss = open_rss(fname);
  if (!rss) 
  {
    cout << "ERROR: invalid rss file" << endl;
    return 1;
  }

  // Declare strings to hold the info for each episode
  string title, url, date;
  //Declarations for date assessment
  istringstream DATE(date); //use istringstream to harvest from date string
  time_t tearly = 0;
  time_t tlate = 0;

  // Continue looping through until there is not a next episode
  while(next_episode(rss)){
    // call functions from rss.h to get episode information
    title = episode_title(rss);
    date = episode_date(rss);
    url = episode_url(rss);

    //Convert date to a tm object
    tm curr = {}; 
    string junk, month;
    char j;
    int year;
    DATE >> junk >> curr.tm_mday >> month >> year >> curr.tm_hour >> j 
      >> curr.tm_min >> j >> curr.tm_sec;
    curr.tm_mon = convertMon(month); //convert month for format
    curr.tm_year = year - 1900; //convert year for format
    
    //compare to earliest and latest episodes thus far
    time_t tcurr = mktime(&curr);
    if(tearly == 0 || tcurr < tearly) //if tearly isn't assigned or is newer 
      tearly = tcurr;
    else if(tlate == 0 || tcurr > tlate) //if tlate isn't assigned or is older
      tlate = tcurr;
  }
  //Process out difference in time
  double diff = difftime(tearly, tlate);
  int d, h, m, s; //day, hour, minute, second
  int r; //remaining
  int i = int(diff); //convert diff to integer for calculations
  d = i/86400;
  r = i%86400;
  h = r/3600;
  r = r%3600;
  m = r/60;
  s = r%60;
  cout << d << " days " << h << " hours " << m << " minutes " 
    << s << " seconds" << endl;


  // It's always good to clean up after yourself.
  close_rss(rss);
  return 0;
}

int convertMon(string month){ //used to convert months to numbers 0-11
  if(month == "Jan")
    return 0;
  else if(month == "Feb")
    return 1;
  else if(month == "Mar")
    return 2;
  else if(month == "Apr")
    return 3;
  else if(month == "May")
    return 4;
  else if(month == "Jun")
    return 5;
  else if(month == "Jul")
    return 6;
  else if(month == "Aug")
    return 7;
  else if(month == "Sep")
    return 8;
  else if(month == "Oct")
    return 9;
  else if(month == "Nov")
    return 10;
  else //assumed only other option is Dec
    return 11;
}
