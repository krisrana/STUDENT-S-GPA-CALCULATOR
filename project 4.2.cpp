/*
     Name:      Krishna rana
     Course:    CIS 160 ME1
     Date:      04/19/2016
     Program:   STUDENT'S GPA CALCULATOR
     Description:  This program will calculate students GPA for the semester. It will let the user input name,
	 				id, number of course's taken for the semester, number of credits received and the grade
					achevied for the course and output the totalcredits and GPA accumalated for the
					for the semester.
*/

#include <iostream>//Standard Input/output streams libary
#include <iomanip>// Header providing parametric manipulators
#include <cctype>//character heading functions


using namespace std;
// Function prototype
void getinput(string&,int&,int&);
int getinfo(int&,int&);
float calculate(int&,int&);
void print(string&,int&,int&,float);

//Main() Function Defination
//This function runs the whole program with step by step intruction written below.
//main() has declaration of string, int, float and char type of value.
//main() has calls and parameters of other function in the program.
int main()
{	//Declarlation/ Definations
	string name;
	int id,numofcourse,totalcredits,gradepoints;
	float gpa;
	char response;
	//heading for introduction of the program and
	//notes for user to read before proceeding
	cout<<"\t\t\t\t STUDENT'S GPA CALCULATOR\n";
	cout<<"\t\t\t__________________________________________\n\n";
	cout<<"\t\t\t****Enter all the required information****";
	cout<<"\n\t\t\t****PLEASE READ THE NOTES BEFORE INPUT****\n\n\n";
	cout<<"Do you have Student information to calculate GPA?";
	cout<<"\n(Type 'Y'for yes, If you have student information or type 'N' for no to exit): ";
	cin>>response;
	//toupper function is used to make the input capital.
	response = toupper(response);
	//a loop to keep the function calls within while loop go forever
	//unless and untill the keyword 'N' or 'n' is entered to terminate the loop
	while(response!='N')
	{
		//Function Calls
		getinput(name,id,numofcourse);
		gradepoints = getinfo(totalcredits,numofcourse);
		gpa = calculate(gradepoints,totalcredits);
		print(name,id,totalcredits,gpa);
		cout<<"_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-";
		// response prompt from user to continue or terminate the program
		cout<<"\n\nDo you have another student information to enter?";
		cout<<"\n(Type 'Y'for yes, If you have student information or type 'N' for no to exit): ";
		cin>>response;
		response = toupper(response);

	}

	return 0;
}

//getinput() Function Defination
//This function is used to get input from the user.
//The input consist of Name, ID number, and number of course taken over the semester.
//It's return type is null, but it passes the value of Name, ID, and # of course via reference.
void getinput(string& name,int& id,int& numofcourse)
{
	//Local Definations/ Declarlations
	//Input Section to get name, ID and numofcourse taken.
	//cin.ignore() is used to clear buffer before using getline().
	cin.ignore();
	//Get's student name
	cout<<"\nEnter Student's Name:";getline(cin,name);
	//Get's ID of student
	cout<<"Enter Student ID number\n(Enter ID number in the range of '0 - 9999'): "; cin>>id;
		//While loop for input validation.
		while((id<0)||(id>9999))
		{
			cout<<"ERROR: Enter ID number in the range of '0 - 9999'): "; cin>>id;
		}
	//Get's the course taken
	cout<<"Enter Number of course's taken for the semester";
	cout<<"\n(Enter course taken in the range '0 - 5'):"; cin>>numofcourse;
		//while loop for input validation
		while((numofcourse<0)||(numofcourse>5))
		{
			cout<<"ERROR: Enter course taken in the range '0 - 5'): "; cin>>numofcourse;
		}
}

