// Programmer: Colton Walker // Date: 11/8/2018
// instructor Name: Price // Section: 1B
// File: hw10fncts.cpp // Description: two classes of a burger and customer

#include <iostream>
#include <cmath>
#include <fstream>
#include "hw10.h"

using namespace std;
//Functions

string makeName()
{
  string name = "";
  ifstream fin;
  fin.open("simpson_names.dat");
  static int line = 1;
  for(int i = 0; i < line; i++)
  {
    getline(fin, name);
  }
  fin.close();
  line++;
  return name;
}

string burgName(const int burgCode, const bool cheese, const bool sauce)
{
  const string KRUSTY = "Krusty ";
  const string BURGER= "Burger";
  const string SINGLE = "Single ";
  const string DOUBLE = "Double ";
  const string TRIUMPH = "Triumph ";
  const string MEATMASTER = "Meatmaster ";
  const string HEALTHMASTER = "Health-Master ";
  const string BACON = "Bacon ";
  const string WILBUR = "Wilbur ";
  const string KLOGGER = "Klogger ";
  const string FATTY = "Fatty ";
  const string TASTELESS = "Tasteless ";
  const string PICKLY = "Pickly ";
  const string GARDENFRESH = "Garden-Fresh ";
  const string KERMIT = "Kermit ";
  const string GREEN = "Green ";
  const string SAUCED = "Sauced ";
  const string CHEESY = "Cheesy ";
  int patties, bacon, pickles;
  string namePatties, nameBacon, namePickles, nameCheese, nameSauce;
  getBurgNum(burgCode, patties, bacon, pickles);
  if(cheese == true)
  {
    nameCheese = CHEESY;	  
  }
  if(sauce == true)
  {
	nameSauce = SAUCED;
  }
  //Name based on number patties
  if(patties == 1)
  {
    namePatties = SINGLE;
  }else if(patties == 2)
   {
     namePatties = DOUBLE;
   }else if(patties == 3)
    {
      namePatties = TRIUMPH;
    }else if(patties == 4)
	 {
	   namePatties = MEATMASTER;
	 }
  //Name based on oz of Bacon
  if(bacon == 1)
  {
    nameBacon = BACON;
  }else if(bacon == 2)
   {
     nameBacon = WILBUR;
   }else if(bacon == 3)
    {
      nameBacon = KLOGGER;
    }else if(bacon == 0)
     {
       nameBacon = HEALTHMASTER;
     }else if(bacon == 4)
	  {
	    nameBacon = FATTY;	  
	  }
  //Name based on number of pickles
  if(pickles  == 1)
  {
    namePickles = PICKLY;
  }else if(pickles == 2)
   {
     namePickles = GARDENFRESH;
   }else if(pickles == 3)
    {
      namePickles = KERMIT;
    }else if(pickles == 0)
     {
       namePickles = TASTELESS;
     }else if(pickles == 4)
	 {
	   namePickles = GREEN; 
	 }
  return KRUSTY + nameCheese + nameSauce + namePatties + nameBacon +
         namePickles + BURGER;
}

void getBurgNum(const int burgCode, int & pat, int & bac, int & pic)
{
  pat = burgCode / 100;
  bac = (burgCode / 10) % 10;
  pic = burgCode % 10;
  return;
}

//Burger Functions
int burger::getburgCode()
{
  return m_burgCode;
}
bool burger::setPattie(const int pattie)
{
  bool ret = false;
  if(pattie > 0 && pattie < 5)
  {
    m_numPatties = pattie;
    ret = true;
  }
  return ret;
}

int burger::getPattie()
{
  return m_numPatties;
}

bool burger::setBacon(const int bacon)
{
  bool ret = false;
  if(bacon >= 0 && bacon < 5)
  {
    m_numBacon = bacon;
    ret = true;
  }
  return ret;
}

int burger::getBacon()
{
  return m_numBacon;
}

bool burger::setPickle(const int pickle)
{
  bool ret = false;
  if(pickle >= 0 && pickle < 5)
  {
    m_numPickles = pickle;
    ret = true;
  }
  return ret;
}

int burger::getPickle()
{
  return m_numPickles;
}

bool burger::setCheese(const bool cheese)
{
  m_hasCheese = cheese;
  return cheese;
}

bool burger::getCheese()
{
  return m_hasCheese;
}

bool burger::setSauce(const bool sauce)
{
  m_hasSauce = sauce;
  return sauce;
}

bool burger::getSauce()
{
  return m_hasSauce;
}

bool burger::setPathogen(const bool pathogen)
{
  m_hasPathogen = pathogen;
  return pathogen;
}

bool burger::getPathogen()
{
  return m_hasPathogen;
}

float burger::getPrice()
{
  return m_price;
}

string burger::getburgName()
{
  return m_burgName;
}

//Customer Functions

string customer::getName()
{
  return m_name;
}

bool customer::setMoney(const float money)
{
  bool ret = false;
  if(money > 0)
  {
    m_money = money;
    ret = true;
  }
  return ret;
}

float customer::getMoney()
{
  return m_money;
}

