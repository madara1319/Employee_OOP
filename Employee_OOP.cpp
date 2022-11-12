#include <iostream>
#include <string.h>
#include <cstring>
#include <typeinfo>

using std::string;

string c_strConverter(string &x)
{	
int n = x.length();
char char_array[n+1];

strcpy(char_array,x.c_str());
return char_array;
}

void numberInString_checker(string &x)
{
while (true)
{
for(int i = 0; i < x.length(); i++)
{
	if(isdigit(c_strConverter(x)[i]))
	{
		std::cout<<"Theres a number in this string"<<std::endl;
	break;
	}
	else
		std::cout<<"Theres no number in this string"<<std::endl;
	continue;
}
break;
}

}


class Employee {
//private is by default in C++ so it is not needed
	private:
		string Name;
		string Company;
		int Age;


	public:

//Setting Setters & getters for private parameters
		void setName(string name)
		{
			Name=name;
			numberInString_checker(name);
				
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


		void IntroduceYourself()
		{
			std::cout<< "Name - " << Name << std::endl;
			std::cout<< "Company- " << Company << std::endl;
			std::cout<< "Age - " << Age << std::endl;
			
		}
//Creating a constructor, it does need to specify return type (like void) in front of, but it is a method just like IntroduceYourself, it needs to be named after class above it
		Employee(string name, string company, int age)
		{
			Name=name;
			Company=company;
			Age=age;
		}
//Creating your default constructor makes you lose your default constructor 
};

int main()

{
	Employee employee1=Employee("Mateusz","NA-Eng",26);
	employee1.IntroduceYourself();
	Employee employee2=Employee("Szymon","Intel",26);
//	employee2.IntroduceYourself();
	employee1.setAge(15);
	employee1.setName("Jacek1");
	std::cout<<"Siema";
//	std::cout<<employee1.getName()<<" is " <<employee1.getAge()<< " years old"<<std::endl;

}



