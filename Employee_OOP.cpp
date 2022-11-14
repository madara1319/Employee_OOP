#include <iostream>
#include <string.h>
#include <cstring>
#include <typeinfo>

using std::string;
//____________________________________________________________________________________
string c_strConverter(string &x)
{
//additional function for converting string into char array so its easier to find number 
int n = x.length();
char char_array[n+1];

strcpy(char_array,x.c_str());
return char_array;
}
//____________________________________________________________________________________

bool numberInString_checker(string &x)
{
	int a {};
	for(int i = 0; i < x.length(); i++)
	{
		if(isdigit(c_strConverter(x)[i]))
		{
//If theres a number in string return 0		
			a=0;
		break;
		

		}
		else
		{
//If theres no number in string return 1
			a=1;
		continue;
		}
	}
return a;
};
//____________________________________________________________________________________
//Below class is an Implementation of Abstraction
//classes can inherit from this abstract class 
//they have to sign contract defined within so provide implementation
//for virtual class (here AskForPromotion)
class AbstractEmployee
{
	virtual void AskForPromotion()=0;
};


class Employee:AbstractEmployee {
//private is by default in C++ so it is not needed
	private:
//These are private to get to them you need to go through methods
//This is basically the concept of encapsulation
		string Company;
		int Age;
	protected:
		string Name;

//____________________________________________________________________________________

	public:

//Setting Setters & getters for private parameters
		void setName(string name)
		{
			if (numberInString_checker(name)==1)
				Name=name;
				
		};
		string getName()
		{
			return Name;
		};
		void setCompany(string company)
		{
			Company=company;
		};
		string getCompany()
		{
			return Company;
		};
		void setAge(int age)
		{
			if (age>=18)
			Age=age;
		};
		int getAge()
		{
			return Age;
		};

//____________________________________________________________________________________

		void IntroduceYourself()
		{
			std::cout<< "Name - " << Name << std::endl;
			std::cout<< "Company- " << Company << std::endl;
			std::cout<< "Age - " << Age << std::endl;
			
		};
//____________________________________________________________________________________

//Creating a constructor, it does need to specify return type (like void) in front of, but it is a method just like IntroduceYourself, it needs to be named after class above it
		Employee(string name, string company, int age)
		{
			Name=name;
			Company=company;
			Age=age;
		};
//____________________________________________________________________________________

		void AskForPromotion()
		{
			if(Age>30)
				std::cout<<Name<<" got promoted!" << std::endl;
			else
				std::cout<<Name<<", sorry NO promotion for you!"<<std::endl;
		};

//Virtual here means that if theres a diff definition in derived classes it will use them
//if theres not it will use this 
		virtual	void Work()
		{
			std::cout<<Name<<" is checking email, task backlog, performing tasks..."<<std::endl;
		}
};
//____________________________________________________________________________________

//Creating your default constructor makes you lose your default constructor 
//Inheritance -> new class Developer inherits from class Employee
//Class made to be public to access method AskForPromotion
class Developer:public Employee
{
public:
		string FavProgrammingLang;
		Developer(string name, string company, int age, string favprogramminglang )
			:Employee(name,company,age)
		{
			FavProgrammingLang=favprogramminglang;
		};
		void FixBug()
		{
//If Name was private not protected you would have to use public getters setters
//to get into it
//			std::cout<<getName()<<" fixed bug using "<<FavProgrammingLang<<std::endl;
			std::cout<<Name<<" fixed bug using "<<FavProgrammingLang<<std::endl;
	
		};
//____________________________________________________________________________________

		void Work()
		{
			std::cout<<Name<<" is writing "<<FavProgrammingLang <<" code"<<std::endl;
		}

};

//____________________________________________________________________________________

class Teacher:public Employee
{
public:
	string Subject;
	void PrepareLesson()
	{
		std::cout<<Name<<" is preparing " <<Subject<<" lesson"<<std::endl;
	};
	Teacher(string name, string company, int age,string subject)
	:Employee(name, company,age)
	{
		Subject=subject;
	};
	void Work()
	{
		std::cout<<Name<<" is teaching "<<Subject<<std::endl;
	}

};

//____________________________________________________________________________________


int main()

{
	Employee employee1=Employee("Mateusz","NA-Eng",26);
//	employee1.IntroduceYourself();
	Employee employee2=Employee("Szymon","Intel",26);
//	employee2.IntroduceYourself();
//____________________________________________________________________________________
//
	employee1.setAge(39);
//	employee1.setName("Jacek");
//	employee2.setName("2Pawel");
//	std::cout<<employee2.getName()<<" is " <<employee2.getAge()<< " years old"<<std::endl;
//	std::cout<<employee1.getName()<<" is " <<employee1.getAge()<< " years old"<<std::endl;
//____________________________________________________________________________________
//
//	string imie="Jacek";
//	std::cout<< numberInString_checker(imie);
//____________________________________________________________________________________
	employee1.AskForPromotion();
	employee2.AskForPromotion();
	Developer d=Developer("Maciek","YT",19,"C++");
	d.FixBug();
	d.AskForPromotion();
	Teacher t=Teacher("Ania","Cool Schoold",35,"History");
	t.PrepareLesson();
	t.AskForPromotion();
	employee1.Work();
//____________________________________________________________________________________
//	d.Work();
//	t.Work();
//	Pointer of base class has a reference to derive object this is 
//	a concept of polymorphism
	Employee* e1=&d;
	Employee* e2=&t;

	e1->Work();
	e2->Work();


}



