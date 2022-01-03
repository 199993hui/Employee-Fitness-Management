#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

class calculation : public personalinfo		// Derived class for calculation of
{											// Date of Birth, Age, BMI,BMR,RMR,Weight category
private:
	double bmi, bmr, rmr;
	int day, month, year, birth, age;
	float Weight, Height;
	fitnessinfo info;
	
public:
	calculation();
	~calculation();
	void setdata(string, long long int, string, float, float);
	void setdata(string, long long int, string);
	void setdata(long long int, float, float);
	void setHeight( float);
	void setWeight(float);
	void BMI();
	void BMR();
	void RMR();
	void change();
	int getage();
	int getday();
	int getmonth();
	int getyear();
	int gets();
	float getWeight();
	float getHeight();
	double getbmi();
	double getbmr();
	double getrmr();
	void printout();
	void showinfo();
	friend void category (calculation& show);
};

calculation::calculation()
{
	day = month = year = birth = age = 0;
	bmi = 0;
	bmr = 0;
	rmr = 0;
}
calculation::~calculation()
{
	day = month = year = birth = age = 0;
	bmi = 0;
	bmr = 0;
	rmr = 0;
}
void calculation:: setdata(string NAME, long long int ID, string GENDER, float w, float h)
{
	setname(NAME);
	setstaffid(ID);
	setgender(GENDER);
	info.setweight(w);
	info.setheight(h);
}
void calculation:: setdata(string NAME, long long int ID, string GENDER)
{
	setname(NAME);
	setstaffid(ID);
	setgender(GENDER);
}
void calculation:: setdata(long long int ID,float w, float h)
{
	personalinfo::setstaffid(ID);
	info.setweight(w);
	info.setheight(h);
}
void calculation:: setHeight(float h)
{
	info.setheight(h);
}
void calculation:: setWeight(float w)
{
	info.setweight(w);
}

void calculation::change ()		// Function calculation class to calculate the date of birth and age of staff
{
	birth = (getstaffid() / 1000000);
	day = birth % 100 ;
	month = (birth/100) % 100;
	
	year = (birth / 10000);
	
	if (year < 9)
	{
		year += 2000;
	}
	else 
	{
		year += 1900;
	}
	
	age = 2020 - year;
}

int calculation::getage()
{
	return age;
}

int calculation::getyear()
{
	return year;
}

int calculation::getmonth()
{
	return month;
}

int calculation::getday()
{
	return day;
}
float calculation::getWeight()
{
	return info.getweight();
}
float calculation::getHeight()
{
	return info.getheight();
}
void calculation::BMI()		// Function calculation class to calculate BMI
{
	bmi = info.getweight() / pow((info.getheight()/100),2);
}

void calculation::BMR()		// Function in calculation class to calculate BMR
{
	if (getgender() == "MALE" || getgender() == "M")
		bmr = (10 * info.getweight()) + (6.25 * info.getheight()) - (5 * (getage())) + 5;
	else if (getgender() == "FEMALE" || getgender() == "F")
		bmr = (10 * info.getweight()) + (6.25 * info.getheight()) - (5 * (getage())) - 161;
}

void calculation::RMR()		// Function in calculation class to calculate RMR
{
	if (getgender() == "MALE" || getgender() == "M")
		rmr = 88.362 + (13.397 * info.getweight()) + (4.799 * info.getheight()) - (5.677 * (getage()));
	else if (getgender() == "FEMALE" || getgender() == "F")
		rmr = 447.593 + (9.247 * info.getweight()) + (3.098 * info.getheight()) - (4.330 * (getage()));
}

double calculation::getbmi()
{
	return bmi;
}

double calculation::getbmr()
{
	return bmr;
}

double calculation::getrmr()
{
	return rmr;
}

