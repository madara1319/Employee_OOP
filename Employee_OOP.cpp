#include <iostream>

using std::string;

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
		};
		string getName()
		{
			return Name;
		}
		void setCompany(string company)
		{
			Company=company;
		};
		string getCompany()
		{
			return Company;
		}
		void setAge(int age)
		{
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
	employee2.IntroduceYourself();
	employee1.setAge(39);
	std::cout<<employee1.getName()<<" is " <<employee1.getAge()<< " years old"<<std::endl;

}



