#include <iostream>

using std::string;

class Employee {
	public:
		string Name;
		string Company;
		int Age;

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
	employee2.IntroduceYourself();

}



