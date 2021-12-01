//Nicholas Heil 242628
//A fancy C program that calculates n!

#include <stdio.h>

int factorial(int n); //compute n!

int main()
{
  //receive user input for a number
  int num;
  printf("Enter a number: ");
  scanf("%d", &num); //Need to use pass by address

  int fac = factorial(num);
  printf("%d ! = %d", num, fac);
  return 0;
}

int factorial(int n){
  int prod = 1;
  for(int i=1; i <=n; i++)
    prod *= i;
  return prod;

}
