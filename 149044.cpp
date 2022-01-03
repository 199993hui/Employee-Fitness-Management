#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include "personalinfo.h"
#include "fitnessinfo.h"
#include "calculation.h"

using namespace std;

void print(int &, int &, int &, int &, int &, int &, float &, float &, float &, float &, float &, float &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int &);
void oprint(fstream &, int &, int &, int &, int &, int &, int &, float &, float &, float &, float &, float &, float &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int &);
void addinfo(string &,unsigned long long int &, string &, float &, float &, unsigned int &);	
void category(calculation &);
void choosemenu(unsigned int &);
void calavg(int &, int &, float &, float &, int &, float &, float &);
void bmicat(calculation [], int &, int &, int &, float &, float &, int &, int &, int &, int &);

int main()							// Main function
{									// Declare functions and variables
	calculation read[501];
	void openfile(calculation []);		
	openfile(read);					// Call open fill function to read in file	
	system("pause");
	return 0;
} // End main

void openfile(calculation read[])	// Function to read in the file
{
	fstream indata, infile, outdata;		// Function and variables declaration
	int numfile, x, y ;
	char q;
	string name,gender, dataname, filename, outfile;
	unsigned long long int staffid;
	unsigned int choice = 14;
	float weight, height;
	void dothing(calculation [], int &,fstream &, string & );
	cout << "\n\n\n\t\t\t  --------------------------------------------------------------------------------------------------" << endl;		// Name of the program to welcome user
	cout << "\t\t\t  ||					WELCOME TO LET'S GET FIT				  ||" << endl;
	cout << "\t\t\t  --------------------------------------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t  Please enter two file name :" << endl;
file1:
	cout << "\n\t\t\t\t\t ( personal information in form of staff ID, name and gender)";
	cout << "\n\t\t\t\t\t                 (exit program by entering '?' )  \n\n\t\t\t\t\t File 1: ";		// Get the file name 1 from user 
	getline(cin,dataname);
	if ( dataname == "?") {	cout << "\n\t\t\t\t\t\t\t\tTHANK   YOU  !!!\n\n\t\t\t\t\t\t\t";
							system("pause");
							exit(1);
						  }
	dataname += ".txt";
	indata.open(dataname.c_str(), ios::in);		// Open file 1 ( Perosnal information file )
	
	while (indata.fail())				// Test the error of opening input file 1
	{
		indata.clear();
		cout << "\n\t\t\t\tERROR :" << dataname << " could not be opened!!!";
		cout << "\n\t\t\t\t  Pleases enter again ";
		goto file1;
	}
	cout << "\n\t\t\t  -------------------------------------------------------------------------------------------------";
file2:
	cout << "\n\t\t\t\t\t ( fitness information in form of staff ID, weight and height)";  // Get the file name 2 from user
	cout << "\n\t\t\t\t\t                 (exit program by entering '?' )  \n\n\t\t\t\t\t File 2: ";
	getline(cin,filename);
	if ( filename == "?")  {	cout << "\n\t\t\t\t\t\t\t\tTHANK   YOU  !!!\n\n\t\t\t\t\t\t\t";
							system("pause");
							exit(1);
						   }
	filename += ".txt";
	infile.open(filename.c_str(), ios::in);		// Open file 2 ( Fitness information file )
	
	while (infile.fail())				// Test the error of opening the input file 2
	{
		indata.clear();
		cout << "\n\t\t\t\tERROR :" << filename << " could not be opened!!!";
		cout << "\n\t\t\t\t  Pleases enter again.";
		goto file2;
	}
	system("cls");
	choosemenu (choice);
	cout << "\n\t\t\t\t  An output file is to save all the latest staff information after the program ends.\n\t\t\t\tOtherwise, the data will be lost after the program ends.";
	cout << "\n\t\t\t\t  Please enter the set a name for the output file or if it is exist, key in the file name" << endl;
	cout << "\n\t\t\t\t  A file name cannot contain '\\'  '/' ':' '*' '?' ' \" ' '<' '>' or '|' \n";
file3:
	cout << "\n\t\t\t\t\t                 (exit program by entering '?' )  \n\n\t\t\t\t\t Output File : "; getline(cin, outfile);		// Get the file name from user
	if ( outfile == "?")  {	cout << "\n\t\t\t\t\t\t\t\tTHANK   YOU  !!!\n\n\t\t\t\t\t\t\t";
							system("pause");
							exit(1);
						  }
	outfile += ".txt";
	outdata.open(outfile.c_str(),ios::out);						// Open file 3 ( Output file )
	if (outdata.fail())				// Test the error of opening this output file
	{
		outdata.clear();
		cout << "\n\t\t\t\tERROR :  Output file could not be opened!!!";
		cout << "\n\t\t\t\t  All the data will be lost after exiting this program. Please check it.";
		cout << "\n\t\t\t\t  A file name cannot contain '\\'  '/' ':' '*' '?' ' \" ' '<' '>' or '|' \n\n";
		goto file3;
	}
	else			// If the output file can be opened, tell the user that the output file is succesfully opened
		cout << "\n\t\t\t\t  An output file (" << outfile << ") exists to store all the latest staff information\n\t\t\t\t  after the program ends.";
	cout << "\n\n\t\t\t\t  Reading file" << endl <<endl << "\t\t\t\t\t";	// Inform the user that the file is being read
	x=0;	
	system("pause");
	while(!indata.eof())			// Test the end of input file 1
	{
		indata >> staffid;
		getline(indata, name, '\t');
		getline(indata, name, '\t');
		transform(name.begin(), name.end(), name.begin(), ::toupper);
		indata >> gender;
		transform(gender.begin(), gender.end(), gender.begin(), ::toupper);
		read[x].setdata(name, staffid, gender);
		x++;
		if (indata.eof())	
			break;				
	}
	y=x;
	while (!infile.eof())			// Test the end of file of input file 2
	{
		infile >> staffid >> weight >> height;
		read[y].setdata(staffid, weight, height);
		for(int j = 0; j < x ; j++)
		{
			if(read[j].getstaffid() == read[y].getstaffid())
				read[j].setdata(staffid, weight, height);
		}
		y++;
		if(infile.eof())
			break;
	}
	cout << "\n\t\t\t\t  File recorded" << endl << "\n\t\t\t\t\t";
	system("pause");
	numfile = x;
	dothing(read, numfile, outdata, outfile);					// Call function to do operation of the system
	indata.close();				// Close the file 1 ( personal information file )
	infile.close();				// Close the file 2 ( fitness information file )
	outdata.close();			// Close the file 3 ( output file )
}	// 	End openfile function

void dothing(calculation read[], int &numfile, fstream &outdata, string &outputfile)	// Function to do all the operations
{
	unsigned int option,choice;				// Variables declaration
	string name,gender;
	unsigned long long int staffid;
	float weight, height;
	
	void display(calculation [], int &);	// Function declaration
	void add(calculation [], int &);
	void asccedingdisplay(calculation [], int &, unsigned int&);
	void searchinfo (calculation [], int &);
	void modifyinfo(calculation [], int &);
	void analysisinfo(calculation [], int &,fstream &);
	void deleteinfo(calculation [], int &, unsigned int &);
	void outfile(calculation [], int &, fstream &outdata);
	display(read, numfile);					// Display the file read in
menu:	system("cls");						// Main menu
		choice =14;
		choosemenu(choice);
	  	choice =13;
		choosemenu(choice);
valid1:
		cout << "Your choice : ";cin >> option;						// Let user to make a choice
		if(cin.fail() || option > 8)		// Limit user to input a correct and valid choice
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << "\n\t\t\t\t\tPlease enter a valid number : ";
			goto valid1;
		}
		else
		{	// Call the functions to do the operations according to the main menu 
			if (option == 1)
				add(read, numfile);			// Call the  function to add new staff information
			else if (option ==2 || option ==3 || option ==4)
				asccedingdisplay(read, numfile, option);	// Call the function to display all the staff information
			else if (option ==5)
				searchinfo(read, numfile);		// Call the function to search staff by a information
			else if (option ==6)
				modifyinfo(read, numfile);		// Call the function to modify some specific information of a staff
			else if (option ==7)
				analysisinfo(read, numfile, outdata);		// Call the function to analysis a staff information or the overall information
			else if (option == 8)
				deleteinfo(read, numfile, option);		// Call the function to delete a staff information
			else goto Exit;
		}
		goto menu;	
Exit:
	system("cls");
	choice =14;
	choosemenu(choice);							// Display a thank you to user after user chose to end the program
	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t       ============================================================================";
	cout << "\n\t\t\t\t       ||	   		    THANK YOU!!!!			         ||";
	cout << "\n\t\t\t\t       ============================================================================";
	cout << "\n\n\t\t\t\t       All the latest staff information are saved into a text file called " << outputfile ;
	cout << "\n\t\t\t\t       You may press enter to exit...";
	cin.get();
	cin.get();
	outfile(read,numfile, outdata);		// Call function to store all the latest staff information into a output text file ;
	
	system("cls");
	exit(1);
}	// End dothing funtion

void display(calculation read[], int &numfile)		// Function to display all the staff informations
{
	unsigned int choice =3;
	choosemenu(choice);
	for (int y = 0; y < numfile; y++)
	{
		read[y].change();
		read[y].BMI();
		read[y].BMR();
		read[y].RMR();
		cout << "  " << y+1 << ")";
		read[y].printout();
	}
	cout << "\t___________________________________________________________________________________________________________________________________________________" << endl << "\t\t\t\t\t";
	system("pause");
}	// End display function