bool customer::setWeight(const float weight)
{
  bool ret = false;
  if(weight > 0)
  {
    m_weight = weight;
    ret = true;
  }
  return ret;
}

float customer::getWeight()
{
  return m_weight;
}

bool customer::setCholesterol(const short chol)
{
  bool ret = false;
  if(chol > 0)
  {
    m_cholesterol = chol;
        ret = true;
  }
  return ret;
}

short customer::getCholesterol()
{
  return m_cholesterol;
}

bool customer::setAlive(const bool alive)
{
  m_alive = alive;
  return alive;
}

bool customer::getAlive()
{
  return m_alive;
}
void customer::payDeath(burgermeister& krusty)
{
  if(m_alive == false && m_paidDeath == false)
  {
    krusty-=35;
  }
  return;  
}
bool customer::isContestant()
{
  return m_isContestant;
}

float customer::getWeightGain()
{
  return m_weightGain;	
}

int customer::getHealth()
{
  return m_health;	
}

int customer::getBurgNotEaten()
{
  return m_burgNotEaten;
}
int customer::getNumBurgEaten()
{
  return m_burgEaten;
}

void customer::checkAlive()
{
  if(m_cholesterol > 300 || m_health == 0 || m_weightGain >= 80)
  {
    m_alive = false;
    m_isContestant = false;	
  }
  return;	
}

void customer::toss(customer contest[], burgermeister& krusty)
{
  burger thrown;
  const int target = rand() % 16;
  if (target == 15)
  {
	m_isContestant = false;  
	krusty += m_money;
	cout <<"\t \t" << m_name <<" threw a " <<thrown<< " at Krusty! Oops!"<<endl;
	cout <<"\t \t" << "Krusty took all of " << m_name << "'s money!" << endl;
	m_money = 0;
  }else 
  {
    if(rand()%10 < 8) 
	{
	  m_money-= thrown.getPrice();
	  contest[target].toss(contest, krusty);
      cout <<"\t \t"<<m_name << " Throws a "<<thrown<< " at "<< contest[target].m_name << endl; 
	}		
  }    
  return;
}

void customer::vomit(const int POS, customer contest[], burgermeister& krusty)
{
  const string VOM_SOUNDS[] = {"YAGHHH", "BLAHHHH", "GAHHG","BLUHH"};
  
  if(m_vomit == true)
  {
    cout<<"\t" <<m_name<<" Barfs   "<<(VOM_SOUNDS[(rand() % 4)])<<endl;
	m_vomit = false;
	krusty+=5;
    if(POS == 0)
    {
        for(int i = 1; i < 15; i++)
	    {
	      if(contest[i].isContestant() == true)
	      {
		    if(rand() % 2)
	        {
	          cout<<"\t" <<contest[i].getName()<<" Barfs   "<<(VOM_SOUNDS[(rand() % 4)])<<endl;
			  krusty+=5;
	        }else
	        {
			  cout<<"\t"<<contest[i].getName()<<" didn't BARF"<<endl;
			  if((rand() % 10) < 3)
			  {
		        contest[i].toss(contest, krusty);
			  }
			  i = 15;
	        }
  	      }
        }
	}else if(POS == 14)
	{
	  for(int i = 13; i >= 0; i--)
	  {
	    if(contest[i].isContestant() == true)
	    {
		  if(rand() % 2)
	      {
	        cout<< "\t" <<contest[i].getName()<<" Barfs   "<<(VOM_SOUNDS[(rand() % 4)])<<endl;
			krusty+=5;
	      }else
	      {
			cout<<"\t"<<contest[i].getName()<<" didn't BARF"<<endl;
			if((rand() % 10) < 3)
			{
		      contest[i].toss(contest, krusty);
			}
            i = 0;			
	      }
  	    }
      }
	}else
	{
      for(int i = POS+1; i < 15; i++)
	  {
	    if(contest[i].isContestant() == true)
	    {
		  if(rand() % 2)
	      {
	        cout<<"\t" <<contest[i].getName()<<" Barfs   "<<(VOM_SOUNDS[(rand() % 4)])<<endl;
			krusty+=5;
	      }else
	      {
			cout<<"\t"<<contest[i].getName()<<" didn't BARF"<<endl;
			if((rand() % 10) < 3)
			{
		      contest[i].toss(contest, krusty);
			}
			i = 15;
	      }
  	    }
      }
      for(int i = POS-1; i >= 0; i--)
	  {
	    if(contest[i].isContestant() == true)
	    {
		  if(rand() % 2)
	      {
	        cout<<"\t" <<contest[i].getName()<<" Barfs   "<<(VOM_SOUNDS[(rand() % 4)])<<endl;
			krusty+=5;
	      }else
	      {
			cout<<"\t"<<contest[i].getName()<<" didn't BARF"<<endl;
			if((rand() % 10) < 3)
			{
		      contest[i].toss(contest, krusty);
			}
            i = 0;			
	      }
  	    }
      }
	}  
  }
  return;
}

