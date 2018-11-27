// Programmer: Colton Walker // Date: 11/8/2018
// instructor Name: Price // Section: 1B
// File: hw9.cpp // Description: two classes of a burger and customer

#include <iostream>
#include <cmath>
#include "hw9.h"
using namespace std;

int main()
{
  srand(time(NULL));
  burger a;
  customer c;
  cout<<a<<endl;
  cout<<c<<endl;
  c.eat(a);
  cout<<c<<endl;
  
  return 0;	
}