void add(calculation read[], int & numfile)		// Function to add new staff information
{
	unsigned int choice =14 ;
	string name,gender;
	unsigned long long int staffid;
	float weight, height;
	string back;
	Addinfo:
		do{
		system("cls");
		choosemenu(choice);
		if ( numfile >= 500)			// when the array of object is full due to the limit , inform the user that the storage is full 
		{
			cout << "\n\t\t\t\tThe storage is full, please remove some unnecessary information to add new information.\n\t\t\t\t";
			system("pause");
			goto endadd;
		}
		cout << "\n\t\t\t\t\t\t    ===============================================" << endl;
		cout << "\n\t\t\t\t\t\t          Please enter the staff information." << endl;
		cout << "\n\t\t\t\t\t\t    ===============================================" << endl;
		choice =1;
		addinfo(name, staffid, gender, weight, height,choice);
		if(height==0)
			goto endadd;
		read[numfile].setdata(name, staffid, gender, weight, height);
		read[numfile].change();	
		read[numfile].BMI();
		read[numfile].BMR();
		read[numfile].RMR();
		cout << "\n\n\t\t\t\t\t\t\tNew staff information added.\n\t\t\t\t\t\t\tPlease press ENTER to continue" << endl << endl;
		cin.ignore();cin.get();
		system("cls");
		choice = 14;
		choosemenu(choice);
			// Display the newly added staff information
		read[numfile].showinfo();
		cout << "\n\t\t\t\t\t\t  ____________________________________________________" << endl << endl << endl << endl;
		numfile++;
		cout << "\n\t\t\t\t\t\tDo you what to continue to add new staff information ?";
		cout << "\n\t\t\t\t\t\tPress 'y' to search again or press any key to go back.";		// Ask the user to continue add another new staff information or not
		cout << "\n\t\t\t\t\t\tYour choice : ";cin >> back;
		transform(back.begin(), back.end(), back.begin(), ::toupper);
		}while(back == "Y");
	endadd:
		cout << " ";
}	// End add function

void asccedingdisplay(calculation read[], int &numfile, unsigned int&option)		// Function to display all the staff information according to 
{																					// name , staff ID or age
	if(option == 2)				// Display according to name													
	{															
		for(int i=0; i<= numfile ;i++)
			for(int j=0; j<numfile; j++)
				if(read[j].getname() > read[j+1].getname())
				{
					read[numfile] = read[j];
					read[j] = read[j+1];
					read[j+1] = read[numfile];
				}
	}
	else if (option == 3)		// Display according to staff ID
	{
		for(int i=0; i<= numfile ;i++)
			for(int j=0; j<numfile; j++)
				if(read[j].getstaffid() > read[j+1].getstaffid())
				{
					read[numfile] = read[j];
					read[j] = read[j+1];
					read[j+1] = read[numfile];
				}
	}
	else if(option ==4)			// Display according to age
	{
		for(int i=0; i<= numfile ;i++)
			for(int j=0; j<numfile; j++)
				if(read[j].getage() > read[j+1].getage())
				{
					read[numfile] = read[j];
					read[j] = read[j+1];
					read[j+1] = read[numfile];
				}
	}
	display(read,numfile);
}	// End asscedingdsiplay function

void searchinfo(calculation read[], int &numfile)		// Function to search the staff information
{
	unsigned int choice;
	string name,gender;
	unsigned long long int staffid;
	float weight, height;
		do{
		int s=0;
		system("cls");
		choice = 14;
		choosemenu(choice);		// Display Searching Menu to let user to choose the method to search the staff information
	unsigned int option =5;
		choosemenu(option);
valid2:
		cout << "Your choice : ";cin >> choice;
		if(cin.fail() || choice >6 )		// To limit the user to input a correct and valid choice
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << "\n\t\t\t\tERROR !!!\n\t\t\t\t\tPlease enter a valid number again : ";
			goto valid2;
		}
		if (choice == 1)					// Searching by name of staff
		{
search1:  																		
			cout << "\n\t\t\t\t\tPlease enter the name which you want to search:";
			getline(cin, name);
			getline(cin, name);
			transform(name.begin(), name.end(), name.begin(), ::toupper);
			system("cls");
			option=2;
			for (int i = 0; i < numfile; i++)
				if (name == read[i].getname())
				{
					choosemenu(option);
					s++; option+=20;
					cout << "  " << s << ") ";
					read[i].printout();
				}
			if(s==0)			// Tell the user that  the name searched could not be found
			{
				option = 14;
				choosemenu(option);
				cout << "\n\n\t\t\t\t\tThe staff "<< name <<" could not be found.(The name recorded might have spaces or tabs)";
			}
			else if (s > 0)
				cout << "\n\n\n\t\t(If the name you search do not show in this list it means the name consists of some tabs or spaces at the end or you spell it wrongly.";
			cout << "\n\t\t\t\t\t";
			system("pause");
		}
		
		else if( choice ==2 )				//Searching by staff ID
		{
		search2:   																
			s=0;
			cout << "\n\t\t\t\t\t\tPlease enter the staff ID  which you want to search (IC no. consists of 12 numbers) : \n\t\t\t\t\t\t";
		idagain1:
			cin >> staffid;
			if(cin.fail() || staffid > 991231000000 || staffid < 101000000 )		// Limit the user to key in the correct and valid staff ID
			{
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout << "\n\t\t\t\tERROR!!!\n\t\tInvalid staff ID : \n\t\t\t\t\tPlease enter staff ID again (IC no consists of 12 numbers ) : \n\t\t\t\t\t";
				goto idagain1;
			}
			system("cls");
			option=2;
			for (int i = 0; i < numfile; i++)
				if (staffid == read[i].getstaffid())
				{
					choosemenu(option);
					s++; option+=20;
					cout << "  " << s << ") ";
					read[i].printout();
				}		
			if(s==0)				// Tell the user that the staff ID searched could not be found
			{
				option = 14;
				choosemenu(option);
				cout << "\n\n\t\t\t\t\tThe staff ID could not be found.";	
			}			
			cout << "\n\t\t\t\t\t";
			system("pause");
		}
		else if (choice ==3 )				// Searching by age of staff
			{
				unsigned int age;
				s=0;
				cout << "\n\t\t\t\t\tPlease enter the age which you want to search :";
			ageagain:
				cin >> age;
				if(cin.fail())		// Limit the user to input correct and valid age
				{
					cin.clear();
					cin.ignore(INT_MAX,'\n');
					cout << "\n\t\t\t\tERROR!!!\n\t\t\tInvalid number : \n\t\t\t\t\tPlease enter the age again : ";
					goto ageagain;
				}
			system("cls");
			option=2;
			for (int i = 0; i < numfile; i++)
				if ( age == read[i].getage())
				{
					choosemenu(option);
					s++; option+=20;
					cout << "  " << s << ") ";
					read[i].printout();
				}	
			if(s==0)				// Tell the user that the age searced could not be found
			{
				option = 14;
				choosemenu(option);
				cout << "\n\n\t\t\t\t\tThe staff with age "<< age <<" could not be found.";	
			}
			cout << "\n\t\t\t\t\t";
			system("pause");
		}
		else if (choice == 4 )				// Searching by gender of staff
		{
				s=0;
				cout << "\n\t\t\t\t\tPlease enter the gender which you want to search ('m' for male and 'f' for female) :";
			genderagain1:	
				cin >> gender;
				transform(gender.begin(), gender.end(), gender.begin(), ::toupper);
				if(gender!= "M" && gender != "F")		// Limit the user to input a correct and valid information
				{
					cout << "\n\t\t\t\tERROR!!!\n\t\t\t\t\tPlease enter a valid gender again : ";
					goto genderagain1;
				}
			if(gender == "M")
				gender ="MALE";
			else if (gender=="F")
				gender = "FEMALE";
				option=2;
			for (int i = 0; i < numfile; i++)
				if (gender == read[i].getgender())
				{
					choosemenu(option);
					s++; option+=20;
					cout << "  " << s << ") ";
					read[i].printout();
				}		
			if(s==0)			// Tell the user that the gender searchd could not be found
			{
				option = 14;
				choosemenu(option);
				cout << "\n\n\t\t\t\t\tNo " << gender <<" could not be found.";
			}
			cout << "\n\t\t\t\t\t";
			system("pause");
		}
		else if (choice ==5 )				// Searching by weight of staff
		{
				s=0;
				cout << "\n\t\t\t\t\tPlease enter the weight which you want to search :";
			weightagain:
				cin >> weight;
				if(cin.fail() || weight <= 0)		// Limit the user to key in a correct and valid weight
				{
					cin.clear();
					cin.ignore(INT_MAX,'\n');
					cout << "\n\t\t\t\tERROR!!!\n\t\t\tInvalid number : \n\t\t\t\t\tPlease enter the weight again : ";
					goto weightagain;
				}
			system("cls");
			option =2;
			for (int i = 0; i < numfile; i++)
				if ( weight == read[i].getWeight())
				{
					choosemenu(option);
					s++; option+=20;
					cout << "  " << s << ") ";
					read[i].printout();
				}		
			if(s==0)			// Tell the user that the weight searched could not be found
			{
				option = 14;
				choosemenu(option);
				cout << "\n\n\t\t\t\t\tThe staff with " << weight << "kg could not be found.";	
			}
			cout << "\n\t\t\t\t\t";
			system("pause");
		}
			
			else if (choice ==6 )			// Searching by height of staff
			{
				s=0;
				cout << "\n\t\t\t\t\tPlease enter the height which you want to search :";
			heightagain:
				cin >> height;
				if(cin.fail() || height <= 0)		// Limit the user to key in a correct and valid height
				{
					cin.clear();
					cin.ignore(INT_MAX,'\n');
					cout << "\n\t\t\t\tERROR!!!\n\t\t\tInvalid number : \n\t\t\t\t\tPlease enter the height again";
					goto heightagain;
				}
			system("cls");
			option=2;
			for (int i = 0; i < numfile; i++)
				if ( height == read[i].getHeight())
				{
					choosemenu(option);
					s++; option+=20;
					cout << "  " << s << ") ";
					read[i].printout();
				}
					
			if(s==0)				// Tell the user that the height searched could not be found
			{
				option = 14;
				choosemenu(option);
				cout << "\n\n\t\t\t\t\tThe staff with " << height << "cm could not be found.";	
			}
			cout << "\n\t\t\t\t\t";
			system("pause");
		}
	}while(choice != 0);
}		// End searchinfo function

