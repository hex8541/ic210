//Nicholas Heil 242628
//lab 7 part 1

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void printSpaced(string s);  //print string with spaces between characters
string mkShadowString(string s);  //creates string entirely of underscores
//uncovers all occurences of a character in a shadowed string
string uncover(string original, string covered, char c);
string crossOut(char c, string s);  //removes character from list of alphabet

int main()
{
  cout << "Testing printSpaced..." << endl;
  cout << "["; 
  printSpaced("wash"); 
  cout << "]" << endl;

  cout << "["; 
  printSpaced("HelloWorld!"); 
  cout << "]" << endl;

  

  cout << endl << "Testing mkShadowString..." << endl;
  string s1 = "food";
  string s2 = mkShadowString(s1);
  cout << "original: " << s1 << endl;
  cout << "  shadow: " << s2 << endl;
  string s3 = "require";
  string s4 = mkShadowString(s3);
  cout << "original: " << s3 << endl;
  cout << "  shadow: " << s4 << endl;

     
  cout << endl << "Testing uncover..." << endl;
  string u1 = "housepet";
  string u2 = "________";
  cout << u1 << endl << u2 << endl;
  
  string u3 = uncover(u1,u2,'e');
  if( u2 == u3 )
    cout << u3 << " there were not e's!"  << endl;
  else
    cout << u3 << " there were e's!"  << endl;
  u2 = u3;
 
  u3 = uncover(u1,u2,'q');
  if( u2 == u3 )
    cout << u3 << " there were not q's!"  << endl;
  else
    cout << u3 << " there were q's!"  << endl;

  cout << endl << "Testing crossOut..." << endl;
  string t1 = "Go get good food!";
  cout << t1 << endl;
  t1 = crossOut('o',t1);
  cout << t1 << endl;
  t1 = crossOut('g',t1);
  cout << t1 << endl;
   
  return 0;
}

void printSpaced(string s)  //print string with spaces between characters
{
  int n = (2 * s.length());  
  char* spaced = new char[n];  //Creates output array
  int w = 0;  //Counter for word
  for (int i = 0; i < n; i++){
    if (i%2 == 0){
      spaced[i] = s[w];  //adds characters of original word
      w++;
    }
    if (i%2 != 0)  //adds a space if not necessary to add character 
      spaced[i] = ' ';
    if (i == n - 1)  //Adds null character to array on last run 
      spaced[i] = '\0';
  }
  string out = spaced;
  cout << out;  //Output spaced word
  delete [] spaced;  //Delete arrays used in iteration of function
}

string mkShadowString(string s)  //creates string entirely of underscores
{
  char* p = new char[s.length()]; 
  for (int i = 0; i < s.length(); i++)
    p[i] = '_'; 
  p[s.length()] = '\0';  //After adding all _ add null
  string shadow = p;  //Convert
  delete [] p;
  return shadow; //Returns string of _
}

//uncovers all occurences of a character in a shadowed string
string uncover(string original, string covered, char c)
{
  string s = covered;  //modified version of covered, output
  //check for character match between original word and character
  for (int i = 0; i < original.length(); i++){
    if (original[i] == c)  
      s[i] = c;  //uncover if there is a match
  }
  return s;
}

string crossOut(char c, string s)  //same process as previous function, just *
{
  string out = s;
  for (int i = 0; i < s.length(); i++){
    if (s[i] == c)
      out[i] = '*';
  }
  return out;
}
