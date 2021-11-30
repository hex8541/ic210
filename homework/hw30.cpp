// hw.cpp
#include "student.h"

int main()
{
  int n = 0, m = 0;
  Student* stu = readfile(&n, &m);

  sort(stu, n, m);

  print(stu, n, m);

  return 0;
}