void modifyinfo(calculation read[], int & numfile)		// Function to modify the staff information
{
	int s,k,u=0;
	int ar[500], br[500];
	string name,gender;
	unsigned long long int staffid;
	unsigned int option, choice;
	float weight, height;
modifymenu:
	system("cls");
	s=0;
	choice = 14;
	choosemenu(choice);
	option =6;
	choosemenu(option);			// Modifying menu to let user to choose the method they want to search and update a staff information

typeagain:
		cout << "Your choice : ";cin >> choice;
		if(choice >2 || cin.fail())		// 	Limit the user to input a correct and valid choice
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << "\n\t\t\t\tERROR!!!\n\t\t\t\t\tPlease enter a valid number : " ;
			goto typeagain;
		}
		if (choice == 1)				// Searched by name then modify it	
		{
		modifyname: 
				
			cout << "\n\t\t\t\t\tPlease enter the staff's name : ";		// Let user to input the name that user wants to search and modify
			getline(cin, name);
			getline(cin, name);
			transform(name.begin(), name.end(), name.begin(), ::toupper);
			s = 0;
			int i = 0;
			option=2;
			for (; i < numfile; i++)
			{
				if (name == read[i].getname())	 	// Program will search  and display all the name the match with the name searched by user
				{
					choosemenu(option);
					k=i;
					s++; option+=20; ar[i]=1;
					cout << " " << ++i << ". ";
					i--;
					read[i].printout();
				}
			}
			if(s>0)
			{
				if(s > 1)
				{
							// if more then one results found, program aks the user to choose to update a staff information and  can input '-1' to cancel modifying
					cout << "\n\n\n\t\tIf the name you search do not show in this list it means the name consists of some tabs or spaces at the end or you spell it wrongly.";
				numname:
					cout << "\n\t\t\t\t\tPlease enter the number that you want to modify (cancel by entering '-1') \n\n\t\t\t\t\t\tYour choice : ";
					cout << "Your choice : ";cin >> i;
					i--;
					if ( i==-2 )
						goto modifymenu;
					if(cin.fail() || i <0 || i>= 500 || read[i].getname() == " " || ar[i] != 1)		// Limit the user to input a correct and valid choice
					{
						cin.clear();
						cin.ignore(INT_MAX,'\n');
						cout << "\n\t\t\t\tERROR!!!\n\t\t\tInvalid number : ";
						goto numname;
					}
				}
				else if (s==1){i=k;}
				cout << "\n\n\n\t\t\t\t\tPlease enter the new information of the staff " << name << " again .\n\t\t\t\t\t";
				system ("pause");
			modifyingmenu1:
				system("cls");
				option =14;
				choosemenu(option);
				option =10;
				choosemenu(option);		// Display Modifying menu to allow user to choose the information that user wants to update
			valid4:
				cout << "Your choice : ";cin >> choice;
 				if ( choice > 7 ||choice ==0  || cin.fail())		// Limit the user to input a correct and valid choice
				{
					cin.clear();
					cin.ignore(INT_MAX,'\n');
					cout << "\n\t\t\t\tERROR!!!\n\t\t\t\t\tPlease enter a valid number : ";
					goto valid4;
				}
				if (choice == 1 )		// Modify the whole information
				{	
					u++;
					addinfo(name, staffid, gender, weight, height, choice);
					if (height ==0)
						goto modifyingmenu1;
					read[i].setdata(name, staffid, gender, weight, height);
					read[i].change();	
					read[i].BMI();
					read[i].BMR();
					read[i].RMR();
					cout <<"\n\t\t\t\t\t\t\tInformation modified.";
					system("pause");
					goto modifyingmenu1;
				}
					
				else if( choice ==2)	// Modify the name of staff
				{
					u++;
					addinfo(name, staffid, gender, weight, height, choice);
					read[i].setname(name);
					cout <<"\n\t\t\t\t\t\t\tInformation modified.";
					system("pause");
					goto modifyingmenu1;
				}
				else if(choice == 3)	// Modify the staff ID
				{
					u++;
					addinfo(name, staffid, gender, weight, height, choice);
					read[i].setstaffid(staffid);
					read[i].change();	
					read[i].BMI();
					read[i].BMR();
					read[i].RMR();
					cout <<"\n\t\t\t\t\t\t\tInformation modified.";
					system("pause");
					goto modifyingmenu1;
				}
				else if (choice == 4)	// Modify the gender of staff
				{
					u++;
					addinfo(name, staffid, gender, weight, height, choice);
					read[i].setgender(gender);	
					read[i].BMI();
					read[i].BMR();
					read[i].RMR();
					cout <<"\n\t\t\t\t\t\t\tInformation modified.";
					system("pause");
					goto modifyingmenu1;
				}
				else if( choice ==5)	// Modify the weight of staff
				{
					u++;
					addinfo(name, staffid, gender, weight, height, choice);
					read[i].setWeight(weight);
					read[i].change();	
					read[i].BMI();
					read[i].BMR();
					read[i].RMR();
					cout <<"\n\t\t\t\t\t\t\tInformation modified.";
					system("pause");
					goto modifyingmenu1;
				}
				else if( choice ==6 )	// Modify the height of staff
				{
					u++;
					addinfo(name, staffid, gender, weight, height, choice);
					read[i].setHeight(height);	
					read[i].BMI();
					read[i].BMR();
					read[i].RMR();
					cout <<"\n\t\t\t\t\t\t\tInformation modified.";
					system("pause");
					goto modifyingmenu1;
				}
				else if(choice == 7 && u ==0 )  // Go back to the previous menu without modifying any information
				{
					goto modifymenu;
				}
				else if ( choice == 7 && u > 0)		// Display the staff information modified and go back to previous menu
				{
					system("cls");
					choice = 14;
					choosemenu(choice);
					cout << "\n\t\t\t\t\t\t\t\tStaff information modified." << endl;
					read[i].showinfo();
					cout << "\n\t\t\t\t\t\t  ____________________________________________________" << endl << endl << "\n\t\t\t\t\t\t\t";
					system("pause"); goto modifymenu;
				}
			}
			else
			{
				cout << "\n\n\n\t\t\t\t\tThe staff " << name <<" could not be found.(The name recorded might have spaces or tabs)\n\t\t\t\t\t";
				system("pause");
				goto modifymenu;
			}	
		}
		
		else if (choice ==2)		// Searched by staff ID then modify it
		{
			
		modifyid:  
		system("cls");
			choice = 14;
			choosemenu(choice);
			cout << "\n\t\t\t\tPlease enter the staff ID (IC no. consists of 12 numbers) : ";		// let user input the staff ID that user wants to search and modify
			cout << "\n\t\t\t\t(If you do not know the staff ID you can search it first.)\n\t\t\t\t\t";
		modifyidagain:
			
			cout << "Your choice : " ;cin >> staffid;			// Limit the user to input a correct and vvalid staff ID
			if(cin.fail() || staffid > 991231000000 || staffid < 101000000 )
			{
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout << "\n\t\t\t\tERROR!!!\n\t\t\tInvalid staff ID : \n\t\t\t\t\tPlease enter staffid again (IC no. consists of 12 numbers) : \n\t\t\t\t\t";
				goto modifyidagain;
			}
			int i = 0;
			option=2;
			for (; i < numfile; i++)		// Program will search and display  the staff ID that match with the staff ID searched by user
			{
				if (staffid == read[i].getstaffid())
				{	
					choosemenu(option);
					k=i;
					s++; option+=20; br[i]=1;
					cout << " " << ++i << ". ";
					i--;
					read[i].printout();
				}
			}
			if(s>0)
			{
				if(s > 1)
				{					// If there are more than one results, the program will displayy all out and let user to choose the staff information that user wants to modify
					cout << "\n\n\t\t\t\t\tPlease enter the number that you want to modify (cancel by entering '-1') \n\t\t\t\t\t\tYour choice : " ;
				numid:
					cout << "Your choice : ";cin >> i;
					i--;
					if ( i==-2 )
						goto modifymenu;		// Limit user to input a orrect and valid choice
					if(cin.fail() || i <0 || i >= 500 || br[i] != 1 || read[i].getstaffid() == 0  )
					{
						cin.clear();
						cin.ignore(INT_MAX,'\n');
						cout << "\n\t\t\t\tERROR!!!\n\t\t\t\t\tPlease enter a valid number again : ";
						goto numid;
					}
				}
				else if (s==1){i=k;}
					cout << "\n\t\t\t\tPlease enter the new information of the staff ID" << staffid << " again .\n\t\t\t\t\t";
					system("pause");
			modifyingmenu2:
				system("cls");
				option =14;
				choosemenu(option);
				option =10;
				choosemenu(option);		// Display Modifying menu to allow user to choose the specific information that wants to modify
				do{
				cout << "Your choice : ";cin >> choice;			// Limit the user to input a correct and valid choice
				if ( choice > 7 || choice ==0 || cin.fail())
				{
					cin.clear();
					cin.ignore(INT_MAX,'\n');
					cout << "\n\t\t\t\tERROR!!!\n\t\t\t\t\tPlease enter a valid number : ";
				}
				}while( choice > 7 || choice ==0  || cin.fail());

				if (choice == 1 )		// Modify the whole information
				{	
					u++;
					addinfo(name, staffid, gender, weight, height, choice);
					if (height ==0)
						goto modifyingmenu2;
					read[i].setdata(name, staffid, gender, weight, height);
					read[i].change();	
					read[i].BMI();
					read[i].BMR();
					read[i].RMR();
					cout <<"\n\t\t\t\t\t\t\tInformation modified.";
					system("pause");
					goto modifyingmenu2;
				}
					
				else if( choice ==2)		// Modify the name of staff
				{
					u++;
					addinfo(name, staffid, gender, weight, height, choice);
					read[i].setname(name);
					cout <<"\n\t\t\t\t\t\t\tInformation modified.";
					system("pause");
					goto modifyingmenu2;
				}
				else if(choice == 3)		// Modify the staff ID
				{
					u++;
					addinfo(name, staffid, gender, weight, height, choice);
					read[i].setstaffid(staffid);
					read[i].change();	
					read[i].BMI();
					read[i].BMR();
					read[i].RMR();
					cout <<"\n\t\t\t\t\t\t\tInformation modified.";
					system("pause");
					goto modifyingmenu2;
				}
				else if (choice == 4)		// Modify the gender of staff
				{
					u++;
					addinfo(name, staffid, gender, weight, height, choice);
					read[i].setgender(gender);	
					read[i].BMI();
					read[i].BMR();
					read[i].RMR();
					cout <<"\n\t\t\t\t\t\t\tInformation modified.";
					system("pause");
					goto modifyingmenu2;
				}
				else if( choice ==5)		// Modify the weight of staff
				{
					u++;
					addinfo(name, staffid, gender, weight, height, choice);
					read[i].setWeight(weight);	
					read[i].BMI();
					read[i].BMR();
					read[i].RMR();
					cout <<"\n\t\t\t\t\t\t\tInformation modified.";
					system("pause");
					goto modifyingmenu2;
				}
				else if( choice ==6 )		// Modify the height of staff
				{
					u++;
					addinfo(name, staffid, gender, weight,  height, choice);
					read[i].setHeight(height);	
					read[i].BMI();
					read[i].BMR();
					read[i].RMR();
					cout <<"\n\t\t\t\t\t\t\tInformation modified.";
					system("pause");
					goto modifyingmenu2;
				}
				else if(choice == 7 && u == 0)		// Go back to previous menu without any modifying
				{
					goto modifymenu;
				}
				else if( choice ==7 && u > 0)		// Display the modified staff information and go back to previous menu
				{
					system("cls");
					choice = 14;
					choosemenu(choice);
					cout << "\n\t\t\t\t\t\t\t\tStaff information modified." << endl;
					read[i].showinfo();
					cout << "\n\t\t\t\t\t\t  ____________________________________________________" << endl << endl << "\n\t\t\t\t\t\t\t";
					system("pause"); goto modifymenu;
				}
			}
			else
			{				// Tell the user that the staff ID searched could not be found
				cout << "\n\t\t\t\t\tThe staff ID "<< staffid <<" could not be found.\n\t\t\t\t\t";
				system("pause");
				goto modifymenu;
			}
		}	
}		// End modifyinfo function

