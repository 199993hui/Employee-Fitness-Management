#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

class personalinfo		// Class of Personal Information to store data ( name, staff ID and gender ) of the staff
{
private:
	string name;
	long long int staffid;
	string gender;

public:
	personalinfo();
	~personalinfo();

	void setname(string);
	void setstaffid(long long int);
	void setgender(string);

	string getname();
	long long int getstaffid();
	string getgender();

};
personalinfo::personalinfo()
{
	name = " ";
	staffid = 0;
	gender = " ";
}
personalinfo::~personalinfo()
{
	name = " ";
	staffid = 0;
	gender = " ";
}
void personalinfo::setname(string NAME)
{
	name = NAME;
}

void personalinfo::setstaffid(long long int ID)
{
	staffid = ID;
}

void personalinfo::setgender(string GENDER)
{
	gender = GENDER;
}


string personalinfo::getname()
{
	return name;
}

long long int personalinfo::getstaffid()
{
	return staffid;
}

string personalinfo::getgender()
{
	return gender;
}

