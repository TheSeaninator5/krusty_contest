// Programmer: Colton Walker // Date: 11/8/2018
// instructor Name: Price // Section: 1B
// File: hw9.h // Description: two classes of a burger and customer

#ifndef HW9_H
#define HW9_H
#endif
using namespace std;

//Desc: getName() will return a name from the simpson_names.dat file
//Pre: none
//Post: a name was returned to the string
string makeName();

//Desc: getBurgNum() will set the parameters for pat, bac, and pic
//Pre: burgCode must be a positive integer 
//Post: the parameters are set based on burgCode
void getBurgNum(const int burgCode, int & pat, int & bac, int & pic);

//Desc: burgName() will create a name for a burger based on the number of 
//pickles, patties, and bacon
//Pre: None
//Post: a string name will be returned
string burgName(const int burgCode, const bool cheese, const bool sauce);

//Desc: getBurgNum() will set the parameters for pat, bac, and pic
//Pre: burgCode must be a positive integer 
//Post: the parameters are set based on burgCode
void getBurgNum(const int burgCode, int & pat, int & bac, int & pic);

class burgermeister
{
	private:
	string m_name;
	float m_montHold;
	
	
	public:
	burgermeister()
	{
	  m_name = "Krusty";
	  m_montHold = 100.0;
	
	}
	
	burgermeister(string name, float mon)
    {
      m_name = name;
	  m_montHold = mon;
    }
	
	friend burgermeister operator+=(burgermeister& Krusty, 
	const float money);
	
	friend burgermeister operator-=(burgermeister& Krusty, 
	const float money);
	
	//Desc: gets the montHold in the burgermeister 
	//Pre:none
	//Post: returned the montHold
	int getMontHold();
	
};
class burger
{
  private:
    int m_numPatties;
    int m_numBacon;
    int m_numPickles;
    bool m_hasCheese;
    bool m_hasSauce;
    bool m_hasPathogen;
    int m_burgCode;
    string m_burgName;
    int m_price;
	
  public:
    //default constructor
    burger() 
    { 
      m_numPatties = 1 + rand() % (4);
      m_numBacon = 1 + rand() % (4);
      m_numPickles = 1 + rand() % (4);
      m_hasCheese = rand() % 2;
      m_hasSauce = rand() % 2;
      m_hasPathogen = !(rand() % 10);
      m_burgCode = m_numPatties*100 + m_numBacon*10 + m_numPickles;
      m_burgName = burgName(m_burgCode, m_hasCheese, m_hasSauce);
      m_price = static_cast<float>(0.75 * m_numPatties) + 
            static_cast<float>(0.5 * m_numBacon) + 
            static_cast<float>(0.25 * m_numPickles) + 
	    static_cast<float>(0.1 * m_hasCheese) + 
            static_cast<float>(0.25 * m_hasCheese) + (0.5);	
    }
	
    //constructor that takes patties, bacon, pickles, whether it has 
	//cheese and a pathagen
    burger(int pat, int bac, int pic, bool cheese, bool path)
    {
      m_numPatties = pat;
      m_numBacon = bac;
      m_numPickles = pic;
      m_hasCheese = cheese;
      m_hasPathogen = path;
      m_burgName = burgName(m_burgCode, m_hasCheese, m_hasSauce);
    }
	