void analysisinfo(calculation read[], int&numfile, fstream &outdata)			//  Function to analysis staff information
{
	unsigned int option, choice;
	int s;
	unsigned long long int staffid;
	int avgage3, avgage1, avgage2;
	int totm1, totf1,tot, totage1, totage2, totage3;
	float totw1, toth1, totw2, toth2, totw3, toth3;
	float avgw1, avgh1, avgw2, avgh2, avgw3, avgh3;
	int totunder1, totnormal1, totover1, totobes1, totunder2,  totnormal2, totover2, totobes2, totunder3,  totnormal3, totover3, totobes3;
analysismenu:
		
		system("cls");		
		choice = 14;
		choosemenu(choice);		// Definition of BMI, BMR and RMR
		cout << "\n\n\t\t\t   ***BMI is defined as the body mass divided by the square of the body height.The BMI is a ";
		cout << "\n\t\t\t   convenient rule of thumb used to broadly categorize a person as underweight, normal weight,";
		cout << "\n\t\t\t   overweight, or obese based on tissue mass (muscle, fat, and bone) and height.\n";
		cout << "\n\t\t\t   ***BMR is the number of calories a body needs to accomplish its most basic (basal) ";
		cout << "\n\t\t\t   life-sustaining functions. Theoretically, body weight can be reduced if we consistently  ";
		cout << "\n\t\t\t   consume lesser daily amount of energy needed by the body.\n";
		cout << "\n\t\t\t   ***RMR is the rate at which a body burns energy when it is at complete rest. Resting ";
		cout << "\n\t\t\t   metabolic ratecan be calculated to see how many calories the body needs to perform basic\n\t\t\t   functions like breathing and blood circulation.\n\n";
		option = 7;
		choosemenu(option);		// display Analysis Menu to allow user to choose  whelther anlayze a staff information or an overall information among all the staff
	valid5:
		cout << "Your choice : ";cin >> choice;
		if (cin.fail()|| choice > 2)
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << "\n\t\t\t\tERROR!!!\n\t\t\t\t\tPlease enter a valid number : ";
			goto valid5;
		}
		if(choice == 1)				//Analysis only one staff information
		{
			system("cls");
			choice = 14;
		choosemenu(choice);
		analysis1:	
			cout << "\n\n\n\t\t\t  Enter the staff ID which you want to analyse (IC no. consists of 12 numbers) : \n\t\t\t   ";
		staffidagain:
			cin >> staffid;
			if(cin.fail() || staffid > 991231000000 || staffid < 101000000)
			{
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout << "\n\t\t\t\tERROR!!!\n\t\t\tInvalid staff ID : \n\t\t\t\t\tPlease enter the staff ID again (IC no. consists of 12 numbers) : \n\t\t\t\t\t";
				goto staffidagain;
			}
			s =0 ;
			for (int i = 0; i < numfile; i++)		// Display and analyze the information of the staff
			{
				if (staffid == read[i].getstaffid())
				{
					s++;
					cout << endl;
					read[i].showinfo();
					read[i].BMI();
					read[i].BMR();
					read[i].RMR();
					cout << "\n\t\t\t\t\t\t ||  BMI            :" << "\t" << left << std::setw(29)<< setprecision(2) << read[i].getbmi() << "||" << endl;
					cout << "\n\t\t\t\t\t\t ||  BMR            :" << "\t" << left << std::setw(29)<< setprecision(2) << read[i].getbmr() << "||"  << endl;
					cout << "\n\t\t\t\t\t\t ||  RMR            :" << "\t" << left << std::setw(29)<< setprecision(2) << read[i].getrmr() << "||" << endl;
					category (read[i]);
					cout << endl;
					cout << "\t\t\t\t\t\t  ____________________________________________________" << endl << endl;
			 	
				}
				
			}
			if(s==0)
				cout << "\n\n\n\t\t\t\t\tThe staff ID could not be found." << "\n\t\t\t\t\t";
			system("pause");
			goto analysismenu;
		}
		else if(choice == 2)		// Analysis the average of age, weight, height, number of male anf female, number of staff and
		{							// number of underweight, normal weight, overweight and obese among all the staff by comparing gender according to age group
			system("cls");
		analysis2:
			
			totm1 = totf1 = tot = totw1 = totw2 = totw3 = toth1 = toth2 = toth3 = 0;
			totage1 = totage2 = totage3 = 0;
			totunder1 =  totnormal1 = totover1 = totobes1 = totunder2 =  totnormal2 = totover2 = totobes2 = totunder3 =  totnormal3 = totover3 = totobes3 = 0;
			choice = 14;
			choosemenu(choice);
			cout << "\n\t\t      ===============================================================================================================";
			cout << "\n\t\t      ||           AGE GROUP             ||        MALE        ||       FEMALE        ||          OVERALL          ||";
			cout << "\n\t\t      ===============================================================================================================";
			
			for(int y=0; y <numfile; y++)
			{
				if (read[y].getage() < 21)			// analyze the information of staff of age group of below 21 years old 
				{									//by comparing gender and dislplay the overall
					if (read[y].getgender() == "Male" || read[y].getgender() == "male" || read[y].getgender() == "MALE" || read[y].getgender() == "m" || read[y].getgender() == "M")
						bmicat(read, y,totm1,totage1, totw1, toth1, totunder1, totnormal1, totover1, totobes1);
					
					else if (read[y].getgender() == "Female" || read[y].getgender() == "female" || read[y].getgender() == "FEMALE" || read[y].getgender() == "f" || read[y].getgender() == "F")
						bmicat(read, y,totf1,totage2, totw2, toth2, totunder2, totnormal2, totover2, totobes2);
						
					bmicat(read, y,tot,totage3, totw3, toth3, totunder3, totnormal3, totover3, totobes3);
				}
			}
			calavg(totm1, totage1, totw1, toth1, avgage1, avgw1, avgh1);		
			calavg(totf1, totage2, totw2, toth2, avgage2, avgw2, avgh2 );
			calavg(tot, totage3, totw3, toth3, avgage3, avgw3, avgh3 );
			
			cout << "\n\t\t\t  " << left << std::setw(33) << " Below 21 years old";
			print(totm1, totf1, tot, avgage1, avgage2, avgage3, avgw1, avgw2, avgw3, avgh1, avgh2, avgh3,totunder1, totunder2, totunder3, totnormal1, totnormal2, totnormal3, totover1, totover2, totover3, totobes1, totobes2, totobes3);
			totm1 = totf1 = tot = totw1 = totw2 = totw3 = toth1 = toth2 = toth3 = 0;
			totage1 = totage2 = totage3 = 0;
			totunder1 =  totnormal1 = totover1 = totobes1 = totunder2 =  totnormal2 = totover2 = totobes2 = totunder3 =  totnormal3 = totover3 = totobes3 = 0;
			for(int y=0; y <numfile; y++)
			{
				if (read[y].getage() >=21 && read[y].getage() < 30)		// analyze the information of staff of age group of between 21 to 29 years old
				{														//by comparing gender and dislplay the overall
					if (read[y].getgender() == "Male" || read[y].getgender() == "male" || read[y].getgender() == "MALE" || read[y].getgender() == "m" || read[y].getgender() == "M")
						bmicat(read, y,totm1,totage1, totw1, toth1, totunder1, totnormal1, totover1, totobes1);
					
					else if (read[y].getgender() == "Female" || read[y].getgender() == "female" || read[y].getgender() == "FEMALE" || read[y].getgender() == "f" || read[y].getgender() == "F")
						bmicat(read, y,totf1,totage2, totw2, toth2, totunder2, totnormal2, totover2, totobes2);
						
					bmicat(read, y,tot,totage3, totw3, toth3, totunder3, totnormal3, totover3, totobes3);
				}
			}
			calavg(totm1, totage1, totw1, toth1, avgage1, avgw1, avgh1);
			calavg(totf1, totage2, totw2, toth2, avgage2, avgw2, avgh2 );
			calavg(tot, totage3, totw3, toth3, avgage3, avgw3, avgh3 );
			cout << "\n\t\t\t_____________________________________________________________________________________________________________";
			cout << "\n\t\t\t  " << left << std::setw(30) << "21 - 29 years old";
			print(totm1, totf1, tot, avgage1, avgage2, avgage3, avgw1, avgw2, avgw3, avgh1, avgh2, avgh3,totunder1, totunder2, totunder3, totnormal1, totnormal2, totnormal3, totover1, totover2, totover3, totobes1, totobes2, totobes3);
			totm1 = totf1 = tot = totw1 = totw2 = totw3 = toth1 = toth2 = toth3 = 0;
			totage1 = totage2 = totage3 = 0;
			totunder1 =  totnormal1 = totover1 = totobes1 = totunder2 =  totnormal2 = totover2 = totobes2 = totunder3 =  totnormal3 = totover3 = totobes3 = 0;
			for(int y=0; y <numfile; y++)
			{
				if (read[y].getage() >=30 && read[y].getage() < 50)		// analyze the information of staff of age group of between 30 to 49 years old
				{														//by comparing gender and dislplay the overall
					if (read[y].getgender() == "Male" || read[y].getgender() == "male" || read[y].getgender() == "MALE" || read[y].getgender() == "m" || read[y].getgender() == "M")
						bmicat(read, y,totm1,totage1, totw1, toth1, totunder1, totnormal1, totover1, totobes1);
					
					else if (read[y].getgender() == "Female" || read[y].getgender() == "female" || read[y].getgender() == "FEMALE" || read[y].getgender() == "f" || read[y].getgender() == "F")
						bmicat(read, y,totf1,totage2, totw2, toth2, totunder2, totnormal2, totover2, totobes2);
						
					bmicat(read, y,tot,totage3, totw3, toth3, totunder3, totnormal3, totover3, totobes3);
				}
			}
			
			
			cout << "\n\t\t\t_____________________________________________________________________________________________________________";
			cout << "\n\t\t\t  " << left << std::setw(30) << "30 - 49 years old";
			print(totm1, totf1, tot, avgage1, avgage2, avgage3, avgw1, avgw2, avgw3, avgh1, avgh2, avgh3,totunder1, totunder2, totunder3, totnormal1, totnormal2, totnormal3, totover1, totover2, totover3, totobes1, totobes2, totobes3);
			totm1 = totf1 = tot = totw1 = totw2 = totw3 = toth1 = toth2 = toth3 = 0;
			totage1 = totage2 = totage3 = 0;
			totunder1 =  totnormal1 = totover1 = totobes1 = totunder2 =  totnormal2 = totover2 = totobes2 = totunder3 =  totnormal3 = totover3 = totobes3 = 0;
			for(int y=0; y <numfile; y++)
			{
				if (read[y].getage() >=50 && read[y].getage() < 65)		// analyze the information of staff of age group of between 50 to 64 years old
				{														//by comparing gender and dislplay the overall
					if (read[y].getgender() == "Male" || read[y].getgender() == "male" || read[y].getgender() == "MALE" || read[y].getgender() == "m" || read[y].getgender() == "M")
						bmicat(read, y,totm1,totage1, totw1, toth1, totunder1, totnormal1, totover1, totobes1);
					
					else if (read[y].getgender() == "Female" || read[y].getgender() == "female" || read[y].getgender() == "FEMALE" || read[y].getgender() == "f" || read[y].getgender() == "F")
						bmicat(read, y,totf1,totage2, totw2, toth2, totunder2, totnormal2, totover2, totobes2);
						
					bmicat(read, y,tot,totage3, totw3, toth3, totunder3, totnormal3, totover3, totobes3);
				}
			}
			
			calavg(totm1, totage1, totw1, toth1, avgage1, avgw1, avgh1);
			calavg(totf1, totage2, totw2, toth2, avgage2, avgw2, avgh2 );
			calavg(tot, totage3, totw3, toth3, avgage3, avgw3, avgh3 );
			
			cout << "\n\t\t\t_____________________________________________________________________________________________________________";
			cout << "\n\t\t\t  " << left << std::setw(30) << "50 - 64 years old" ;
			print(totm1, totf1, tot, avgage1, avgage2, avgage3, avgw1, avgw2, avgw3, avgh1, avgh2, avgh3,totunder1, totunder2, totunder3, totnormal1, totnormal2, totnormal3, totover1, totover2, totover3, totobes1, totobes2, totobes3);
			totm1 = totf1 = tot = totw1 = totw2 = totw3 = toth1 = toth2 = toth3 = 0;
			totage1 = totage2 = totage3 = 0;
			totunder1 =  totnormal1 = totover1 = totobes1 = totunder2 =  totnormal2 = totover2 = totobes2 = totunder3 =  totnormal3 = totover3 = totobes3 = 0;
			for(int y=0; y <numfile; y++)
			{
				if (read[y].getage() >=65)			// analyze the information of staff of age group of 65 years old and above
				{									//by comparing gender and dislplay the overall
					if (read[y].getgender() == "Male" || read[y].getgender() == "male" || read[y].getgender() == "MALE" || read[y].getgender() == "m" || read[y].getgender() == "M")
						bmicat(read, y,totm1,totage1, totw1, toth1, totunder1, totnormal1, totover1, totobes1);
					
					else if (read[y].getgender() == "Female" || read[y].getgender() == "female" || read[y].getgender() == "FEMALE" || read[y].getgender() == "f" || read[y].getgender() == "F")
						bmicat(read, y,totf1,totage2, totw2, toth2, totunder2, totnormal2, totover2, totobes2);
						
					bmicat(read, y,tot,totage3, totw3, toth3, totunder3, totnormal3, totover3, totobes3);
				}
			}
			
			calavg(totm1, totage1, totw1, toth1, avgage1, avgw1, avgh1);
			calavg(totf1, totage2, totw2, toth2, avgage2, avgw2, avgh2 );
			calavg(tot, totage3, totw3, toth3, avgage3, avgw3, avgh3 );
			
			cout << "\n\t\t\t_____________________________________________________________________________________________________________";
			cout << "\n\t\t\t  " << left << std::setw(30) << "65 years old and above";
			print(totm1, totf1, tot, avgage1, avgage2, avgage3, avgw1, avgw2, avgw3, avgh1, avgh2, avgh3,totunder1, totunder2, totunder3, totnormal1, totnormal2, totnormal3, totover1, totover2, totover3, totobes1, totobes2, totobes3);
			
			totm1 = totf1 = tot = totw1 = totw2 = totw3 = toth1 = toth2 = toth3 = 0;
			totage1 = totage2 = totage3 = 0;
			totunder1 =  totnormal1 = totover1 = totobes1 = totunder2 =  totnormal2 = totover2 = totobes2 = totunder3 =  totnormal3 = totover3 = totobes3 = 0;
			for(int y=0; y <numfile; y++)		// analyze the information of staff among all the staff
			{
				if (read[y].getgender() == "Male" || read[y].getgender() == "male" || read[y].getgender() == "MALE" || read[y].getgender() == "m" || read[y].getgender() == "M")
						bmicat(read, y,totm1,totage1, totw1, toth1, totunder1, totnormal1, totover1, totobes1);
					
					else if (read[y].getgender() == "Female" || read[y].getgender() == "female" || read[y].getgender() == "FEMALE" || read[y].getgender() == "f" || read[y].getgender() == "F")
						bmicat(read, y,totf1,totage2, totw2, toth2, totunder2, totnormal2, totover2, totobes2);
						
					bmicat(read, y,tot,totage3, totw3, toth3, totunder3, totnormal3, totover3, totobes3);
			}
		
		calavg(totm1, totage1, totw1, toth1, avgage1, avgw1, avgh1);
		calavg(totf1, totage2, totw2, toth2, avgage2, avgw2, avgh2);
		calavg(tot, totage3, totw3, toth3, avgage3, avgw3, avgh3 );
		cout << "\n\t\t\t_____________________________________________________________________________________________________________";
		cout << "\n\t\t\t  " << left << std::setw(30) << "Overall : ";
		cout << "\n\t\t\t================================== " <<endl;
		
					// Call the function to display the analysis data into an output file
		oprint(outdata, totm1,totf1, tot,avgage1, avgage2, avgage3, avgw1, avgw2,avgw3,avgh1, avgh2, avgh3, totunder1, totunder2, totunder3, totnormal1, totnormal2, totnormal3, totover1, totover2, totover3, totobes1, totobes2, totobes3);
		print(totm1, totf1, tot, avgage1, avgage2, avgage3, avgw1, avgw2, avgw3, avgh1, avgh2, avgh3,totunder1, totunder2, totunder3, totnormal1, totnormal2, totnormal3, totover1, totover2, totover3, totobes1, totobes2, totobes3);
		cout << "\n\t\t\t_____________________________________________________________________________________________________________\n\t\t\t\t\t";
		system("pause");
		goto analysismenu;
		}
}		// End analysisinfo function

