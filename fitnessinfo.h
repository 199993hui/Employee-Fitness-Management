#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

class fitnessinfo 		//Class of Fitness Information to store data ( staff ID, weight and height ) of staff
{
private:
	float height, weight;
	long long int staff_id;

public:
	fitnessinfo();
	~fitnessinfo();

	void setstaff_id(long long int);
	void setweight(float);
	void setheight(float);
	long long int getstaff_id();
	float getweight();
	float getheight();
};
fitnessinfo::fitnessinfo()
{
	height = weight = 0;
}
fitnessinfo::~fitnessinfo()
{
	height = weight = 0;
}
void fitnessinfo::setstaff_id(long long int ID)
{
	staff_id = ID;
}

void fitnessinfo::setweight(float w)
{
	weight = w;
}
void fitnessinfo::setheight(float h)
{
	height = h;
}

long long int fitnessinfo::getstaff_id()
{
	return staff_id;
}

float fitnessinfo::getweight()
{
	return weight;
}
float fitnessinfo::getheight()
{
	return height;
}	