    //Desc: gets the name from the burger
    //Pre: none
    //Post: the namefrom the burger was returned
    string getburgName();
    //Desc: gets the burgCode from the burger
    //Pre: none
    //Post: the burgCode from the burger was returned
    int getburgCode();
    //Desc: gets the num of patties from the burger
    //Pre: none
    //Post: the num of patties from the burger was returned
    int getPattie();
    //Desc: set the num of patties to the burger
    //Pre: none
    //Post: the num of patties is now given to the burger
    bool setPattie(const int pattie);
    //Desc: gets the num of oz of bacon from the burger
    //Pre: none
    //Post: the num of oz of bacon from the burger was returned
    int getBacon();
    //Desc: set the num of bacon to the burger
    //Pre: none
    //Post: the num of oz of bacon is now given to the burger
    bool setBacon(const int bacon);
    //Desc: gets the num of pickles from the burger
    //Pre: none
    //Post: the num of pickles from the burger was returned
    int getPickle();
    //Desc: set the num of pickles to the burger
    //Pre: none
    //Post: the num of pickles is now given to the burger
    bool setPickle(const int pickle);
    //Desc: gets whether cheese is on the burger
    //Pre: none
    //Post: whether cheese is from the burger was returned
    bool getCheese();
    //Desc: set whether there is cheese to the burger
    //Pre: none
    //Post: whether there is cheese is now given to the burger
    bool setCheese(const bool cheese);
    //Desc: gets whether sauce is on the burger
    //Pre: none
    //Post: whether sauce is from the burger was returned
    bool getSauce();
    //Desc: set whether there is sauce to the burger
    //Pre: none
    //Post: whether there is sauce is now given to the burger
    bool setSauce(const bool sauce);
    //Desc: gets whether a pathogen is on the burger
    //Pre: none
    //Post: whether a pathogen is on the burger was returned
    bool getPathogen();
    //Desc: set whether there is a pathogen on the burger
    //Pre: none
    //Post: whether there is a pathogen is now given to the burger
    bool setPathogen(const bool pathegen);
    //Desc: gets the price from the burger
    //Pre: none
    //Post: the price of burger was returned
    float getPrice();
};

class customer
{
  private:
    string m_name;
    //This is their "local monetary holdings" in $
    float m_money;
    float m_weight;
    float m_cholesterol;
    bool m_alive;
	int m_health;
	bool m_vomit;
	bool m_isContestant;
	
  public:
    //default constructor
    //WILL DRAW NAME FROM A FILE OF NAMES!!!!!
    //MAKE GETNAME FUNCTIONNS LK&T)U@T*@&$* $W(*Y_($^_(*@
    customer()
    {
      m_name = makeName();
      m_money =  25 + rand() % (51);
      m_weight = 90 + rand() % (161);
      m_alive = true;
	  m_health = (1 + rand() % (100));
	  m_vomit = false;
	  m_isContestant = true;
    }
        
    //Desc: gets the name of the customer
    //Pre: none
    //Post: the name of the customer was returned
    string getName();
    //Desc: gets the amount of money the from customer
    //Pre: none
    //Post: the amount of money the customer has was returned
    float getMoney();
    //Desc: set money to the customer
    //Pre: none
    //Post: the money is now given to the customer
    bool setMoney(const float money);
    //Desc: gets the weight of the customer
    //Pre: none
    //Post: the weight of the customer was returned
    float getWeight();
    //Desc: set the weight to the customer
    //Pre: none
    //Post: the weight is now given to the customer
    bool setWeight(const float weight);
    //Desc: gets the cholesterol of the customer
    //Pre: none
    //Post: the cholesterol of the customer was returned
    short getCholesterol();
    //Desc: set the cholesterol to the customer
    //Pre: none
    //Post: the cholesterol is now given to the customer
    bool setCholesterol(const short cholesterol);
    //Desc: gets the aliveness of the customer
    //Pre: none
    //Post: the aliveness of the customer was returned
    bool getAlive();
    //Desc: set the aliveness to the customer
    //Pre: none
    //Post: the aliveness is now given to the customer
    bool setAlive(const bool alive);
    //Desc: Will remove money, increase cholesterol, increase weight,
    //if a pathagen is present then will kill the customer
    //Pre: Customer must be alive
    //Post: Customers money, cholesterol, weight and aliveness were changed
    void eat();
	//Desc: Will throw a burger at a random person in the array or krusty
	//Pre: None
	//Post: A burger was throw at a random person or krusty
	int toss();
	//Desc: Will cause the person to vomit and then 50% chance 
	//for neighbor to vomit
	//Pre: None
	//Post: The customer vomited and possibly caused the neighbors to vomit
	void vomit();
};


ostream &operator<<(ostream &stream, burger b);
ostream &operator<<(ostream &stream, customer c);