void deleteinfo(calculation read[], int &numfile, unsigned int &option)			// Function to delete the information of staff
{
	unsigned int choice,s;
	int arr[500];
	int i;
	unsigned long long int staffid;
deleteinfo:	
	system("cls");
		choice = 14; option =8;
		choosemenu(choice);	
		
		choosemenu(option);		// Deletion Menu for user to choose to delete a staff information or go back to main menu
	valid6:
		cout << "Your choice : "; cin >> choice;
		if( choice >1 ||cin.fail())		// Limit user to input a correct and valid choice
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << "\n\t\t\t\tERROR!!!\n\t\t\t\t\tPlease enter a valid number : " ;
			goto valid6;
		}

		if(choice == 1)
		{	
		system("cls");
		deletechoose:
			choice = 14;
			choosemenu(choice);		// Let user to key in the staff ID that wants to delete
			cout << "\n\n\n\n\n\t\t\t  Enter the staff ID which you want to delete the staff's information (IC no. consists of 12 numbres) ";
			cout << "\n\t\t\t      (If you do not know the staff ID you can search it first.)";
			cout << "\n\t\t\t  Staff ID : ";
			do{
			cin >> staffid;		// Limit user to inout a correct and valid staff ID
			if(cin.fail() || staffid > 991231000000 || staffid < 101000000)
			{
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout << "\n\t\t\t\tERROR!!!\n\t\t\tInvalid staff ID : \n\t\t\t\t\tPlease enter the staff ID again (IC no. consists of 12 numbres) : \n\t\t\t\t\t";
			}
			}while(cin.fail() || staffid > 991231000000 || staffid < 101000000);
			s=0;
			option=2;
			for (; i < numfile; i++)		// Program will searche and display all the staff ID that match with the staff ID searched by user
			{
				if (staffid == read[i].getstaffid())
				{	
					choosemenu(option);
					s++; option+=20;	arr[i]=1;
					cout << " " << ++i << ". ";
					i--;
					read[i].printout();
				}
			}
			if(s>0)
			{
				if(s > 1)	// Since there might be some error and overallap information, user can choose to delete which inforamtion
				{
					cout << "\n\t\t\t\t\tPlease enter the number that you want to delete. (Cancel by entering '-1'.) \n\t\t\t\t\t\tYour choice : ";
				numid:
					cout << "Your choice : "; cin >> i;
					i--;
					if(i==-2)	// Limit the user to input the correct and valid choice
							goto deleteinfo;
					if(cin.fail() || i > 500 || read[i].getstaffid() == 0 || arr[i] != 1  )
					{
						cin.clear();
						cin.ignore(INT_MAX,'\n');
						cout << "\n\t\t\t\tERROR!!!\n\t\t\t\t\tPlease enter  a valid number again : ";
						goto numid;
					}
				}
			cout << "\n\t\t\t\t\t";
			system("pause");
			}
			else if (s ==0)		// Tell the user that the staff ID searched could not be found
			{
				cout << "\n\n\t\t\tThe staff ID could not be found." << endl << "\n\t\t\t\t\t";
				system("pause");
				goto deleteinfo;
			}
			system("cls");
			choice = 14;
			choosemenu(choice);	
			unsigned int sure;
			cout << endl;		// Display the staff information that user searched to delete and let user to check the staff inforamtion 
			cout << "\n\t\t\t\t\t\t\tThis is the information of the staff." << endl << endl;
			read[i].showinfo();
			cout << "\t\t\t\t\t\t  ____________________________________________________" << endl << endl << endl << endl;
			cout << "\t\t\t\t\tDo you sure you want to delete the staff information?\n";
			cout << "\n\t\t\t\t\tIf you decide to delete," << endl;		// Get confirmation from user and make sure user want to delete the staff information
			cout << "\n\t\t\t\t\tSelect an option" << endl;
			cout << "\n\t\t\t\t\t 1 - delete." << endl;
			cout << "\n\t\t\t\t\t 0 - cancel." << endl;
			cout << "\t\t\t\t\t ";
	deletemenu:
			cout << "Your choice : "; cin >> sure;
			if(sure >1 || cin.fail())		// Limit user to input correcr and valid choice
			{
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout << "\n\t\t\t\tERROR!!!\n\t\t\t\t\tPlease enter a valid number again : ";
				goto deletemenu;
			}
			if (sure == 1)
			{						// Inform user that the staff information is deleted
				cout << "\n\t\t\t\tThe staff information is deleted.";
				for(int j=i; j<(500-1); j++)
				{
					read[j]=read[j+1];
				}
				numfile--;
				system("pause");
				goto deleteinfo;
			}
			else if (sure == 0)
				goto deleteinfo;
		}
}	// End deleteinfo function
										// Function to add new staff information and modify staff information