void category(calculation &show)		// Friend function in calculation class to estimate the weight category and give some advice
{
	double IDW;
	double low;
	cout << fixed << showpoint;
	if (show.getbmi() <20 )
	{
		cout << "\n\t\t\t\t\t\t ||  Weight category   : " << "\t"  << "Underweight" << "          ||";
	}
	else if(show.getbmi() >= 20 && show.getbmi() < 25)
	{
		cout << "\n\t\t\t\t\t\t ||  Weight category   : " << "\t"  << "Normal weight" << "        ||";
	}
	else if(show.getbmi() >= 25 && show.getbmi() < 30)
	{
		cout << "\n\t\t\t\t\t\t ||  Weight category   :  " << "\t" << "Overweight" << "           ||";
	}
	else if(show.getbmi() >= 30)
	{
		cout << "\n\t\t\t\t\t\t ||  Weight category   : " << "\t"  << "Obese" << "                ||";
	}
	cout << endl;
	cout << "\t\t\t\t\t\t  ____________________________________________________" << endl;
	if( show.info.getheight() >= 152.4)
	{	
		if (show.getgender() == "MALE" || show.getgender() == "M")
		{
			IDW = 50 + (0.91 * (show.info.getheight() - 152.4));
			cout << "\n\t\t\t\t\t\t   Ideal Body Weight : " << "\t" << left << std::setw(5) << setprecision(2) << IDW ;		
		}
		else if (show.getgender() == "FEMALE" || show.getgender() == "F")
		{
			IDW = 45.5 + (0.91 * (show.info.getheight() - 152.4));
			cout << "\n\t\t\t\t\t\t   Ideal Body Weight : " << "\t" << left << std::setw(5) << setprecision(2) << IDW;
		}
		cout << endl;
		if( show.info.getweight() < IDW && show.getbmi() <20)
		{
			low = ((IDW - show.info.getweight()) / IDW) * 100;
			cout << "\n\t\t\t\t\t\t  It is " << setprecision(2) << low << "% below Ideal Body Weight.";
			cout << "\n\t\t\t\t\t\t  You should eat more frequently.";
			cout << "\n\t\t\t\t\t\t  Choose nutrient-rich foods. As part of an ";
			cout << "\n\t\t\t\t\t\t  overall healthy diet, choose whole-grain breads,";
			cout << "\n\t\t\t\t\t\t  pastas and cereals; fruits and vegetables;\n\t\t\t\t\t\t  dairy products; lean protein sources; and nuts and seeds.";
		}
		else if( low < 0.01)
		{
			if( show.info.getweight() < IDW )
			cout << "\n\t\t\t\t\t\t It is " << left << std::setw(29) << setprecision(2) << low << "% below Ideal Body Weight.";
			else if( show.info.getweight() > IDW)
			cout << "\n\t\t\t\t\t\t  It is " << setprecision(2) << low << "% above Ideal Body Weight.";
			cout << "\n\t\t\t\t\t\t  Well Done !!! You have archived your ideal \n\t\t\t\t\t\t  body weight.";
		}
		
	 	else if( show.info.getweight() > IDW && show.getbmi() >= 25 && show.getbmi() < 30)
		{
			low = (( show.info.getweight()) - IDW / IDW) * 100;
			cout << "\n\t\t\t\t\t\t  It is " << setprecision(2) << low << "% above Ideal Body Weight.";
			cout << "\n\t\t\t\t\t\t  You should do more exercise and eat more vegetables \n\t\t\t\t\t\t  and fruit.";
		}
		else if(show.info.getweight() != IDW && show.getbmi() >= 20 && show.getbmi() < 25)
		{
			if( show.info.getweight() < IDW )
			cout << "\n\t\t\t\t\t\t  It is " << setprecision(2) << low << "% below Ideal Body Weight.";
			else if( show.info.getweight() > IDW)
			cout << "\n\t\t\t\t\t\t  It is " << setprecision(2) << low << "% above Ideal Body Weight.";
			cout << "\n\t\t\t\t\t\t  However you have a normal weight, continue \n\t\t\t\t\t\t  embracing a healthy to maintain your weight.";
		}
		else if(show.info.getweight() > IDW && show.getbmi() >= 30)
		{
			low = (( show.info.getweight()) - IDW / IDW) * 100;
			cout << "\n\t\t\t\t\t\t  It is " << setprecision(2) << low << "% above Ideal Body Weight.";
			cout << "\n\t\t\t\t\t\t  Losing weight can reduce your risk of heart disease ";
			cout << "\n\t\t\t\t\t\t  and stroke; risk factors likehigh blood pressure,";
			cout << "\n\t\t\t\t\t\t  plasma glucose and sleep apnea. It can also help " ;
			cout << "\n\t\t\t\t\t\t  lower your total cholesterol and triglycerides.\n\t\t\t\t\t\t  Losing weight can mean less heart disease, less diabetes and less cancer.";
			cout << "\n\t\t\t\t\t\t  Please take care of your body.";
			cout << "\n\t\t\t\t\t\t  you may change you diet. To lose weight, you have to reduce the ";
			cout << "\n\t\t\t\t\t\t  amount of calories you consume.You must do more physical activities.";
		}
	}
	else
		cout << "\n\t\t\t\t\t\t  Ideal Body Weight : " << "\n\t\t\t\t\t\t  Not appropriate, since the height is below 152.4 cm";
}		// End category friend function