//getinfo() Function Defination
//This function is used to get information from user about the name of course,
//number of credits and grade recevied.
//This function return type is int, it return the calculated gradepoints to main for further use.
int getinfo(int& totalcredits,int& numofcourse)
{
	//Local Definations/ Declarlations
	//Input Section to get info about the cousre's, credits and grade..
	//constant's are defined for use in the function for calculation.
	//constant defining the worth of the grade's in integer.
	const int A = 4,
			  B = 3,
			  C = 2,
			  D = 1,
			  F = 0;

	string coursenumber;
	int credits, gradepoints;
	char grade;
	//initializatoin
	totalcredits = 0;
	gradepoints = 0;
	//for loop is used to keep the loop going untill the condition is equivallent to the num of course's taken
	//from getinput(). numofcourse is passed by reference.
	//for loop has initialization, condition and update value.
	for(int i = 1; i <=numofcourse; i++)
	{
		//Get's course name from the user.
		cout<<"\nEnter the Course number #"<<i<<": "; cin>>coursenumber;
		//Get's the # of credits recevied from the course
		cout<<"Enter the Course credit: "; cin>>credits;
		//keep's the total of credit, entered for each course number
		totalcredits += credits;
		//Get's the grade recevied for the course.
		cout<<"Enter the Grade recevied for the course\n(Grade should be A, B, C, D, or F.): "; cin>>grade;
			//toupper() is used to capitalize the charecter.
			grade = toupper(grade);
			//while loop is used to create a input validation from user
			//while loop will only accept input A,B,C,D or F and any other input will be considered an error.
			while ((grade!='A')&&(grade!='B')&&(grade!='C')&&(grade!='D')&&(grade!='F'))
			{
				cout<<"ERROR:Grade should be A, B, C, D, or F.): "; cin>>grade;
				grade = toupper(grade);
			}
		// switch() is used to create case's for eace grade
		// This switch has condition to calculate for a specific input from user
		// It give the total gradepoints achevied from the semeter.
		switch(grade)
		{
			case 'A':gradepoints += (credits * A);
				break;
			case 'B':gradepoints += (credits * B);
				break;
			case 'C':gradepoints += (credits * C);
				break;
			case 'D':gradepoints += (credits * D);
				break;
			case 'F':gradepoints += (credits * F);
				break;
		}
	}
	//return's integer gradepoints to main for further use.
	return gradepoints;
}

//Calculate() function Defination
//This function has a return type of float gpa which is stored in main
//This function calculate gpa for output with gradepoints from getinfo()
//and totalcredits from getinfo() as well.
float calculate(int& gradepoints, int& totalcredits)
{
	//Local Definations/ Declarlations
	float gpa;
	gpa = gradepoints / ((float)totalcredits);
	//return's float gpa to main for further use
	return gpa;
}

//Print() function Defination
//This function is the output section of the program
//It output's the Name, ID, totalcredits and GPA for the semeter.
//Name, ID and totalcredits are passed by reference.
//it's return type is null.
void print (string& name, int& id, int& totalcredits, float gpa)
{
	//Local Definations/ Declarlations
	//output heading for the program
	//setprecision(2) prints answers in 2 decimal spaces.
	cout << fixed << showpoint << setprecision(2);
	cout<<"\n\n\t  STUDENT'S GPA CALCULATOR\n";
	cout<<"___________________________________________________\n\n";
	cout<<"\t  Student: "<<name<<"'s GPA Report\n"<<endl;
	cout<<"___________________________________________________\n";
	cout<<"ID number\tTotal # of credits\t  GPA"<<endl;
	cout<<setw (5)<<id<<setw (20)<<totalcredits<<setw (20)<<gpa<<endl;
	cout<<"_-_-_-_-_-_-_-_****REMARKS****_-_-_-_-_-_-_-_-_"<<endl;
	// if else if is used to print out remarks based the the GPA.
		//if GPA is less than 2.0 it will print Warning remark.
		if (gpa<2.0)
			{
				cout<<"  Warning, Your GPA is Low";
			}
			//If GPA is 3.0 or above it will print an congratulation remark.
			else if (gpa>=3.0)
			{
				cout<<"  Congratulation!!, keep up the smart work";
			}
	//footing of the program
	cout<<"\n\nThank you for using Student's GPA calculator\n"<<endl;
}