void addinfo(string &staff_name, unsigned long long int &staff_id, string &staff_gender, float &staff_weight, float &staff_height, unsigned int &choose)
{

endinput:
	staff_height=0;
	if(choose == 1)		// Add new staff information or modify the whole information of a staff
	{
		cout << "\n\t\t\t\t\t(Exit by entering '1' )";
		cout << "\n\t\t\t\t\tEnter the Staff Name : ";		// Let user to key int the name of staff
		getline(cin, staff_name);
		getline(cin, staff_name);
		transform(staff_name.begin(), staff_name.end(), staff_name.begin(), ::toupper);
		if ( staff_name == "1")		// Let user to cancel adding new staff information or stop modifying staff information by entering "A" to staff name
		{
			choose = 10;
			cout << "\n\t\t\t\t\tPlease press enter to go back.";
			cin.get();
			goto endinput;
		}								
		cout << "\n\t\t\t\t\tEnter the staff ID of the staff (IC No. consists of 12 numbers): \n\t\t\t\t\t";		// Let user to input the staff ID
	keyin1:
		cin >> staff_id;
		cin.ignore();
		if ( cin.fail() || staff_id > 991231000000 || staff_id < 101000000 && staff_id != 1)		// Limit the user to input a correct and valid staff ID
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << "\n\t\t\t\tERROR!!!\n\t\t\tInvalid staff ID : \n\t\t\t\t\tPlease enter the staff ID again (IC No. consists of 12 numbers): \n\t\t\t\t\t";
			goto keyin1;
		}
		if(staff_id == 1)	// Let user to cancel adding new staff information or stop modifying staff information by entering '1' to staff ID
		{
			choose = 10;
			cout << "\n\t\t\t\t\tPlease press enter to go back.";
			cin.get();
			goto endinput;
		} 
			cout << "\n\t\t\t\t\tEnter the gender of staff ('m' for male and 'f' for female) : ";		// Let user to input gender of staff
		keyin2:
			cin >> staff_gender;
			if ( staff_gender == "1")		// Let user to cancel adding new staff information or stop modifying staff information by entering "A" to staff name
			{
				choose = 10;
				cout << "\n\t\t\t\t\tPlease press enter to go back.";
				cin.get();
				cin.get();
				goto endinput;
			}
			transform(staff_gender.begin(), staff_gender.end(), staff_gender.begin(), ::toupper);		// Limit the user to input correct and valid gender
			if(staff_gender !="M" && staff_gender != "F")
			{
				cout << "\n\t\t\t\tERROR!!!\n\t\t\t\t\tPlease enter a valid gender again : ";
				goto keyin2;
			}
			if(staff_gender == "M")
				staff_gender ="MALE";
			else if (staff_gender=="F")
				staff_gender = "FEMALE";
			cout << "\n\t\t\t\t\tEnter the weight of staff (in kg) : ";			// Let user to input weight of staff
		keyin3:
			cin >> staff_weight;
			if ( cin.fail() || staff_weight < 1 )		// Limit the user to input the correct and valid weight
			{
				cout << "\n\t\t\t\tERROR!!!\n\t\t\tInvalid number : \n\t\t\t\t\tPlease enter the weight again : ";
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				goto keyin3;
			}
			if(staff_weight == 1)		// Let user to cancel adding new staff information or stop modifying staff information by entering "1" to weight of staff
			{
				choose = 10;
				cout << "\n\t\t\t\t\tPlease press enter to go bac.";
				cin.get();
				cin.get();
				goto endinput;
			}
			cout << "\n\t\t\t\t\tEnter the height of staff (in cm) : ";		// Let the user to input the height of staff
		keyin4:
			cin >> staff_height;
			if ( cin.fail() || staff_height < 1 )		// Limit the user to input a correct and valid height
			{
				cout << "\n\t\t\t\tERROR!!!\n\t\t\tInvalid number : \n\t\t\t\t\tPlease enter the height again : ";
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				goto keyin4;
			}
			if(staff_height == 1)	// Let user to cancel adding new staff information or stop modifying staff information by entering "1" to height of staff
			{
				choose = 10;
				cout << "\n\t\t\t\t\tPlease press enter to go back.";
				cin.get();
				cin.get();
				goto endinput;
			}
				
	}
	else if (choose == 2)
	{
		cout << "\n\t\t\t\t\tEnter the new Name : ";		// Let user to input name of staff
		getline(cin, staff_name);
		getline(cin, staff_name);
		transform(staff_name.begin(), staff_name.end(), staff_name.begin(), ::toupper);
	}
	else if (choose == 3)
	{
		cout << "\n\t\t\t\t\tEnter the new staff ID of the staff (IC No. consists of 12 numbers): \n\t\t\t\t\t";		// Let the user to input the staff ID
	idagain:
		cin >> staff_id;
		cin.ignore();
		if ( cin.fail() ||staff_id > 991231000000 || staff_id < 101000000)		// Limit the user to input a correct and valid staff ID
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << "\n\t\t\t\tERROR!!!\n\t\t\tInvalid staff ID : \n\t\t\t\t\tPlease enter the staff ID again (IC No. consists of 12 numbers): \n\t\t\t\t\t";
			goto idagain;
		}
	} 
	else if ( choose == 4)
	{
		cout << "\n\t\t\t\t\tEnter the correct gender of staff ('m' for male and 'f' for female) : ";		// Let user to input the gender of staff
	genderagain:
		cin >> staff_gender;
		transform(staff_gender.begin(), staff_gender.end(), staff_gender.begin(), ::toupper);
		if(staff_gender !="M" && staff_gender != "F")
		{
			cout << "\n\t\t\t\tERROR!!!\n\t\t\t\t\tPlease enter a valid gender again : ";		// Limit the user to input a correct and valid gender
			goto genderagain;
		}	
		if(staff_gender == "M")
			staff_gender ="MALE";
		else if (staff_gender=="F")
			staff_gender = "FEMALE";
	} 
	else if ( choose == 5)
	{
		cout << "\n\t\t\t\t\tEnter the new weight of staff (in kg) : ";		// Let user to input weight of staff
	weightagain:
		cin >> staff_weight;
		if ( cin.fail() || staff_weight <=0 )		// Limit the user to input corect and valid weight of staff
			{
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout << "\n\t\t\t\tERROR!!!\n\t\t\tInvalid number : \n\t\t\t\t\tPlease enter the weight again : ";
				goto weightagain;
			} 
	}
	else if ( choose ==6 )
	{
		cout << "\n\t\t\t\t\tEnter the new height of staff (in cm) : ";		// Let user to input height of staff
	heightagain:
		cin >> staff_height;
		if ( cin.fail() || staff_height <=0 )		// Limit the user to input  correct and valid height of staff
			{
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout << "\n\t\t\t\tERROR!!!\n\t\t\tInvalid number : \n\t\t\t\t\tPlease enter the height again : ";
				goto heightagain;
			} 
	} 

}		// End addinfo function
											// Function to calculate the analysis data among all the staff
