//Nicholas Heil 242628
//lab 7 part 3

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
  cout << "Welcome to hangman!" << endl;
  
  //Randomize word
  cout << "Enter a seed value: ";
  int seed;
  cin >> seed;
  srand(seed);
  int n = rand() % 1466;
  ifstream fin("words07.txt");
  string word;
  for (int i = 0; i <= n; i++)
    fin >> word;
  
  //Initialize game setup
  string progress = mkShadowString(word);
  string options = "abcdefghijklmnopqrstuvwxyz";
  int gr = 8; //Guesses remaining
  char guess; 
  int wc = 0; //Win condition 

  while (gr > 0 && !wc){
    cout << "Wrong guesses remaining: " << gr << "\t" << options << endl;
    printSpaced(progress); 
    cout << ":";
    cin >> guess;
    //see if the letter appears, update progress if so or output mistake if not
    if (uncover(word, progress, guess) == progress){
      cout << "There were no " << guess << "'s!" << endl;
      gr--;
    }
    else 
      progress = uncover(word, progress, guess);
    options = crossOut(guess, options);
    
    //determine if end conditions met
    if (gr == 0)
      cout << "You lose!!!! The word was " << word << endl;
    else if (word == progress){
      cout << "You win!!!! The word was " << word << endl;
      wc++;
    }
  }
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
  cout << out << endl;  //Output spaced word
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
