//Nicholas Heil 242628
//Defining shapes to be drawn in gnuplot


#include <iostream>
#include <string>

using namespace std;

int main()
{
  //Gather inputs
  double a, b, c, t; 
  t = 0;
  cout << "Enter side lengths: ";
  cin >> a >> b >> c;

  //Sort to ensure that c is largest side length
  if (a > c){
    t = c;
    c = a;
    a = t;
  }
  if (b > c){
    t = c;
    c = b;
    b = t;
  }
  if (a > b){
    t = b;
    b = a;
    a = t;
  }
  //Check for triangle inequality
  if ((a + b) <= c){
    cout << "Error! these lengths violate the traingle inequality!";
    return 0;
  }

  //Employ Pythagorean Theorem
  string angle, type;
  if (a == c && b == c){  //Equilateral triangles are a special case
    angle = "acute";
    type = "equilateral";
    cout << "This is a " << angle << " " << type << " triangle.";
    return 0;
  }
  double a2, b2, c2;
  a2 = a*a;
  b2 = b*b;
  c2 = c*c;
  if (c2 == a2 + b2)  //Determine angle type
    angle = "right";
  else if (c2 > a2 + b2)
    angle = "obtuse";
    else 
      angle = "acute";
  if (a == b || b == c)  //Determine type based on lengths 
    type = "isosceles"; 
  else 
    type = "scalene";

  //Output
  cout << "This is a " << angle << " " << type << " triangle." << endl;
}