void calculation::printout()		// Function in calculation class to display the information of all the staff
{
	cout << "\t|  " << left << setw(27) << getname();
	if(getstaffid() <= 99999999999 && getstaffid() > 9999999999 )
		cout << "| 0" << left << setw(13) << getstaffid();
	else if(getstaffid() <= 9999999999 && getstaffid() > 999999999)
		cout << "| 00" << left << setw(12) << getstaffid();
	else if(getstaffid() <= 999999999 && getstaffid() > 99999999)
		cout << "| 000" << left << setw(11) << getstaffid();
	else
		cout << "| " << left << setw(14) << getstaffid();
	cout << "|  " << left << setw(5) << getage();
	if (getgender() == "FEMALE" || getgender() == "F")
		cout << left << setw(11) << "|  Female";
	else if (getgender() == "MALE" || getgender() == "M")
		cout << left << setw(11) << "|  Male";
	else;
	cout << "|  " << setw(5) << getyear() << left << setw(2) <<"-" ;
	if(getmonth() <10) cout << "0" << left << setw(2) << getmonth();
	else cout << left << setw(3) << getmonth() ;
	cout << left << setw(2) << "-" ;
	if ( getday() < 10) cout << "0" << left << setw(4) << getday();
	else cout << left << setw(5) << getday();
	cout << fixed << showpoint;
	cout << "|   " << left << setw(11) << setprecision(2) << info.getweight();
	cout << "|   " << left << setw(10) << setprecision(2) << info.getheight();
	cout << "|  " << left << setw(7) << setprecision(2) << getbmi();
	cout << "| " << left << setw(9) << setprecision(2) << getbmr();
	cout << "| " << left << setw(8) << setprecision(2) << getrmr() << "||" << endl;
	
}		// End printout function

void calculation::showinfo()		// Function in calculation class to display a staff information
{
	cout << "\n\t\t\t\t\t\t\t\t   Staff's information" << endl;
	cout << "\t\t\t\t\t\t  ____________________________________________________" << endl;
	cout << "\n\t\t\t\t\t\t ||  Name           :" << "\t" << left << std::setw(29) << getname() << "||"<< endl;
	cout << "\n\t\t\t\t\t\t ||  ID             :" << "\t" ;
	if(getstaffid() <= 99999999999 && getstaffid() > 9999999999 )
		cout << "0" << left << std::setw(28) <<  getstaffid()  << "||"<< endl;
	else if(getstaffid() <= 9999999999 && getstaffid() > 999999999)
		cout << "00" << left << std::setw(27) << getstaffid() << "||" << endl;
	else if(getstaffid() <= 999999999 && getstaffid() > 99999999)
		cout << "000" << left << std::setw(26)<< getstaffid() << "||" << endl;
	else
		cout << left << std::setw(29) << getstaffid() << "||" << endl;
	cout << "\n\t\t\t\t\t\t ||  Age            :" << "\t" << left << std::setw(29) << getage() << "||" << endl;
	cout << "\n\t\t\t\t\t\t ||  Gender         :" << "\t" ;
	if (getgender() == "FEMALE" || getgender() == "F")
		cout << left << std::setw(29) <<  "Female" << "||" << endl;
	else if (getgender() == "MALE" || getgender() == "M")
		cout << left << std::setw(29) << "Male" << "||" << endl;
	cout << "\n\t\t\t\t\t\t ||  Date of Birth  :" << "\t" << left << std::setw(5) << getyear() << "-" << left << std::setw(2)<< getmonth() << "-" << left << std::setw(20)<< getday() << "||" << endl;
	cout << "\n\t\t\t\t\t\t ||  Weight         :" << "\t" << left << std::setw(29) << setprecision(2) << info.getweight() << "||" << endl;
	cout << "\n\t\t\t\t\t\t ||  Height         :" << "\t" << left << std::setw(29) << setprecision(2) << info.getheight() << "||" << endl;
	
}		// End calculation function 