void bmicat(calculation read[], int & y, int &totm1, int &totage1, float &totw1, float &toth1, int &totunder1, int &totnormal1, int &totover1, int &totobes1)
{
		totm1++;
		totage1 += read[y].getage();
		totw1 += read[y].getWeight();
		toth1 += read[y].getHeight();
		if(read[y].getbmi() < 20 )
			totunder1++;
		else if( read[y].getbmi() >= 20 && read[y].getbmi() < 25)
				totnormal1++;
		else if( read[y].getbmi() >= 25 && read[y].getbmi() <30)
			totover1++;
		else if( read[y].getbmi() >= 30)
			totobes1++;
}	// End bmicat function

											// Function to display the analysis among all the staff
void print(int &totm1, int &totf1, int &tot, int &avgage1, int &avgage2, int &avgage3, float &avgw1, float &avgw2, float &avgw3, float &avgh1, float &avgh2, float &avgh3, int &totunder1, int &totunder2, int &totunder3, int &totnormal1, int &totnormal2, int &totnormal3, int &totover1, int &totover2, int &totover3, int &totobes1, int &totobes2, int &totobes3)
{
	
	cout << "\n\n\t\t\t  #########################################################################################################";
	cout << "\n\t\t\t  #" << left << std::setw(40) << "  Number of Staff          :    |      " << left << std::setw(9) <<totm1 << "    |         " << left << std::setw(9) << totf1 << "  ||             " << left << std::setw(14) << tot << "#";
	cout << "\n\t\t\t  #" << left << std::setw(40) << "  Average Age              :    |    " << left << std::setw(9) <<avgage1 << "    |         " << left << std::setw(9) << avgage2 << "  ||             " << left << std::setw(14) << avgage3 << "#";
	cout << "\n\t\t\t  #" << left << std::setw(38) << "  Average Weight           :    |    " << left << std::setw(9) << avgw1 << "      |       " << left << std::setw(9) << avgw2 << "    ||            " << left << std::setw(14) <<  avgw3 << " #";
	cout << "\n\t\t\t  #" << left << std::setw(38) << "  Average Height           :    |    " << left << std::setw(9) << avgh1 << "      |       " << left << std::setw(9) << avgh2 << "    ||            " << left << std::setw(14) << avgh3 << " #";
	cout << "\n\t\t\t  #" << left << std::setw(40) << "  Number of Underweight    :    |      " << left << std::setw(9) << totunder1 << "    |         " << left << std::setw(9) << totunder2 << "  ||             " << left << std::setw(14) << totunder3 << "#";
	cout << "\n\t\t\t  #" << left << std::setw(40) << "  Number of Normal Weight  :    |     " << left << std::setw(9) << totnormal1 << "    |         " << left << std::setw(9) << totnormal2 << "  ||             " << left << std::setw(14) << totnormal3 << "#";
	cout << "\n\t\t\t  #" << left << std::setw(40) << "  Number of Overweight     :    |      " << left << std::setw(9) << totover1 << "    |         " << left << std::setw(9) << totover2 << "  ||             " << left << std::setw(14) << totover3 << "#";
	cout << "\n\t\t\t  #" << left << std::setw(40) << "  Number of Obese          :    |      " << left << std::setw(9) << totobes1 << "    |         " << left << std::setw(9) << totobes2 << "  ||             " << left << std::setw(14) << totobes3 << "#";
	cout << "\n\t\t\t  #########################################################################################################";
} // End print function
											// Function to display the analysis among all the staff into an output text file
void oprint(fstream &outdata, int &totm1, int &totf1, int &tot, int &avgage1, int &avgage2, int &avgage3, float &avgw1, float &avgw2, float &avgw3, float &avgh1, float &avgh2, float &avgh3, int &totunder1, int &totunder2, int &totunder3, int &totnormal1, int &totnormal2, int &totnormal3, int &totover1, int &totover2, int &totover3, int &totobes1, int &totobes2, int &totobes3)											// Function to calculate the avarage age, average weight, average height, average BMI, Average BMR, average RMR among all the staff		
{
	outdata << "\n\n\n\t\t\t   ==================================================================================================";
	outdata << 	 "\n\t\t\t    || 		   	 	 	 Here is 'LET'S GET FIT'	  	     		  ||";
	outdata << "\n\t\t\t   ==================================================================================================";
	outdata << "\n\t\t      ===============================================================================================================";
	outdata << "\n\t\t      ||           AGE GROUP             ||        MALE        ||       FEMALE        ||          OVERALL          ||";
	outdata << "\n\t\t      ===============================================================================================================";
	outdata << "\n\n\t\t\t  #########################################################################################################";
	outdata << "\n\t\t\t  #" << left << std::setw(40) << "  Number of Staff          :    |      " << left << std::setw(9) <<totm1 << "    |         " << left << std::setw(9) << totf1 << "  ||             " << left << std::setw(14) << tot << "#";
	outdata << "\n\t\t\t  #" << left << std::setw(40) << "  Average Age              :    |    " << left << std::setw(9) <<avgage1 << "    |         " << left << std::setw(9) << avgage2 << "  ||             " << left << std::setw(14) << avgage3 << "#";
	outdata << "\n\t\t\t  #" << left << std::setw(38) << "  Average Weight           :    |    " << left << std::setw(9) << avgw1 << "      |       " << left << std::setw(9) << avgw2 << "    ||            " << left << std::setw(14) <<  avgw3 << " #";
	outdata << "\n\t\t\t  #" << left << std::setw(38) << "  Average Height           :    |    " << left << std::setw(9) << avgh1 << "      |       " << left << std::setw(9) << avgh2 << "    ||            " << left << std::setw(14) << avgh3 << " #";
	outdata << "\n\t\t\t  #" << left << std::setw(40) << "  Number of Underweight    :    |      " << left << std::setw(9) << totunder1 << "    |         " << left << std::setw(9) << totunder2 << "  ||             " << left << std::setw(14) << totunder3 << "#";
	outdata << "\n\t\t\t  #" << left << std::setw(40) << "  Number of Normal Weight  :    |     " << left << std::setw(9) << totnormal1 << "    |         " << left << std::setw(9) << totnormal2 << "  ||             " << left << std::setw(14) << totnormal3 << "#";
	outdata << "\n\t\t\t  #" << left << std::setw(40) << "  Number of Overweight     :    |      " << left << std::setw(9) << totover1 << "    |         " << left << std::setw(9) << totover2 << "  ||             " << left << std::setw(14) << totover3 << "#";
	outdata << "\n\t\t\t  #" << left << std::setw(40) << "  Number of Obese          :    |      " << left << std::setw(9) << totobes1 << "    |         " << left << std::setw(9) << totobes2 << "  ||             " << left << std::setw(14) << totobes3 << "#";
	outdata << "\n\t\t\t  #########################################################################################################";
} // End oprint function
void calavg(int &TOT, int &TOTAGE, float &TOTW, float &TOTH, int &AVGAGE, float &AVGW, float &AVGH )
{
	if (TOT == 0)
	{
		AVGAGE = AVGW =	AVGH  =0;
	}
	else
	{
		AVGAGE = (TOTAGE / TOT);
		AVGW = (TOTW / TOT);
		AVGH = (TOTH / TOT);
	}
	
}	// End calavg function
				
