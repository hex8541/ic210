//Nicholas Heil 242628
//Definitions for functions

#include "student.h"

Student* readfile(int *n, int *m){
  //Read file
  string file, junk;
  cout << "Filename: ";
  cin >> file;
  ifstream fin(file);
  fin >> *n >> junk >> *m >> junk;
  Student* stu = new Student[*n];
  for(int i = 0; i < *n; i++){  //allocate memory for each student's grades
    stu[i].HW = new double[*m];
    fin >> stu[i].fname >> stu[i].lname;
    //read in each student's grades
    double sum = 0;
    for(int j=0; j < *m; j++){
      fin >> stu[i].HW[j];
      sum = sum + stu[i].HW[j];
    }
    stu[i].avg = sum / *m; //compute average homework score for the student
  }
  return stu;
}

void sort(Student* stu, int n, int m){
  for (int i = 0; i < n - 1; ++i) {
    // find nexti, the index of the next element
    int nexti = i;
    for (int j = i + 1; j < n; ++j) {
      if (before(stu[j], stu[nexti])) {
        nexti = j;
      }
    }
    // swap A[i] and A[nexti]
    Student temp = stu[i];
    stu[i] = stu[nexti];
    stu[nexti] = temp;
  }
} 

bool before(Student a, Student b){
  if(a.avg != b.avg) //sort by average, then last, then first names
    return a.avg < b.avg;
  else if (a.lname != b.lname)
    return a.lname < b.lname;
  else
    return a.fname < b.lname;
}

void print(Student* stu, int n, int m){
  for(int i=0; i < n; i++){//start with output of name and average
    cout << stu[i].fname << " " << stu[i].lname << " avg=" << stu[i].avg;
    for(int j=0; j < m; j++)//output homework assignments
      cout << " " << stu[i].HW[j];
    cout << endl;
  }
}
