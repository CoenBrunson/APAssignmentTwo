#include<iostream>
#include<string>
#include<fstream>
#include"Person.h"

class Enemy : public Person
{
private:
	int AC;
	int AP;
public:
	virtual int getAC() { return AC; };
	virtual int getAP() { return AP; };
	virtual void setAC(int i) = 0;
	virtual void setAP(int i) = 0;
};
