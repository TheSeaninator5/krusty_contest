// Programmer: Colton Walker // Date: 11/8/2018
// instructor Name: Price // Section: 1B
// File: hw9fncts.cpp // Description: two classes of a burger and customer

#include <iostream>
#include <cmath>
#include <fstream>
#include "hw9.h"

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

void customer::eat()
{
  burger b;
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
  
  m_cholesterol = m_cholesterol + cholGain;
  m_weight = m_weight + wtGain;
  m_money = m_money - b.getPrice();
  if(b.getPathogen() == true)
  {
   	die = (1 + rand() % (101));
    if(die > m_health)
    {
      m_alive = false;
	}else{
	  m_vomit = true;
	}
  }
  return;	
}


ostream &operator<<(ostream& os, burger b)
{
  os << "Burger: patties: "<<b.getPattie()<<" pickles: "<<b.getPickle() <<
        " bacon: "<<b.getBacon();
        if(b.getCheese() == true)
        {
          os<<"\n has cheese: true ";
        }else
         {
           os<<"\n has cheese: false ";
         }
         if(b.getSauce() == true)
        {
          os<<" has sauce: true ";
        }else
         {
           os<<" has sauce: false ";
         }
        if(b.getPathogen() == true)
        {
          os<<" has pathogen: true ";
        }else
         {
           os<<" has pathogen: false ";
         }
  return os;
}

ostream &operator<<(ostream& os, customer c)
{
  os << "Customer: name: "<<c.getName()<<" money: "<<c.getMoney() <<
        "\n weight: "<<c.getWeight()<<" Cholesterol: "<<c.getCholesterol();
        if(c.getAlive() == true)
        {
        os<<" Is ALIVE";
        }else
         {
         os<<" Is DEAD";
         }
  return os;
}

burgermeister operator+= (const float money)
{
    m_montHold+=money;
    return;
}
burgermeister operator-= (const float money)
{
    m_montHold-=money;
    return;
}
    
   
