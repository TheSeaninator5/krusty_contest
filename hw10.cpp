// Programmer: Colton Walker // Date: 11/8/2018
// instructor Name: Price // Section: 1B
// File: hw9.cpp // Description: two classes of a burger and customer

#include <iostream>
#include <cmath>
#include "hw10.h"
using namespace std;

int main()
{
  srand(time(NULL));
  customer contest[15];
  burgermeister Krusty;
  Krusty+=5;
  cout<<"Amount:"<< Krusty.getMontHold()<<endl;
  Krusty-=5;
  cout<<"Amount:"<< Krusty.getMontHold()<<endl;
  bool main_loop = 0;
  do{
	//for(int i = 0; i < 15; i++)
	//{
	  //cout<<contest[i].getName()<<endl;
	  //contest[i].eat();
	  //Check if got pathogen
	  //if path = true
	  //roll die
	//}
	//for(int i = 14; i >=0; i--)
	//{
     // cout<<contest[i].getName()<<endl;
	//}
	
	cout<<contest[0].getName()<<endl;
	cout<<contest[0].getMoney()<<endl;
	contest[0].eat();
	cout<<contest[0].getName()<<endl;
	cout<<contest[0].getMoney()<<endl;
	
	main_loop = 1;
	  
  }while(main_loop == 0);
  
  return 0;	
}