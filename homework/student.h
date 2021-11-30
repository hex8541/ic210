//Nicholas Heil 242628
//Header file

#ifndef STUDENTHEADER
#define STUDENTHEADER
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Student{
  string fname, lname;
  double avg;
  double* HW;
};

Student* readfile(int *n, int *m);
void sort(Student* stu, int n, int m);
void print(Student* stu, int n, int m);
bool before(Student a, Student b);
#endif