void customer::eat(burgermeister& krusty)
{
  
  burger b;
  
  if(m_isContestant == true && m_alive == true && m_money >= b.getPrice())
  {
    cout<<m_name<<" eats "<<b<<endl;
    float cheese = 0;
    float sauce = 0;
    float wtGain = 0;
    float cholGain = 0;
    int die;
    if(b.getCheese() == true)
    {
      cheese = 2.1;
    }
    if(b.getSauce() == true)
    {
      sauce = 0;	  
    }
  
    cholGain = 2.5 * b.getBacon() + (3.14/2) * b.getPattie() + 
    m_weight/((b.getPickle() + 1)*10);
  
    wtGain = 0.5 * pow(b.getPattie(), 2) + (1.0/8)*pow(b.getBacon(), 2) -
    b.getPickle()/4.0 + cheese + sauce;
    
	m_weightGain += wtGain;
    m_cholesterol = m_cholesterol + cholGain;
    m_weight = m_weight + wtGain;
    m_money = m_money - b.getPrice();
	if(m_health >= 2)
	{
	  m_health-=2;
    }else
	{
	  m_health-=1;	
	}
    if(b.getPathogen() == true)
    {
   	  die = (1 + rand() % (101));
      if(die > m_health)
      {
        m_alive = false;
		m_isContestant = false;
	  }else{
	    m_vomit = true;
		m_health /= 2;
	  }
    }
    m_burgNotEaten = 0;
	m_burgEaten++;
	krusty+=b.getPrice();
  }else if(m_isContestant == true)
  {
    m_burgNotEaten +=1;
  }
  return;	
}

int findWinner(customer contest[], burgermeister& krusty)
{
  int end_loop = 0;
  int winner_pos = 0;
  int isContCtr = 0;
  int numBurgNotEaten = 0;
  int numPosWinners = 0; //Number of possible winners
  int numIC = 0;
  int numBNE = 0;
  
  for (int i = 0; i < 15; i++)
  {
	if(contest[i].isContestant())
	{
	  isContCtr++;
      numIC++;
	}
    if((contest[i].getBurgNotEaten() >= 1))
    {
      numBurgNotEaten++;
	  numBNE++;
	  
	}
	if(numIC == numBNE && numBNE != 0)
    {
	  numPosWinners++;
	}
      numIC = 0;
      numBNE = 0;	   
  }
  
  //Find first possible winner to compare
  for(int i = 0; i < 15; i++)
  {
    if(contest[i].isContestant() && (contest[i].getBurgNotEaten() >= 1))
    {
      winner_pos = i;
	  i = 15;
    }  
  }
  cout<<"Winner Pos: "<<winner_pos<<endl;
  
  
  if(numBurgNotEaten == isContCtr && isContCtr == numPosWinners)
  {
	//Compare other possible winners if possible
   	for(int i = 0; i < 15; i++)
	{
      if(contest[i].isContestant() == true && contest[i].getBurgNotEaten() >= 1)
	  {
	    if(contest[i].getNumBurgEaten() > contest[winner_pos].getNumBurgEaten())
		{
		  winner_pos = i;	
		}else if(contest[i].getWeightGain() > contest[winner_pos].getWeightGain())
		{
		  winner_pos = i;
		}
	  }
	}
	cout<<"The remaining contestants and their stats are... "<<endl;
    for(int i = 0; i < 15; i++)
    {
      if(contest[i].isContestant() && contest[i].getBurgNotEaten() >= 1)
	  {
        cout<<contest[i]<<endl;
	  }
    }
    cout<<"Krusty's Stats are... Money: " <<krusty.getMontHold()<<endl<<endl;
    cout<<"THE WINNER OF KRUSTY'S HORRID AND AWEFULLY KILLING CONTEST IS... "<<endl;
    cout<<"CONGRADULATIONS "<<contest[winner_pos].getName()<<" ON YOUR WIN!!!"<<endl;
	end_loop = 1;
  }
  return end_loop;
}

ostream &operator<<(ostream& os, burger b)
{
  os << b.getburgName();
  return os;
}

ostream &operator<<(ostream& os, customer c)
{
  os << c.getName()<<" money: "<<c.getMoney() <<
        "\n weight: "<<c.getWeight()<<" Cholesterol: "<<
		c.getCholesterol() << " Health: "<<c.getHealth() <<
		" Weight Gain: "<<c.getWeightGain()<<"\n roundsBurgNotEtn: "<<
		c.getBurgNotEaten()<<" numBurgEtn: "<<c.getNumBurgEaten()<<" isContestant: ";
		if(c.isContestant() == true)
		{
		  os<<" True ";	
		}else
		{
		  os<<" False ";  	
		}
        if(c.getAlive() == true)
        {
        os<<" Is ALIVE";
        }else
         {
         os<<" Is DEAD";
         }
  return os;
}

burgermeister operator+=(burgermeister& Krusty, const float money)
{
    Krusty.m_montHold+=money;
    return Krusty;
}
burgermeister operator-=(burgermeister& Krusty, const float money)
{
    Krusty.m_montHold-=money;
    return Krusty;
}
    
int burgermeister::getMontHold()
{
  return m_montHold;	
}
   
