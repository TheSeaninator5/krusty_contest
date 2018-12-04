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
  burgermeister krusty;
  bool main_loop = true;
  do{
	  static int round = 1;
	  //Display contestants
	  for(int i = 0; i < 14; i++)
      {
        cout<<contest[i]<<endl;
      }
	  //Display round
	  cout<<"------------ROUND "<<round<<"--------------"<<endl; 
	  //Start round eating burgers
	  for(int i = 0; i < 15; i++)
	  {
	    contest[i].eat();
		contest[i].vomit(i, contest, krusty);
		contest[i].checkAlive();
	  }
	  for(int i = 14; i >=0; i--)
	  {
        contest[i].eat();
		contest[i].vomit(i, contest, krusty);
		contest[i].checkAlive();
	  }
	  cout<<"Krusty's Money: "<<krusty.getMontHold()<<endl;
	  round++;
	  if(findWinner(contest, krusty) == 1)
	  {
		main_loop = false;  
	  }
  }while(main_loop);
  return 0;	
}