void choosemenu(unsigned int &option)		// Fucntion to print out the menu and the name of the program
{
	if ( option == 5)		// Display Searching Menu for user to choose a choice
	{
		cout << "\t\t\t\t\t\t\t     ---------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t\t     Searching Menu" << endl;
		cout << "\n\t\t\t\t\t\t\t     ---------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t    **           Search by :         **" << endl;         
		cout << "\n\t\t\t\t\t\t\t    **  1 - Name                     **" << endl;
		cout << "\n\t\t\t\t\t\t\t    **  2 - Staff Id                 **" << endl;
		cout << "\n\t\t\t\t\t\t\t    **  3 - Age                      **" << endl;
		cout << "\n\t\t\t\t\t\t\t    **  4 - Gender                   **" << endl;
		cout << "\n\t\t\t\t\t\t\t    **  5 - Weight                   **" << endl;
		cout << "\n\t\t\t\t\t\t\t    **  6 - Height                   **" << endl;
		cout << "\n\t\t\t\t\t\t\t    **  0 - Go back to main menu     **" << endl;
		cout << "\n\t\t\t\t\t\t\t    ***********************************" << endl;
		cout << "\t\t\t\t\t\t\t      ";
	}
	
	else if (option == 6)	// Display Searching Menu for Modifying for user to choose a choice
	{
		cout << "\t\t\t\t\t\t\t ----------------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t\tSearching Menu for Modifying" << endl;
		cout << "\n\t\t\t\t\t\t\t ----------------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t**           Select an option           **" << endl;
		cout << "\n\t\t\t\t\t\t\t**  1 - Search by name and update       **" << endl;
		cout << "\n\t\t\t\t\t\t\t**  2 - Search by staff ID and update   **" << endl;
		cout << "\n\t\t\t\t\t\t\t**  0 - Go back to main menu.           **" << endl;
		cout << "\n\t\t\t\t\t\t\t******************************************" << endl;
		cout << "\t\t\t\t\t\t\t      ";
	}
	
	else if(option == 7)		// Display Analysis Menu for user to choose a choice
	{
		cout << "\t\t\t\t\t\t\t     ---------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t\t     Analysis  Menu" << endl;
		cout << "\n\t\t\t\t\t\t\t     ---------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t    **       Select an option :      **" << endl;
		cout << "\n\t\t\t\t\t\t\t    **  1 - Analysis of a staff      **" << endl;
		cout << "\n\t\t\t\t\t\t\t    **  2 - Overall analysis         **" << endl;
		cout << "\n\t\t\t\t\t\t\t    **  0 - Go back to main menu     **" << endl;
		cout << "\n\t\t\t\t\t\t\t    ***********************************" << endl;
		cout << "\t\t\t\t\t\t\t      ";
	}
	else if(option == 8)		// Display Menu for Deletion for user to choose a choice
	{
		cout << "\t\t\t\t\t\t\t     ---------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t\t     Menu for Deletion" << endl;
		cout << "\t\t\t\t\t\t\t     ---------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t    **      Select an option :        **" << endl;
		cout << "\n\t\t\t\t\t\t\t    **  1- Delete a staff information **" << endl;
		cout << "\n\t\t\t\t\t\t\t    **  0- Go back to main menu       **" << endl;
		cout << "\n\t\t\t\t\t\t\t    ***********************************" << endl;
		cout << "\t\t\t\t\t\t\t       ";
	}
	
	else if(option == 10)		// Display Modifying Menu for user to choose a choice
	{
		cout << "\t\t\t\t\t\t\t   ---------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t\t     Modifying Menu" << endl;
		cout << "\t\t\t\t\t\t\t   ---------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t**       Select to modify :      **" << endl;
		cout << "\n\t\t\t\t\t\t\t**  1 - Whole information        **" << endl;
		cout << "\n\t\t\t\t\t\t\t**  2 - Name                     **" << endl;
		cout << "\n\t\t\t\t\t\t\t**  3 - Staff ID                 **" << endl;
		cout << "\n\t\t\t\t\t\t\t**  4 - Gender                   **" << endl;
		cout << "\n\t\t\t\t\t\t\t**  5 - Weight                   **" << endl;
		cout << "\n\t\t\t\t\t\t\t**  6 - Height                   **" << endl;
		cout << "\n\t\t\t\t\t\t\t**  7 - Go back                  **" << endl;
		cout << "\n\t\t\t\t\t\t\t***********************************" << endl;
		cout << "\t\t\t\t\t\t\t      ";
	}
	
	
	else if(option ==2 || option == 3 || option ==4)		// Display the name of the program and name of personal and fitness information list
	{
		system("cls");
		cout << "\n\n\n\t\t\t   ==================================================================================================";
		cout << 	 "\n\t\t\t    || 		   	 	 	 Here is 'LET'S GET FIT'	  	     		  ||";
		cout << 	"\n\t\t\t   ==================================================================================================" << endl;
		cout << "\n\t\t\t\t\t\t    =================================================";
		cout << "\n\t\t\t\t\t\t    ||  Personal and Fitness Information of Staff  ||";
		cout << "\n\t\t\t\t\t\t    =================================================" << endl;
		cout << "\t===================================================================================================================================================" << endl;
		cout << "\t" << left << std::setw(30) <<"||      Staff Name"  << std::setw(16) << "|   Staff ID " << std::setw(8) << "|  Age" << std ::setw(11) << "|  Gender" <<std::setw(20) << "|   Date Of Birth " << std::setw(15) << "|  Weight (kg)"<< std::setw(14) << "| Height (cm)" << std::setw(10) << "|   BMI " << std::setw(10) << "|   BMR " << std::setw(10)<< " |   RMR  " << std::setw(9) << " ||" << endl;
		cout << "\t===================================================================================================================================================" << endl;
	}
	
	else if(option == 13)		// Display the Main Menu fo user to choose a choice
	{
		cout << "\n\t\t\t\t\t    ================================================================";
		cout << "\n\t\t\t\t\t    || 		   		Main  Menu	  		  ||";
		cout << "\n\t\t\t\t\t    ================================================================" << endl;
		cout << "\n\t\t\t\t\t***                       Select an option :                         ***" << endl;
		cout << "\n\t\t\t\t\t* *  1 - Add a new staff information                                 * *" << endl;
		cout << "\n\t\t\t\t\t***  2 - Display all staff information by name in ascending order    ***" << endl;
		cout << "\n\t\t\t\t\t* *  3 - Display all staff information by staff ID in ascending order* *" << endl;
		cout << "\n\t\t\t\t\t* *  4 - Display all staff information by age in ascending order     * *" << endl;
		cout << "\n\t\t\t\t\t***  5 - Search staff information                                    ***" << endl;
		cout << "\n\t\t\t\t\t* *  6 - Modify a staff information                                  * *" << endl;
		cout << "\n\t\t\t\t\t* *  7 - Analysis of staff information                               * *" << endl;
		cout << "\n\t\t\t\t\t* *  8 - Delete a staff information                                  * *" << endl;
		cout << "\n\t\t\t\t\t***  0 - Exit                                                        ***" << endl;
		cout << "\n\t\t\t\t\t************************************************************************" << endl;
		cout << "\t\t\t\t\t      ";
	}
	else if(option == 14)		// Display the name of the program
	{
		cout << "\n\n\n\t\t\t   ==================================================================================================";
		cout << 	 "\n\t\t\t    || 		   	 	 	 Here is 'LET'S GET FIT'	  	     		  ||";
		cout << 	"\n\t\t\t   ==================================================================================================" << endl;
	}
}		// End choosemenu function

void outfile(calculation read[], int & numfile, fstream &outdata)		// Function to store all the latest staff information in a text file calles 'staffinfo'
{
	outdata << "\n\t\t\t\t\t\t    =================================================";
	outdata << "\n\t\t\t\t\t\t    ||  Personal and Fitness Information of Staff  ||";
	outdata << "\n\t\t\t\t\t\t    =================================================" << endl;
	outdata << "\t===================================================================================================================================================" << endl;
	outdata << "\t" << left << std::setw(30) <<"||      Staff Name"  << std::setw(16) << "|   Staff ID " << std::setw(8) << "|  Age" << std ::setw(11) << "|  Gender" <<std::setw(20) << "|   Date Of Birth " << std::setw(15) << "|  Weight (kg)"<< std::setw(14) << "| Height (cm)" << std::setw(10) << "|   BMI " << std::setw(10) << "|   BMR " << std::setw(10)<< " |   RMR  " << std::setw(9) << " ||" << endl;
	outdata << "\t===================================================================================================================================================" << endl;
	for (int y = 0; y < numfile; y++)
	{
		outdata << "\t|  " << left << setw(27) << read[y].getname();
		if(read[y].getstaffid() <= 99999999999 && read[y].getstaffid() > 9999999999 )
			outdata << "| 0" << left << setw(13) << read[y].getstaffid();
		else if(read[y].getstaffid() <= 9999999999 &&read[y]. getstaffid() > 999999999)
			outdata << "| 00" << left << setw(12) << read[y].getstaffid();
		else if(read[y].getstaffid() <= 999999999 && read[y].getstaffid() > 99999999)
			outdata << "| 000" << left << setw(11) << read[y].getstaffid();
		else
			outdata << "| " << left << setw(14) << read[y].getstaffid();
		outdata << "|  " << left << setw(5) << read[y].getage();
		if (read[y].getgender() == "FEMALE" || read[y].getgender() == "F")
			outdata << left << setw(11) << "|  Female";
		else if (read[y].getgender() == "MALE" || read[y].getgender() == "M")
			outdata << left << setw(11) << "|  Male";
		else;
		outdata << "|  " << setw(5) << read[y].getyear() << left << setw(2) <<"-" ;
		if(read[y].getmonth() <10) outdata << "0" << left << setw(2) << read[y].getmonth();
		else outdata << left << setw(3) << read[y].getmonth() ;
		outdata << left << setw(2) << "-" ;
		if ( read[y].getday() < 10) outdata << "0" << left << setw(4) << read[y].getday();
		else outdata << left << setw(5) << read[y].getday();
		outdata << fixed << showpoint;
		outdata << "|   " << left << setw(11) << setprecision(2) << read[y].getWeight();
		outdata << "|   " << left << setw(10) << setprecision(2) << read[y].getHeight();
		outdata << "|  " << left << setw(7) << setprecision(2) << read[y].getbmi();
		outdata << "| " << left << setw(9) << setprecision(2) << read[y].getbmr();
		outdata << "| " << left << setw(8) << setprecision(2) << read[y].getrmr() << "||" << endl;
	}
		outdata << "\t_________________________________________________________________________________________________________________________________________________" << endl << "\t\t\t\t\t";
}		// End outfile function
